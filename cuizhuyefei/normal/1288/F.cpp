#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}

const int N = 16009, M = 200000, inf = 0x3f3f3f3f;
	int S,T,edgenum=1,head[N],cur[N],to[M],nxt[M],cap[M],val[M];
	inline void addedge(int u, int v, int c, int w){
		to[++edgenum]=v;cap[edgenum]=c;val[edgenum]=w;
		nxt[edgenum]=head[u];head[u]=edgenum;
	}
	inline void add(int u, int v, int c, int w){
	//	assert(u<=T&&v<=T&&u&&v);
		addedge(u,v,c,w);addedge(v,u,0,-w);
	}
	int rec[N],dis[N],q[N];bool vis[N];
	inline void inc(int &x){x++;x=x==N?0:x;}
	inline bool spfa(){
		int f=0,r=1;memset(dis,inf,4*(T+2));dis[T]=0;q[f]=T;
		while(f!=r){
			int u=q[f];inc(f);vis[u]=0;
			L(i,u)if(cap[i^1]&&dis[to[i]]>dis[u]+val[i^1]){
				dis[to[i]]=dis[u]+val[i^1];rec[to[i]]=i;
				if(!vis[to[i]]){
					q[r]=to[i],inc(r);vis[to[i]]=1;//SLF 
				}
			}
		}
		return dis[S]<inf;
	}
	bool incir[N];
	inline int dfs(int u, int flow){
		if(u==T||!flow)return flow;assert(!incir[u]);int tot=0;incir[u]=1;
		for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+val[i]&&!incir[to[i]]){
			int tmp=dfs(to[i],min(flow,cap[i]));
			cap[i]-=tmp;cap[i^1]+=tmp;tot+=tmp;flow-=tmp;if(!flow)break;
		}
		incir[u]=0;return tot;
	}
	inline Pii solve(){//int
		Pii res(0,0);
		while(spfa()){
			memcpy(cur,head,4*(T+2));
			int qaq=dfs(S,inf);res.fi+=qaq;res.se+=qaq*dis[S];
		}
		return res;
	}
int n1,n2,m,r,b,dif[N];char s[N],t[N];

int main() {
	read(n1);read(n2);read(m);read(r);read(b);
	scanf("%s%s",s+1,t+1);int big=400;
	static int pos1[N],pos2[N];
	rep(i,1,m){
		int x,y;read(x);read(y);
		pos1[i]=edgenum+1;add(x,n1+y,1,r);
		pos2[i]=edgenum+1;add(n1+y,x,1,b);
	}
	S=n1+n2+1;T=S+1;int SS=T+1;int TT=SS+1;
	add(T,S,big,0);
	rep(i,1,n1)
		if(s[i]=='R'){dif[i]--;dif[S]++;add(S,i,big-1,0);}
		else if(s[i]=='B'){dif[T]--;dif[i]++;add(i,T,big-1,0);}
		else add(S,i,big,0),add(i,T,big,0);
	rep(i,1,n2)
		if(t[i]=='R'){dif[T]--;dif[n1+i]++;add(n1+i,T,big-1,0);}
		else if(t[i]=='B'){dif[n1+i]--;dif[S]++;add(S,n1+i,big-1,0);}
		else{add(S,n1+i,big,0);add(n1+i,T,big,0);}
	int tot=0;
	rep(i,1,T)
		if(dif[i]<0)add(SS,i,-dif[i],0);
		else if(dif[i]>0)add(i,TT,dif[i],0),tot+=dif[i];
	S=SS;T=TT;
	Pii res=solve();
	if(res.fi!=tot){puts("-1");return 0;}
	printf("%d\n",res.se);
	rep(i,1,m)printf("%c",!cap[pos1[i]]?'R':(!cap[pos2[i]]?'B':'U'));
	return 0;
}