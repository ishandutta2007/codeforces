//#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
const ll maxn=100000+100;
const ll maxm=100000+100;
bool flag[maxn];
ll dis[maxn];
const ll maxn_wei=64;
struct XXJ{
	//
	ll b[maxn_wei];
	void init(){memset(b,0,sizeof b);}
	void insert(ll x){
		for(ll i=maxn_wei-1;i>=0;i--){
			if(!(x&(1ll<<i)))continue;
			if(!b[i]){
				b[i]=x;
				return ;
			}
			x^=b[i];
		}
	}
}Base;
struct Graph{
	struct Edge{ll v,w,nxt;}e[maxm*2];
	ll cnt,head[maxn];
	void init(){memset(head,0,sizeof head);cnt=0;}
	void add(ll u,ll v,ll w){e[++cnt]=(Edge){v,w,head[u]};head[u]=cnt;}
	#define For(G,i) for(ll eee=(G).head[(i)];eee;eee=(G).e[eee].nxt)
	#define v(G) (G).e[eee].v
	#define w(G) (G).e[eee].w
}G;
void dfs(ll x,ll res){
	dis[x]=res;
	flag[x]=true;
	For(G,x){
		if(!flag[v(G)])dfs(v(G),res^w(G));
		else Base.insert(res^w(G)^dis[v(G)]);
	} 
}
ll n,m,u,v,w;
signed main(){
	read(n,m);
	for(ll i=1;i<=m;i++){
		read(u,v,w);
		G.add(u,v,w);
		G.add(v,u,w);
	}
	dfs(1,0);
	ll ans=dis[n];
	for(ll i=maxn_wei-1;i>=0;i--)
		if((ans^Base.b[i])<ans)
			ans^=Base.b[i];
	write(ans);
}