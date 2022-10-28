#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;

vector<vector<int>>cr;
vector<vector<int>>cc;
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<vector<int>>vec;
	vec.resize(n);
	for(int i=0; i<n; i++){
		vec[i].resize(m);
	}
	cr.resize(N);
	cc.resize(N);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>vec[i][j];
			cr[vec[i][j]].pb(i);
			cc[vec[i][j]].pb(j);
		}
	}
	int ans=0;
	for(int i=0; i<N; i++){
		sort(cr[i].begin(), cr[i].end());
		sort(cc[i].begin(), cc[i].end());
		int sr=0;
		for(auto u:cr[i]){
			sr+=u;
		}
		int sc=0;
		for(auto u:cc[i]){
			sc+=u;
		}
		int sz=cr[i].size();
		int s1=0;
		for(int j=0; j<sz; j++){
			ans+=((j*cr[i][j]-s1)+(sr-cr[i][j]-s1-(cr[i][j]*(sz-j-1))));
			s1+=cr[i][j];
		}
		int s2=0;
		for(int j=0; j<sz; j++){
			ans+=((j*cc[i][j]-s2)+(sc-cc[i][j]-s2-(cc[i][j]*(sz-j-1))));
			s2+=cc[i][j];
		}
	}
	cout<<ans/2<<endl;
	
	return 0;
}