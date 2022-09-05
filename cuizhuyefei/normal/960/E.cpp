#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 500000, mo = 1e9+7;
int n,head[N],v[N],to[N],nxt[N],edgenum;
void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int size[N],tot,f[N],dep[N]; ll ans;
void dfs(int u, int fa, int depth) {
	size[u]=1; dep[u]=depth;
	f[u]=(dep[u]==1)?1:-1;
	L(i,u) if (to[i]!=fa) dfs(to[i],u,depth^1),size[u]+=size[to[i]],f[u]+=f[to[i]];
}
ll CNT[N];
void dfs1(int u, int fa) {
	int cnt=tot-(dep[u]==1?1:-1);
	L(i,u) if (to[i]!=fa) {
		dfs1(to[i],u);
		int now=f[to[i]]; cnt-=now;
		ans+=1LL*(dep[u]==1?1:-1)*now*(n-size[to[i]])%mo*v[u]%mo;
		CNT[u]+=1LL*(dep[u]==1?1:-1)*now*(n-size[to[i]])%mo;
	}
	CNT[u]+=1LL*(dep[u]==1?1:-1)*cnt*(size[u])%mo+n;
	ans+=1LL*(dep[u]==1?1:-1)*cnt*(size[u])%mo*v[u]%mo;
	ans+=1LL*n*v[u]%mo;
}
int main() {
	read(n); rep(i,1,n) read(v[i]);
	rep(i,2,n) {int x,y;read(x);read(y);add(x,y);add(y,x);}
	dfs(1,0,0); tot=f[1];
	dfs1(1,0);
//	rep(i,1,n) printf("%lld ",CNT[i]); puts("");
	cout<<((ans%mo+mo)%mo);
	return 0;
}