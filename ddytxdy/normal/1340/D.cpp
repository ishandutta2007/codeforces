#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e5+50;
int n,mx,f[N];
vector<int>v[N];
vector<pii>ans;
void dfs(int x,int d){
	v[x].erase(find(v[x].begin(),v[x].end(),f[x]));
	int now=d+1;ans.pb(mp(x,now));
	for(int i=0,y;i<v[x].size();i++){
		if(now==mx){now=d-(v[x].size()-i);ans.pb(mp(x,now));}
		f[y=v[x][i]]=x,dfs(y,now),ans.pb(mp(x,++now));
	}
	if(now!=d)ans.pb(mp(x,d));
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].pb(y),v[y].pb(x);
	}
	for(int i=1;i<=n;i++)
		mx=max(mx,(int)v[i].size());
	ans.pb(mp(1,0));
	for(int i=0,y,now=0;i<v[1].size();i++)
		f[y=v[1][i]]=1,dfs(y,now),ans.pb(mp(1,++now));
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}