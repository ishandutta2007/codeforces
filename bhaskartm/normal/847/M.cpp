#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int diff=arr[1]-arr[0];
	bool che=1;
	for(int i=0; i<n-1; i++){
		if(arr[i+1]-arr[i]!=diff){
			che=0;
		}
	}
	if(che){
		cout<<arr[n-1]+diff;
		return 0;
	}
	else{
		cout<<arr[n-1];
	}
	return 0;
}