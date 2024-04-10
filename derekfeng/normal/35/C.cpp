#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,K,f[2004][2004],mx;
queue<pii>que;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	memset(f,-1,sizeof(f));
	scanf("%d",&K);
	while(K--){
		int u,v;scanf("%d%d",&u,&v);
		f[u][v]=0,que.push({u,v});
	}
	while(!que.empty()){
		auto[u,v]=que.front();que.pop(),mx=max(mx,f[u][v]);
		for(int i=0;i<4;i++){
			int uu=u+d[i][0],vv=v+d[i][1];
			if(uu>0&&uu<=n&&vv>0&&vv<=m&&!~f[uu][vv])
				f[uu][vv]=f[u][v]+1,que.push({uu,vv});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(f[i][j]==mx){
		printf("%d %d",i,j);return 0;
	}
}