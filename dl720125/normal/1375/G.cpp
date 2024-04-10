#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,dep[200010];
vector<int> v[200010]; 

inline void dfs(int x,int pr)
{
	for(int i=0;i<v[x].size();i++) if(v[x][i]!=pr){
		dep[v[x][i]]=dep[x]+1;
		dfs(v[x][i],x);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,-1);
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		if(dep[i]%2==0) cnt0++;
		else cnt1++;
	}
	cout<<min(cnt0,cnt1)-1<<endl;
	return 0;
}