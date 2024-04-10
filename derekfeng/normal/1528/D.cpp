#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
vector<pii>g[606];
ll dis[606],nxt[1206];
bool del[606];
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
	}
	for(int t=0;t<n;t++){
		memset(del,0,sizeof(del));
		memset(dis,63,sizeof(dis));
		dis[t]=0;
		for(;;){
			int pos=-1;
			for(int i=0;i<n;i++)if(!del[i]&&(pos<0||dis[pos]>dis[i]))pos=i;
			if(pos==-1)break;
			del[pos]=1;
			memset(nxt,63,sizeof(nxt));
			ll W=dis[pos];
			for(auto [v,c]:g[pos]){
				int y=(W+v)%n;
				nxt[y]=nxt[y+n]=min(W+c,nxt[y]);
			}
			for(int i=1;i<n+n;i++)nxt[i]=min(nxt[i],nxt[i-1]+1);
			for(int i=0;i<n;i++)dis[i]=min(dis[i],min(nxt[i],nxt[i+n]));
		}
		for(int i=0;i<n;i++)printf("%lld ",dis[i]);puts("");
	}
}