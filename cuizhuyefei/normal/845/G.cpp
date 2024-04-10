#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 303000;
int n,m,head[N],to[N],nxt[N],val[N],edgenum=1;
inline void add(int u, int v, int w) {
	to[++edgenum]=v; val[edgenum]=w;
	nxt[edgenum]=head[u]; head[u]=edgenum;
}
struct Gauss {
	int v[32];
	inline void add(int x) {
		per(i,30,0) if ((x>>i)&1)
			if (!v[i]) {v[i]=x; break;}
			else x^=v[i];
	}
	inline int query(int x) {
		per(i,30,0) x=(x^v[i])<x ? x^v[i] : x;
		return x;
	}
} gauss;
int vis[N],tree[N],v[N];
inline void dfs(int u, int Val) {
	vis[u]=1; v[u]=Val;
	L(i,u) if (!vis[to[i]]) {tree[i>>1]=1; dfs(to[i],Val^val[i]);}
	else if (!tree[i>>1]) {
		gauss.add(v[to[i]]^v[u]^val[i]);
	}
}
int main() {
	read(n); read(m);
	rep(i,1,m) {int a,b,c; read(a);read(b);read(c);add(a,b,c);add(b,a,c);}
	dfs(1,0); printf("%d",gauss.query(v[n]));
	return 0;
}