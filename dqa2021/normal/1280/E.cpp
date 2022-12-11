#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int lim;
ll W; ll w[80010]; int n,m;
char s[1<<20]; int len,C;

vector<int> e[1<<20];

int f[1<<20]; bool g[1<<20];

int dfs1(){
	int x=++n; e[x].clear();
	if (s[C++]=='*') return x;
	while (1){
		e[x].pb(dfs1());
		if (s[C++]==')') break;
		g[x]=s[C-1]=='P';
	}
	return x;
}

void dfs2(int x){
	f[x]=0;
	if (e[x].empty()) return f[x]=1,void();
	if (g[x]){
		forall(x,y) dfs2(y),f[x]+=f[y];
	}
	else{
		f[x]=1e9;
		forall(x,y) dfs2(y),f[x]=min(f[x],f[y]);
	}
}

void dfs3(int x,bool h){
	if (e[x].empty()){
		w[++m]=0;
		if (h) w[m]=W;
		return;
	}
	if (g[x]){
		forall(x,y) dfs3(y,h);
	}
	else{
		int t=-1;
		forall(x,y) if (f[y]==f[x]){t=y; break;}
		forall(x,y) dfs3(y,h&&t==y);
	}
}

void solve(){
	lim=read(); n=m=0;
	len=0; C=1;
	for (char c=getchar();c!='\n'&&c!='\r';c=getchar()){
		if (c=='('||c==')'||c=='P'||c=='S'||c=='*') s[++len]=c;
	}
	int rt=dfs1();
	dfs2(rt);
	W=1LL*lim*f[rt];
	dfs3(rt,1);
	printf("REVOLTING ");
	rep(i,1,m) printf("%lld ",w[i]);
	puts("");
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}