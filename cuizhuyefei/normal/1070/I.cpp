#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define eef(i,x)for(int i=head[x],y=e[i].to;i;i=e[i].next,y=e[i].to)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
int read(){char c=getchar();int d=0,f=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());return d*f;}
char Read(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c;}
void print(int s){if(!s){putchar('0');return;}if(s<0)putchar('-'),s=-s;int t[20],n=0;while(s)t[++n]=s%10,s/=10;def(i,n,1)putchar(t[i]+'0');}
int getdigit(char c){return (c<'0'||c>'9')?-1e9:(c-'0');}
typedef pair<int,int>PII;
typedef long long LL;
const int N=1205;
int T,n,m,k,a[N][N];
int op,ed,ans[N];

const int M = 240030, inf = 0x3f3f3f3f;
int head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1,w[N][N];
void addedge1(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void addedge(int u, int v, int c){
	addedge1(u,v,c);addedge1(v,u,0);
}
int dis[N],q[N];
inline bool bfs() {
	memset(dis,inf,4*(ed+2));
	int f=0,r=1; q[f]=ed; dis[ed]=0;
	while (f!=r) {
		int u=q[f++];
		L(i,u) if (cap[i^1]&&dis[to[i]]==inf){
			q[r++]=to[i];dis[to[i]]=dis[u]+1;if(to[i]==op)return 1;
		}
	}
	return dis[op]<inf;
}
inline int dfs(int u, int flow) {
	if (u==ed||!flow)return flow;int res=0;
	for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+1){
		int tmp=dfs(to[i],min(flow,cap[i]));
		res+=tmp;flow-=tmp;cap[i]-=tmp;cap[i^1]+=tmp;if(!flow)break;
	}
	return res;
}
inline int dinic() {
	int res=0;
	while (bfs()) {
		memcpy(cur,head,4*(ed+2)); res+=dfs(op,inf);
	}
	return res;
}

void init(){
	edgenum=1;memset(head,0,sizeof(head));
}
int main(){
	T=read();
	while(T--){
		n=read();m=read(),k=read();
		memset(a,0,sizeof a);
		op=n+m+1; ed=op+1;
		init();	ref(i,0,ed)ref(j,0,ed)w[i][j]=0;
		ref(i,1,m){
			int x=read(),y=read();
			a[x][y]=a[y][x]=i;
		}
		ref(i,1,m)addedge(i,ed,1);
		int S=0;
		ref(i,1,n){
			int tot=0;
			ref(j,1,n)if(a[i][j])tot++;
			if(tot>k){
				ref(j,1,n)if(a[i][j])addedge(m+i,a[i][j],1);
				addedge(op,m+i,2*(tot-k));S+=2*(tot-k);
			}
		}
		ref(i,1,m)ans[i]=0;
		if(dinic()==S){
			int tot=0;
			rep(u,1,ed)L(i,u)w[u][to[i]]+=cap[i];
			ref(i,m+1,m+n){
				bool fg=0;
				ref(j,1,m)if(w[j][i]){
					fg^=1; tot+=fg;
					ans[j]=tot;
				}
			}
			ref(i,1,m)if(!ans[i])ans[i]=++tot;
		}
		ref(i,1,m)printf("%d ",ans[i]);
		printf("\n");
	}
}