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
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 666666;
int n,m,a[N],p[N],id[N],vis[N];Vi e[N];
bool cmp(int x, int y){return a[x]<a[y];}
int main() {
	read(n);read(m);
	rep(i,1,m){int u,v;read(u),read(v),e[u].pb(v),e[v].pb(u);}
	rep(i,1,n)read(a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	rep(i,1,n){
		p[i]=id[i];
		for(int x:e[p[i]])vis[a[x]]=1;
		int res=1;while(vis[res])res++;
		for(int x:e[p[i]])vis[a[x]]=0;
		if(res!=a[p[i]]){puts("-1");return 0;}
	}
	rep(i,1,n)printf("%d ",p[i]);
	return 0;
}