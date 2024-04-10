#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666,M = 360;
int In[N],Out[N],n,m,q;ll res;Vi e[N];
int nxt[N],pre[N],tail,val[N];
bool vis[200000/M+5][100005];int tot,bh[N];
int main() {
	read(n);read(m);
	rep(i,1,m){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
		if(u>v)swap(u,v);Out[u]++;In[v]++;
	}
	rep(i,1,n)val[i]=i;
	rep(i,1,n)res+=1LL*In[i]*Out[i];printf("%lld\n",res);
	rep(i,1,n-1)nxt[i]=i+1,pre[i+1]=i;tail=n;
	rep(u,1,n)if(SZ(e[u])>=M){
		bh[u]=++tot;
		rep(i,0,SZ(e[u])-1)vis[tot][e[u][i]]=1;
	}
	read(q);rep(ttt,1,q){
		int u;read(u);
		if(SZ(e[u])<M){
			rep(i,0,SZ(e[u])-1)if(val[u]<val[e[u][i]]){
				int v=e[u][i];
				res+=1LL*(In[u]+1)*(Out[u]-1)-1LL*In[u]*Out[u];In[u]++;Out[u]--;
				res+=1LL*(In[v]-1)*(Out[v]+1)-1LL*In[v]*Out[v];In[v]--;Out[v]++;
			}
		}
		else{
			for(int v=nxt[u];v;v=nxt[v])if(vis[bh[u]][v]){
				res+=1LL*(In[u]+1)*(Out[u]-1)-1LL*In[u]*Out[u];In[u]++;Out[u]--;
				res+=1LL*(In[v]-1)*(Out[v]+1)-1LL*In[v]*Out[v];In[v]--;Out[v]++;
			}
		}
		val[u]=n+ttt;
		if(u!=tail){
			nxt[pre[u]]=nxt[u];pre[nxt[u]]=pre[u];
			nxt[u]=pre[u]=0;
			pre[u]=tail;nxt[tail]=u;tail=u;
		}
		printf("%lld\n",res);
	}
	return 0;
}