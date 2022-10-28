#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second

main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	pair<int, int>b[n];
	for(int i=0; i<n; i++){
		b[i].f=arr[i];
		b[i].s=i;
	}
	sort(b, b+n);
	vector<int>v;
	for(int i=0; i<n; i++){
		v.pb(b[i].f);
	}
	
	vector<int>v2;
	v2.pb(v[n-1]);
	for(int i=0; i<n-1; i++){
		v2.pb(v[i]);
	}
	int ans[n];
	for(int i=0; i<n; i++){
		ans[b[i].s]=v2[i];
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}