#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		for(int i=0; i<n; i++){
			arr[i]=-arr[i];
		}
		int index=0;
		for(int i=0; i<n-1; i++){
			if(i==n-2 && arr[i]>arr[i+1]){
				
				sort(arr+index, arr+n);
				continue;
			}
			if(arr[i]<arr[i+1]){
				sort(arr+index, arr+i+1);
				
				index=i+1;
			}
			
		}
		
		bool booly=true;
		for(int i=0; i<n; i++){
			if(arr[i]!=(-(n-i))){
				booly=false;
			}
		}
		if(booly){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}