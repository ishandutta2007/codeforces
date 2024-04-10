#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:0; }
struct Graph{
	struct Edge{ int to,nxt; };
	vector<int> head;
	vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1);
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y){
		edge.push_back((Edge){y,head[x]});
		head[x]=edge.size()-1;
	}
}G;
int dis[505][505],ans[505][505],n;
bitset<505> g[505][505];
void init(int x,int dis[],bitset<505> g[]){
	for(int i=1;i<=n;++i) dis[i]=(int)1e9;
	queue<int> q; dis[x]=0; q.push(x);
	while(!q.empty()){
		int x=q.front(); g[x][x]=1; q.pop(); 
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(dis[x]+1<dis[y]){
				dis[y]=dis[x]+1; g[y]=g[x]; 
				q.push(y);
			}
		}
	}
}
int main(){
	int m; scanf("%d%d",&n,&m);
	G=Graph(n,m+m);
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	for(int i=1;i<=n;++i) init(i,dis[i],g[i]);
/*	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			printf("[%d %d %d]",i,j,dis[i][j]);
		puts("");
	}
*/	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
			int key=1;
			for(int x=1;x<=n;++x)
				if(!g[i][j][x]){
					int cnt=0;
					for(int jj=G.head[x];~jj;jj=G.edge[jj].nxt){
						int y=G.edge[jj].to;
						if(dis[i][y]<dis[i][x]&&dis[j][y]<dis[j][x])
							++cnt;
					}
					key=1ll*key*cnt%MOD;
					if(key==0) break;
				}
			ans[i][j]=ans[j][i]=key;
		}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			printf("%d ",ans[i][j]);
		puts("");
	}
}