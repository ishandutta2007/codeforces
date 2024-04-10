#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int inf=314000000;
int m,n;
int a[100005],d[100005];
vector<int>t[100005],g[100005],r[100005];
int dis[100005],deg[100005],ans[100005];
priority_queue<pii,vector<pii>,greater<pii> >pq;
bool ins[100005];
bool ok[100005];
int dfs(int x){
	if(ans[x]!=-1e9)return ans[x];
	ans[x]=0,ins[x]=1;
	for(auto i:r[x])if(ok[i]){
		int tmp=d[i];
		for(auto y:t[i]){
			if(ins[y])tmp=-2;
			else{
				int val=dfs(y);
				if(val==-2)tmp=-2;
				else{
					if(tmp!=-2)
						tmp=min(tmp+val,inf);
				}
			}
		}
		if(tmp==-2){
			ans[x]=-2;
			break;
		}else ans[x]=max(ans[x],tmp);
	}
	ins[x]=0;
	return ans[x];
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]),r[a[i]].push_back(i);
		int N;scanf("%d",&N);
		while(N--){
			int x;scanf("%d",&x);
			if(x<0)d[i]++;
			else{
				deg[i]++;
				t[i].push_back(x);
				g[x].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i]=1e9;
	for(int i=1;i<=m;i++)
		if(t[i].empty()&&dis[a[i]]>d[i]){
			dis[a[i]]=d[i];
			pq.push({dis[a[i]],a[i]});
		}
	while(!pq.empty()){
		pii u=pq.top();pq.pop();
		if(u.fi>dis[u.se])continue;
		for(auto v:g[u.se]){
			deg[v]--;
			if(deg[v]==0){
				int w=d[v];
				for(auto y:t[v])
					w=min(inf,dis[y]+w);
				if(dis[a[v]]>w)
					dis[a[v]]=w,pq.push({w,a[v]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		ok[i]=1;
		for(auto x:t[i])if(dis[x]==1e9)ok[i]=0;
	}
	for(int i=1;i<=n;i++)ans[i]=-1e9;
	for(int i=1;i<=n;i++)if(dis[i]<1e9)dfs(i);
	for(int i=1;i<=n;i++){
		if(dis[i]==1e9)puts("-1 -1");
		else printf("%d %d\n",dis[i],ans[i]);
	}
}