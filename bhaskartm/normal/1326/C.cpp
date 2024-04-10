#include <bits/stdc++.h>
using namespace std;
#define int long long int
int N=998244353;
main() {
	
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int sum=0;
	for(int i=0; i<k; i++){
		sum+=(n-i);
	}
	cout<<sum<<" ";
	vector<int>v;
	for(int i=0; i<n; i++){
		if(arr[i]>n-k){
			v.push_back(i);
		}
	}
	int ans=1;
	for(int i=0; i<v.size()-1; i++){
		ans=(ans*(v[i+1]-v[i]))%N;
	}
	cout<<ans;
	return 0;
}