#include<bits/stdc++.h>
using namespace std;
int t,n;
bool ok[105][105][105];
char s[105];
int dis[105][105],fa[105];
vector<int>g[105],v;
bool used[105],vis[105];
void bfs(int s){
	queue<int>q;q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto y:g[x]){
			if(y==s||dis[s][y])continue;
			dis[s][y]=dis[s][x]+1,q.push(y);
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(ok,0,sizeof(ok));
		scanf("%d",&n);
		for(int i=1;i<n;i++)for(int j=1;j<=n-i;j++){
			scanf("%s",s+1);
			for(int k=1;k<=n;k++)
				ok[k][i][i+j]=ok[k][i+j][i]=(s[k]=='1');
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ok[i][j][j]=1;
		bool YES=0;
		memset(vis,0,sizeof(vis));
		for(int t=2;t<=n;t++)if(!vis[t]){
			int cnt=1;memset(used,0,sizeof(used));
			v.clear();
			for(int i=2;i<=n;i++)if(ok[1][t][i]){
				v.push_back(i),cnt++;
				used[i]=1,fa[i]=1,vis[i]=1;
			}
			while(cnt<n){
				vector<int>nv;
				for(int i=2;i<=n;i++)if(!used[i])
					for(auto x:v)if(ok[x][i][fa[x]]){
						nv.push_back(i),cnt++;
						used[i]=1,fa[i]=x;break;
					}
				if(nv.empty())break;
				swap(v,nv);
			}
			if(cnt<n)continue;
			memset(dis,0,sizeof(dis));
			for(int i=1;i<=n;i++)g[i].clear();
			for(int i=2;i<=n;i++)g[fa[i]].push_back(i),g[i].push_back(fa[i]);
			for(int i=1;i<=n;i++)bfs(i);
			bool OK=1;
			for(int i=1;i<=n&&OK;i++)for(int j=i+1;j<=n&&OK;j++)
				for(int k=1;k<=n&&OK;k++)
					OK&=(ok[k][i][j])^(dis[i][k]!=dis[j][k]);
			if(OK){
				puts("Yes"),YES=1;
				for(int i=2;i<=n;i++)printf("%d %d\n",i,fa[i]);
				break;
			}
		}
		if(!YES)puts("No");
	}
}