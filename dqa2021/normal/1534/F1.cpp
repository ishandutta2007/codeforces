#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
char mp[400010];
int gethash(int x,int y){
	return (x-1)*m+y;
}

vector<int> e[400010];
void adde(int x,int y){
	if (y<1||y>n*m) return;
	if (mp[y]=='.') return;
//	printf("adde %d %d\n",x,y);
	e[x].pb(y);
}

int dfn[400010],low[400010];
int stk[400010]; bool vis[400010];
int h[400010],htot;
int d[400010];

void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x,vis[x]=1;
	forall(x,y)
		if (!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (vis[y])
			low[x]=min(low[x],dfn[y]);
	if (low[x]^dfn[x]) return;
	++htot; int u;
	do{
		u=stk[*stk]; --*stk;
		vis[u]=0; h[u]=htot;
	}while (u!=x);
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) scanf("%s",mp+1+(i-1)*m);
	rep(i,1,n) rep(j,1,m){
		int o;
		if (mp[o=gethash(i,j)]=='.') continue;
//		printf("test o %d\n",o);
		adde(o,o-m);
		int k=i,g=o;
		while (k<=n&&(g==o||mp[g]=='.')){
			if (j>1) adde(o,g-1);
			if (j<m) adde(o,g+1);
			++k,g+=m;
		}
		adde(o,g);
	}
	rep(i,1,n*m) if (mp[i]!='.'&&!dfn[i]) tarjan(i);
	rep(i,1,n*m) if (mp[i]!='.') forall(i,j) if (h[i]^h[j]) ++d[h[j]];
	int z=0;
	rep(i,1,htot) z+=!d[i];
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}