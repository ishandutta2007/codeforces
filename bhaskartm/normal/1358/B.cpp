#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

 main() {
	int t;
	cin>>t;
	while(t--){
		 int n;
		 cin>>n;
		 int arr[n];
		 for(int i=0; i<n; i++){
		 	cin>>arr[i];
		 }
		 sort(arr, arr+n);
		 bool booly[n];
		 for(int i=0; i<n; i++){
		 	booly[i]=false;
		 }
		 for(int i=0; i<n; i++){
		 	if(arr[i]<=i+1){
		 		booly[i]=true;
		 	}
		 }
		 int maxi=-1;
		 for(int i=0; i<n; i++){
		 	if(booly[i]){
		 		maxi=i;
		 	}
		 }
		 if(maxi==-1){
		 	cout<<1<<endl;
		 }
		 else{
		 	cout<<maxi+2<<endl;
		 }
	}
	return 0;
}