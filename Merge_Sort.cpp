#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge (vector <int> &a,int start,int mid, int end){  //pass by reference
    
    int n1 = mid -start + 1;
    int n2 = end - mid;
  
    int L1[n1], L2[n2];
  
 for (int i = 0; i < n1; i++)
        L1[i] = a[start + i];
 for (int j = 0; j < n2; j++)
        L2[j] = a[mid + 1+ j];
        
int i=0,j=0,index = start;

    while(i<n1 && j<n2){
    if(L1[i] <= L2[j]){
        a[index] = L1[i] ;
        i++;
        
    }
    else {
        a[index] = L2[j];
         j++;
         
    }
    index++;
    }
    
        while(j<n2){
            a[index] = L2[j];
            index++; 
            j++;
        }
    
    
        while(i<n1){
            a[index] = L1[i];
            index++; 
            i++;
        }
    
    
}

void mergeSort (vector <int> &a,int start, int end){ //pass by reference
    if(start == end)
      return;
      
    if(start < end){  
    int mid =  (start + end)/2;
  
    mergeSort (a,start,mid);
    mergeSort (a,mid+1,end);
    
    merge(a,start,mid,end);
 
    }
    
}
int main() {
	vector <int> a;
	int n;
	cin >> n; // Size of array to be sorted
	for(int i=0;i<n;i++){
	int elem;         
	cin>> elem;
	a.push_back(elem);
	}
	int start = 0,end = a.size() - 1;
	
	mergeSort(a,start,end);
	for(int i=0; i<a.size(); i++){
	    cout<< a[i] <<" ";
	}
	return 0;
}
