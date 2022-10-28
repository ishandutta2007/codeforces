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
	int n, m;
	cin>>n>>m;
	vector<int>vec;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		vec.pb(x);
	}
	vector<int>v;
	sort(vec.begin(), vec.end());
	for(int i=1; i<n; i++){
		v.pb(vec[i]-vec[i-1]);
	}
	int gc=0;
	for(auto u:v){
		gc=__gcd(gc, u);
	}
	for(int i=0; i<m; i++){
		int x;
		cin>>x;
		cout<<__gcd(vec[0]+x, gc)<<" ";
	}
	
	return 0;
}