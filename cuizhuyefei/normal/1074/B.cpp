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
const int N = 1050;
int n,a[N],s[N],y;Vi e[N];
void getans(int x){
	printf("C %d\n",x);fflush(stdout);
}
void dfs(int u, int fa){
	if(a[u]&&!y)y=u;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
		dfs(e[u][i],u);
}
void solve(int m){//s[1..m]
	printf("B %d\n",s[1]);fflush(stdout);
	int x;read(x);
	if(a[x]){getans(x);return;}
	y=0;dfs(x,0);
	printf("A %d\n",y);fflush(stdout);
	int z;read(z);
	rep(i,1,m)if(s[i]==z){getans(y);return;}
	getans(-1);
}
int main() {
	int T;read(T);
	while(T--){
		read(n);
		rep(i,1,n)e[i].clear(),a[i]=0;
		rep(i,1,n-1){
			int u,v;read(u);read(v);e[u].pb(v);
			e[v].pb(u);
		}
		int k1,k2,x;read(k1);
		rep(i,1,k1){read(x);a[x]=1;}
		read(k2);rep(i,1,k2){
			read(s[i]);
		}
		solve(k2);
	}
	return 0;
}