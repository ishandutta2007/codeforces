#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define R register int
#define L long long
#define V vector<int>::iterator
#define I inline
#define N 100001
#define INF 99999999999999999
L dis[N];
int st[N],ed[N],len[N],d[N];
bool vis[N];
vector<int>G[N];
struct Node{
	int Id;
	L Dis;
	I friend bool operator<(Node A,Node B){
		return A.Dis>B.Dis;
	}
};
I void Dijkstra(){
	Node Tem;
	Tem.Dis=0;
	Tem.Id=1;
	priority_queue<Node>Q;
	Q.push(Tem);
	while(Q.empty()==false){
		int u=Q.top().Id;
		Q.pop();
		if(vis[u]==false){
			vis[u]=true;
			for(V T=G[u].begin();T!=G[u].end();T++){
				int v=ed[*T];
				if(dis[v]>dis[u]+len[*T]){
					Tem.Dis=dis[v]=dis[u]+len[*T];
					Tem.Id=v;
					Q.push(Tem);
				}
			}
		}
	}
}
vector<int>S[1000001];
I void SPFA(int&tot,int&n,int&m){
	if(tot==0){
		return;
	}
	S[0].push_back(1);
	for(R i=2;i<=n;i++){
		d[i]=9999999;
	}
	for(R i=0;i<=tot;i++){
		for(R j=0;j!=S[i].size();j++){
			int u=S[i][j];
			if(d[u]==i){
				for(V T=G[u].begin();T!=G[u].end();T++){
					int v=ed[*T];
					if(d[v]>i+len[*T]){
						d[v]=i+len[*T];
						if(d[v]<=tot){
							S[d[v]].push_back(v);
						}
					}
				}
			}
		}
		S[i].clear();
	}
	tot=0;
	for(R i=0;i!=m;i++){
		len[i]-=d[ed[i]]-d[st[i]];
	}
	for(R i=2;i<=n;i++){
		if(d[i]!=9999999){
			dis[i]+=d[i];
		}
	}
}
int main(){
	int n,m,q,type,x,y,tot=0;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i!=m;i++){
		scanf("%d%d%d",st+i,ed+i,len+i);
		G[st[i]].push_back(i);
	}
	for(R i=2;i<=n;i++){
		dis[i]=INF;
	}
	Dijkstra();
	for(R i=0;i!=m;i++){
		len[i]-=dis[ed[i]]-dis[st[i]];
	}
	for(R i=0;i!=q;i++){
		scanf("%d%d",&type,&x);
		if(type==1){
			SPFA(tot,n,m);
			if(dis[x]==INF){
				puts("-1");
			}else{
				printf("%lld\n",dis[x]);
			}
		}else{
			tot+=x; 
			for(R j=0;j!=x;j++){
				scanf("%d",&y);
				len[y-1]++;
			}
		}
	}
	return 0;
}