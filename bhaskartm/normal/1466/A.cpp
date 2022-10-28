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
		set<int>se;
		for(int i=0; i<n; i++){
			for(int j=0; j<i; j++){
				se.insert(arr[i]-arr[j]);
			}
		}
		cout<<se.size()<<endl;
	}
	return 0;
}