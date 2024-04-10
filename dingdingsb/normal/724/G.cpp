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
const int maxn_wei=63;
int pw[maxn_wei];
struct Linear_Basis{
	ll b[maxn_wei];int size;
	bool flag[maxn_wei];
	inline void init(){size=0;memset(b,0,sizeof b);memset(flag,0,sizeof flag);}
	inline void insert(ll x){
		//printf("Insert %lld\n",x);
		for(int i=maxn_wei-1;i>=0;i--)
			flag[i]|=((x&(1ll<<i))!=0);
		for(int i=maxn_wei-1;i>=0;i--){
			if(!(x&(1ll<<i)))continue;
			if(!b[i]){size++;b[i]=x;return;}
			x^=b[i];
		}
	}
	inline void print(){for(int i=maxn_wei-1;i>=0;i--)printf("%d %d\n",b[i],flag[i]);printf("\n");}
}B;
const int maxn=1e5+10;
const int maxm=2e5+10;
struct Graph{
	struct node{int v;ll w;int nxt;}e[maxm*4];
	int cnt,head[maxn*2];
	void add(int x,int y,ll w){e[++cnt]=(node){y,w,head[x]};head[x]=cnt;}
	#define For(G,x) for(int __=(G).head[x];__;__=(G).e[__].nxt)
	#define v(G) (G).e[__].v
	#define w(G) (G).e[__].w
	
}G;
int cnt[maxn_wei];
int n,m,u,v,pos;ll w;
bool vis[maxn];
ll dis[maxn];
const ll mod=1e9+7;
inline ll fpow(int b){
	ll a=2,ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ret;
}
void dfs(int x,ll res,int fa){
	//printf("%d %lld\n",x,res);
	vis[x]=true;
	dis[x]=res;pos++;
	for(int i=0;i<maxn_wei;i++)
		if(res&(1ll<<i))cnt[i]++;
	For(G,x){
		if(v(G)==fa)continue;
		if(!vis[v(G)])dfs(v(G),res^w(G),x);
		else B.insert(res^w(G)^dis[v(G)]);
	}
}
ll ans=0;
inline ll C(ll x){
	return x*(x-1)*500000004%mod;
}
signed main(){
	//freopen("ttt.in","r",stdin); 
	pw[0]=1;
	for(int i=1;i<maxn_wei;i++)pw[i]=(pw[i-1]<<1)%mod;
	read(n,m);
	for(int i=1;i<=m;i++){read(u,v,w);G.add(u,v,w),G.add(v,u,w);}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			memset(cnt,0,sizeof cnt);
			B.init();
			pos=0;
			dfs(i,0,-1);
			//B.print();
			for(int j=0;j<maxn_wei;j++){
				if(B.flag[j])ans=(ans+1ll*C(pos)*pw[j]%mod*pw[B.size-1])%mod;
				else ans=(ans+1ll*cnt[j]*(pos-cnt[j])%mod*pw[j]%mod*pw[B.size])%mod; 
			}
		}
	write(ans);
}