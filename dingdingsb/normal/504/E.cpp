// Problem: CF504E Misha and LCP on Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF504E
// Memory Limit: 500 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
#define mid ((l+r)>>1)
typedef long long ll;
const int N=3e5+100,M=20;
int mod1,mod2;const int base=233;
mt19937 rnd(random_device{}());
int pw1[N],pw2[N],i1[N],i2[N],lg[N];
int ksm(int a,int b,int mod){int res=1;while(b)(b&1)&&(res=1ll*res*a%mod),a=1ll*a*a%mod,b>>=1;return res;}
void init(){
	vector<int>mods;
	auto isp=[&](int x){
		for(int i=2;i*i<=x;i++)if(x%i==0)return false;
		return true;
	};
	uniform_int_distribution<int>dis(1e8/2,1e9/2);
	while(mods.size()<2){
		int kk=dis(rnd)*2+1;
		if(isp(kk))mods.pb(kk);
	}
	mod1=mods[0];
	for(int i=2;i<N;i++)lg[i]=lg[i>>1]+1;
}
int n,m;
char c[N];
vector<int>e[N],a[N],b[N];
int dep[N],top[N],f[N][M];
pair<int,int>mx[N];
struct Hash{
	int x;
	Hash(int x=0):x(x){}
	friend Hash operator+(Hash a,Hash b){return Hash((a.x+b.x)%mod1);}
	friend Hash operator-(Hash a,Hash b){return Hash((a.x+mod1-b.x)%mod1);}
	friend Hash operator*(Hash a,Hash b){return Hash(1ll*a.x*b.x%mod1);}
	friend bool operator==(Hash a,Hash b){return a.x==b.x;}
}h1[N],h2[N];
void dfs1(int u){
	dep[u]=dep[f[u][0]]+1;
	mx[u]=mp(dep[u],0);
	for(auto v:e[u])if(v!=f[u][0]){
		f[v][0]=u;
		for(int i=0;f[v][i];i++)
			f[v][i+1]=f[f[v][i]][i];
		dfs1(v);
		chkmx(mx[u],mp(mx[v].fi,v));
	}
}
void dfs2(int u){
	if(!top[u])top[u]=u;
	if(u==top[u]){
		for(int i=0,o=u;i<=mx[u].fi-dep[u];i++)
			a[u].pb(o),o=f[o][0];
		for(int i=0,o=u;i<=mx[u].fi-dep[u];i++)
			b[u].pb(o),o=mx[o].se;
	}
	if(mx[u].se)top[mx[u].se]=top[u];
	for(auto v:e[u])if(v!=f[u][0])dfs2(v);
}
int ask(int x,int k){
	if(!k)return x;
	x=f[x][lg[k]];
	k-=1<<lg[k];
	k-=dep[x]-dep[top[x]];
	x=top[x];
	return k>=0?a[x][k]:b[x][-k];
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]][0];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
void dfs3(int u){
	h1[u]=h1[f[u][0]]+Hash(c[u])*Hash(pw1[dep[u]]);
	h2[u]=h2[f[u][0]]*Hash(base)+Hash(c[u]);
	for(auto v:e[u])if(v!=f[u][0])
		dfs3(v);
}
Hash calc(int x,int y,int l,int nd){
	int len=dep[x]-dep[l]+1;
	if(len>=nd){
		y=ask(x,nd-1);
		return (h1[x]-h1[f[y][0]])*Hash(i1[dep[y]]);
	}
	Hash tmp=(h1[x]-h1[f[l][0]])*Hash(i1[dep[l]])*Hash(pw1[nd-len]);
	return tmp+h2[ask(y,dep[y]-(dep[l]+nd-len))]-h2[l]*Hash(pw1[nd-len]);
}
signed main(){
	init();
	read(n);
	scanf("%s",c+1);
	for(int i=1,u,v;i<n;i++)
		read(u,v),e[u].pb(v),e[v].pb(u);
	dfs1(1);
	dfs2(1);
	pw1[0]=1;pw1[1]=base;
	i1[0]=1;i1[1]=ksm(base,mod1-2,mod1);
	for(int i=2;i<N;i++)
		pw1[i]=1ll*pw1[i-1]*base%mod1,
		i1[i]=1ll*i1[i-1]*i1[1]%mod1;
	dfs3(1);
	read(m);
	while(m--){
		int x1,y1,x2,y2;read(x1,y1,x2,y2);
		int l1=lca(x1,y1),l2=lca(x2,y2);
		int l=1,r=min(dep[x1]+dep[y1]-2*dep[l1]+1,dep[x2]+dep[y2]-2*dep[l2]+1);
		int ans=0;
		while(l<=r){
			if(calc(x1,y1,l1,mid)==calc(x2,y2,l2,mid))
				ans=mid,l=mid+1;
			else r=mid-1;
		}
		write(ans);pc('\n');
	}
	return 0;
	cerr<<"c*fnm**";
}