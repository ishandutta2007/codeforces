#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int ans,n,m,k,cnt,pos[300000],tot,id[10][10];
vector<pair<int,int> > v[300000],rev[300000];
pair<int,int> q[300000];
map<int,int> vis;

inline void dfs(int x,int mask)
{
	if(x>=tot/2ll){
		for(int i=1;i<=cnt;i++){
			int val=__builtin_popcountll(mask&q[i].first);
			if(val>1) return;
			if(x>q[i].second&&val==0) return;
		}
	}
	if(x==tot+1){
		ans++;return;
	}
	dfs(x+1ll,mask);
	dfs(x+1ll,mask+(1ll<<(x-1ll)));
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,c;cin>>x>>y>>c;
		v[x].push_back(make_pair(c,y));
		rev[y].push_back(make_pair(c,x));
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++) pos[v[i][j].first]=j+1;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			tot++;
			id[i][j]=tot;
		}
	}
	for(int i=1;i<=k;i++){
		cnt++;
		for(int j=1;j<=i;j++) q[cnt].first|=(1ll<<(id[i][j]-1ll)),q[cnt].second=max(q[cnt].second,id[i][j]);
		vis[q[cnt].first]=1;
	}
	for(int i=1;i<=n;i++){
		if(rev[i].size()==0){
			cout<<0<<endl;
			return 0;
		}
		cnt++;
		for(int j=0;j<rev[i].size();j++){
			int now=id[v[rev[i][j].second].size()][pos[rev[i][j].first]];
			q[cnt].first|=(1ll<<(now-1ll));
			q[cnt].second=max(q[cnt].second,now);
		}
		if(vis[q[cnt].first]){
			q[cnt].first=0;q[cnt].second=0;
			cnt--;
		}
		else{
			vis[q[cnt].first]=1;
		}
	}
	sort(q+1,q+cnt+1);
	reverse(q+1,q+cnt+1);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}