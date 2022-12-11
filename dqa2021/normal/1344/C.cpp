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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m;
vector<int> e[200010],ie[200010];
int d[200010];
int f[200010],g[200010];  // front; back
void solve(){
	n=read(),m=read();
	rep(i,1,m){
		int u=read(),v=read();
		e[u].pb(v); d[v]++;
		ie[v].pb(u);
	}
	static int que[200010],hd,tl;
	rep(i,1,n) if (!d[i]) que[++tl]=i;
	while (hd<tl){
		int u=que[++hd];
		for (int v: e[u]){
			if (!--d[v]) que[++tl]=v;
		}
	}
	if (tl!=n) puts("-1"),exit(0);
	rep(i,1,n){
		int x=que[i];
		f[x]=x;
		for (int y: ie[x]) f[x]=min(f[x],f[y]);
	}
	per(i,1,n){
		int x=que[i];
		g[x]=x;
		for (int y: e[x]) g[x]=min(g[x],g[y]);
	}
	int tot=0;
	rep(i,1,n){
		if (min(f[i],g[i])<i);
		else ++tot;
	}
	printf("%d\n",tot);
	rep(i,1,n){
		if (min(f[i],g[i])<i) putchar('E');
		else putchar('A');
	}
	puts("");
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}