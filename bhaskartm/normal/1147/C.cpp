#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int mini=100;
	int cnt=0;
	for(int i=0; i<n; i++){
		if(arr[i]==mini){
			cnt++;
		}
		if(arr[i]<mini){
			mini=arr[i];
			cnt=1;
		}
	}
	if(cnt<=(n/2)){
		cout<<"Alice";
	}
	else{
		cout<<"Bob";
	}
	return 0;
}