#include<bits/stdc++.h>
#define MP(x,y) make_pair(x,y)
using namespace std;
const int maxn = 3e3+100;
const int maxq = 4e5+100;
vector<int> E[maxn];
int ans[maxq];
vector<int> G[maxn];
vector<pair<pair<int,int>,int> >Q[maxn];
int m,n,q;
int st[maxn][13];
bool vis[maxn];
void dfs(int node){
	if (vis[node])return;
	vis[node] = true;
	for (int v :G[node])dfs(v);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i=1;i<=q;i++){
		int s,t,k;
		scanf("%d%d%d",&s,&t,&k);
		Q[t].push_back(MP(MP(s,k),i));
	}
	for (int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end());
	}
	for (int t=1;t<=n;t++){
		if (Q[t].size()){
			memset(vis,0,sizeof vis);
			dfs(t);
			memset(st,0,sizeof st);
			st[n+1][0]=n+1;
			for (int i=1;i<=n;i++){
				if (i==t)st[t][0]=n+1;
				else if (vis[i]){
					for (int v:E[i]){
						if (!vis[v])continue;
						st[i][0]=v;
						break;
					}
				}
			}
			for (int i=1;i<=12;i++){
				for (int j=1;j<=n+1;j++){
					st[j][i] = st[st[j][i-1]][i-1];
				}
			}
			for (auto temp:Q[t]){
				int s = temp.first.first;
				int k = temp.first.second-1;
				int id = temp.second;
				if (st[s][12]==n+1){
					for (int i=0;i<=12;i++){
						if (k&(1<<i))s = st[s][i];
					}
					if (s!=n+1){
						ans[id] =s;
					}else{
						ans[id]=-1;
					}
				}else{
//					cout<<-100<<endl;
					ans[id]=-1;
				}
			}
		}
	}
	for (int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}