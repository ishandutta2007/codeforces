#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long 
using namespace __gnu_pbds;
using namespace std;

int m,n,a[100010],b[100010],p[200010];
vector<pair<int,pair<int,int> > > e;

inline int find_set(int x)
{
	return p[x]==x?x:p[x]=find_set(p[x]);
}

inline bool unite(int x,int y)
{
	int rootx=find_set(x),rooty=find_set(y);
	if(rootx==rooty) return false;
	p[rooty]=rootx;
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int tot=0;
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			int y;cin>>y;
			e.push_back(make_pair(a[i]+b[y],make_pair(i,m+y)));
			tot+=a[i]+b[y];
		}
	}
	sort(e.begin(),e.end());reverse(e.begin(),e.end());
	int ans=0;
	for(int i=1;i<=m+n;i++) p[i]=i;
	for(int i=0;i<e.size();i++){
		int x=e[i].second.first,y=e[i].second.second;
		if(unite(x,y)){
			ans+=e[i].first;
		}
	}
	cout<<tot-ans<<endl;
	return 0;
}