#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1000+10;
int n,m;
char s[N][N];
int a[N][N],b[N][N];
namespace Graph{
	int cnt=1,head[N],cur[N];
	int s,t;
	struct node{
		int v,nxt,w;
	}e[N*N];
	void adde(int u,int v,int w){
		e[++cnt]={v,head[u],w};
		head[u]=cnt;
	}
	void add(int u,int v,int w){
		adde(u,v,w);
		adde(v,u,0);
	//	printf("%d->%d %d\n",u,v,w);
	}
	int dis[N];
	queue<int>q;
	bool bfs(){
		memset(dis,-1,sizeof dis);
		memcpy(cur,head,sizeof head);
		while(q.size())q.pop();
		q.push(s);dis[s]=0;
		while(q.size()){
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].v,w=e[i].w;
				if(w&&dis[v]==-1){
					dis[v]=dis[u]+1,q.push(v);
					if(v==t)return true;
				}
			}
		}
		return false;
	}
	int dfs(int u,int flow){
		if(u==t)return flow;
		int rest=flow;
		for(int i=cur[u];i&&rest;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[v]==dis[u]+1&&w){
				int tmp=dfs(v,min(rest,w));
				rest-=tmp;
				e[i].w-=tmp;
				e[i^1].w+=tmp;
			}
			cur[u]=i;
		}
		if(rest==0)dis[u]=-1;
		return flow-rest;
	}
	int dinic(){
		int ans=0;
		while(bfs())
			while(int sth=dfs(s,2e9))
				ans+=sth;
		return ans;
	}
};
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='B')
				a[i][j]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			b[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
	int cnt=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(b[i][j])cnt++;
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(b[i][j]&&b[i][m]&&b[n][j])
				Graph::add(i,j+n,1);
	Graph::s=n+m,Graph::t=n+m+1;
	for(int i=1;i<n;i++)
		Graph::add(Graph::s,i,1);
	for(int i=1;i<m;i++)
		Graph::add(i+n,Graph::t,1);
	int k=Graph::dinic();
	cnt-=k;
	if(b[n][m]==0&&k%2==1)cnt++;
	if(b[n][m]==1&&k%2==1)cnt--;
	write(cnt);
}