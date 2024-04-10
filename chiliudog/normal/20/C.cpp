#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
ll n,m,x,y,z,s,t,vis[100010];
int que[12000010];
ll dis[100010];
ll path[100010];
vector<pll> edge[100010];
ll st[100010],top;
int main(){
	scanf("%I64d%I64d",&n,&m);
//	memset(dis,127,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i]=1e18;
//	cout<<dis[1];
	for(int i=1;i<=m;i++){
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		edge[x].pb(mk(y,z));
		edge[y].pb(mk(x,z));
	}
//	for(int i)
	que[++t]=1;
	vis[1]=1;
	dis[1]=0;
	while(s<t){
		int u=que[++s];
		vis[u]=0;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].fi;
			int c=edge[u][i].se;
			if(dis[v]>dis[u]+c){
				dis[v]=dis[u]+c;
				path[v]=u;
				if(!vis[v]) que[++t]=v;
			}
		}
	}
	if(dis[n]>=1e18) puts("-1"); 
	else{
		ll fr=path[n];
		while(fr){
			st[++top]=fr;
			fr=path[fr];
		}
		while(top) printf("%I64d ",st[top--]);
		printf("%I64d ",n);
//		puts("step 1");
	}
	
	return 0;
}