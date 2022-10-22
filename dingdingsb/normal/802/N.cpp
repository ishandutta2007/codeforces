// Problem: CF802N April Fools' Problem (medium)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF802N
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=3e3+100,M=2e4+100;
int n,m,a[N],b[N];
namespace Graph{
	int s,t;
	ll dis[N];
	int flow[N],pre[N],lste[N];
	bool inq[N];
	int v[M],w[M],c[M],nxt[M];
	int tot,head[N];
	void init(int _s,int _t){
		tot=1;memset(head,0,sizeof head);
		s=_s,t=_t;
	}
	void adde(int U,int V,int W,int C){++tot;v[tot]=V,w[tot]=W,c[tot]=C,nxt[tot]=head[U];head[U]=tot;}
	void add(int u,int v,int w,int c){adde(u,v,w,c);adde(v,u,0,-c);}
	bool spfa(){
		queue<int>q;
		memset(dis,0x3f,sizeof dis);
		memset(flow,0x3f,sizeof flow);
		memset(inq,0,sizeof inq);
		dis[s]=0,pre[t]=-1;q.push(s);
		while(!q.empty()){
			int u=q.front();q.pop();inq[u]=0;
			for(int i=head[u];i;i=nxt[i]){
				if(w[i]&&dis[v[i]]>dis[u]+c[i]){
					dis[v[i]]=dis[u]+c[i];
					pre[v[i]]=u,lste[v[i]]=i;
					flow[v[i]]=min(flow[u],w[i]);
					if(!inq[v[i]])inq[v[i]]=1,q.push(v[i]);
				}
			}
		}
		return pre[t]!=-1;
	}
	pair<ll,int>mcmf(){
		//printf("%d %d\n",s,t);
		ll mncost=0;int mxflow=0;
		while(spfa()){
			int u=t;
			mxflow+=flow[t],mncost+=flow[t]*dis[t];
			while(u!=s){
				int E=lste[u];
				w[E]-=flow[t],w[E^1]+=flow[t];
				u=pre[u];
			}
		}
		return mp(mncost,mxflow);
	}
}
signed main(){
	read(n,m);
	Graph::init(n+1,n+3);
	for(int i=1;i<=n;i++)read(a[i]),Graph::add(n+1,i,1,a[i]);
	for(int i=1;i<n;i++)Graph::add(i,i+1,m,0);
	for(int i=1;i<=n;i++)read(b[i]),Graph::add(i,n+2,1,b[i]);
	Graph::add(n+2,n+3,m,0);
	write(Graph::mcmf().first);
}