#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
using namespace __gnu_pbds;
using namespace std;

int n,p[1510],ver[1510],edge[1510];
vector<int> v[1510];
vector<pair<int,pair<int,int> > > e;

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

inline void unite(int x,int y)
{
	int rootx=find_set(x),rooty=find_set(y);
	if(rootx==rooty){
		edge[rootx]++;
		if(ver[rootx]*(ver[rootx]-1)/2==edge[rootx]) v[rootx][0]++;
		return;
	}
	p[rooty]=rootx;
	ver[rootx]+=ver[rooty];
	edge[rootx]+=edge[rooty];
	edge[rootx]++;
	vector<int> nw;nw.resize(v[rootx].size()+v[rooty].size(),0);
	for(int i=0;i<v[rootx].size();i++){
		for(int j=0;j<v[rooty].size();j++){
			add(nw[i+j+1],1ll*v[rootx][i]*v[rooty][j]%MOD);
		}
	}
	v[rootx]=nw;
	if(ver[rootx]*(ver[rootx]-1)/2==edge[rootx]) v[rootx][0]++;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			if(i<j){
				e.push_back(make_pair(x,make_pair(i,j)));
			}
		}
	}
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++){
		p[i]=i;ver[i]=1;edge[i]=0;
		v[i].push_back(1);
	}
	for(int i=0;i<e.size();i++){
		int x=e[i].second.first,y=e[i].second.second;
		unite(x,y);
	}
	int root=find_set(1);
	for(int i=0;i<v[root].size();i++) cout<<v[root][i]<<" ";
	cout<<endl;
	return 0;
}