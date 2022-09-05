#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 100050;
int times;
ll ans[N],val;
int n,c[N],size[N],cnt[N],num,l[N],r[N],ver[N]; //ver:dfs_xu's dot.
int head[N],nxt[N<<1],to[N<<1],edgenum; //edge!!!
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void dfs1(int u, int fa) {
	size[u]=1; l[u]=++num; ver[num]=u;
	L(i,u) if (to[i]!=fa) {
		dfs1(to[i],u); size[u]+=size[to[i]];
	}
	r[u]=num;
}
inline void addv(int col) {
	cnt[col]++;
	if (cnt[col]==times) val+=col;
	if (cnt[col]>times) {times=cnt[col]; val=col;}
}
inline void dfs(int u, int fa, bool keep) { //keep=1 ? heavy : light
	int Bigc=-1,mx=0;
	L(i,u) if (to[i]!=fa&&size[to[i]]>mx) {mx=size[to[i]]; Bigc=to[i];}
	L(i,u) if (to[i]!=fa&&to[i]!=Bigc) dfs(to[i],u,0);
	L(i,u) if (to[i]==Bigc) dfs(to[i],u,1);
	addv(c[u]);
	L(i,u) if (to[i]!=fa&&to[i]!=Bigc) {
		int v=to[i];
		for (int j=l[v]; j<=r[v]; j++) {
			addv(c[ver[j]]);
		}
	}
	ans[u]=val; //..getquery
	if (!keep) {
		for (int j=l[u]; j<=r[u]; j++) cnt[c[ver[j]]]--;
		times=val=0;
	}
}
int main() {
	read(n);
	rep(i,1,n) read(c[i]);
	rep(i,1,n-1) {int a,b; read(a); read(b); add(a,b); add(b,a);}
	dfs1(1,-1);
	dfs(1,-1,0); //keep???
	rep(i,1,n) printf("%lld\n",ans[i]);
	return 0;
}
/*
15
1 2 3 1 2 3 3 1 1 3 2 2 1 2 3
1 2
1 3
1 4
1 14
1 15
2 5
2 6
2 7
3 8
3 9
3 10
4 11
4 12
4 13

4
1 2 3 4
1 2
2 3
2 4
*/