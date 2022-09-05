#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef unsigned long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 606006;
int n,m,A[N],B[N],cnt;
ll v[N],val[N], seed = 19260817, cs = 613;
inline ll Rand() {
	seed=(seed*cs>>13)^(seed*cs<<7);
	return seed;
}
map<ll,int> Map;
int bel[N],deg[N],bh[N],ans[N],now;
vector<int> List[N],to[N];
bool vis[N];
inline void dfs(int u) {
	vis[u]=1; bh[u]=++now; int len=to[u].size();
	rep(i,0,len-1) if (deg[to[u][i]]<=2&&!vis[to[u][i]]) dfs(to[u][i]);
}
int main() {
	read(n); read(m);
	rep(i,1,m) read(A[i]),read(B[i]);
	rep(i,1,n) v[i]=Rand(),val[i]=v[i];
	rep(i,1,m) {val[A[i]]+=v[B[i]]; val[B[i]]+=v[A[i]];}
	rep(i,1,n) if (!Map[val[i]]) Map[val[i]]=++cnt;
	rep(i,1,n) {bel[i]=Map[val[i]]; List[bel[i]].push_back(i);}
	rep(i,1,m) if (bel[A[i]]!=bel[B[i]]) {
		int u=bel[A[i]],v=bel[B[i]];
		to[u].push_back(v); to[v].push_back(u);
	//	printf("edge %d %d\n",u,v);
	}
	rep(i,1,cnt) {
		sort(to[i].begin(),to[i].end());
		to[i].erase(unique(to[i].begin(),to[i].end()),to[i].end());
		deg[i]=to[i].size();
	//	rep(j,0,(int)to[i].size()-1) printf("edge %d %d\n",i,to[i][j]);
	}
//	printf("<%d>\n",cnt);
	rep(i,1,cnt) if (deg[i]<=1&&!vis[i]) {dfs(i); now+=2;}
	rep(i,1,cnt) if (!vis[i]) {puts("NO"); return 0;}
	puts("YES");
	rep(i,1,n) printf("%d ",bh[bel[i]]);
	return 0;
}