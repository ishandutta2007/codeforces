#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		if(n==1 && arr[0]==k){
			cout<<"yes"<<endl;
			continue;
		}
		bool booly=false;
		for(int i=0; i<n; i++){
			if(arr[i]==k){
				booly=true;
			}
		}
		if(!booly){
			cout<<"no"<<endl;
			continue;
		}
		bool b2=false;
		for(int i=0; i<n-1; i++){
			if(arr[i]>=k && arr[i+1]>=k){
				b2=true;
			}
		}
		for(int i=0; i<n-2; i++){
			if(arr[i]>=k && arr[i+2]>=k){
				b2=true;
			}
		}
		if(b2){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}