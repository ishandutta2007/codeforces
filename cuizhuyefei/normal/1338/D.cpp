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
const int N = 166666;
int n,f[N],g[N],res;Vi e[N];
void dfs(int u, int fa){
	for(int v:e[u])if(v!=fa)dfs(v,u);
	static int s[N];int len=0;
	for(int v:e[u])if(v!=fa)s[++len]=v;
	if(!len){f[u]=1;return;}
	rep(i,1,len)umax(f[u],g[s[i]]);f[u]++;
	rep(i,1,len)umax(g[u],max(f[s[i]],g[s[i]]));g[u]+=len-1;
	if(len>=2){
		static int a[N];
		rep(i,1,len)a[i]=g[s[i]];
		sort(a+1,a+len+1);
		umax(res,1+a[len]+a[len-1]);
		rep(i,1,len)a[i]=max(g[s[i]],f[s[i]]);
		sort(a+1,a+len+1);
		umax(res,len-2+(fa>0)+a[len]+a[len-1]);
	}
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	int rt=1;while(SZ(e[rt])==1)rt++;
	dfs(rt,0);cout<<res;
	return 0;
}