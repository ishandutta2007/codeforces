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
const int N = 1200000;
vector<int> e[N];
int head[N],edgenum,to[N<<1],nxt[N<<1],deg[N];
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum; deg[v]++;
}
int n,m,q[N]; //suodian -> ji
bool exist[N],rd[N];
int ok[N][2],pre[N][2];

inline void inc(int &x) {x++; if (x==N) x=0;}

int vis[N];
inline bool dfs(int u) {
	vis[u]=1; int len=e[u].size();
	rep(i,0,len-1) {
		int v=e[u][i];
		if (vis[v]==1) return 1;
		if (!vis[v]&&dfs(v)) return 1;
	}
	vis[u]=2;
	return 0;
}
int main() {
	read(n); read(m);
	rep(i,1,n) {
		int l,x; read(l); rep(j,1,l) {read(x); add(x,i); e[i].push_back(x);}
	}
	int f=0,r=0; rep(i,1,n) if (!deg[i]) {q[r++]=i; ok[i][0]=1;}
	while (f!=r) {
		int u=q[f]; inc(f); exist[u]=0; rd[u]=1;
		L(i,u) {
			int v=to[i]; deg[v]--; 
			bool flag=0;
			if (!ok[v][0]&&ok[u][1]) {flag=1; ok[v][0]=1; pre[v][0]=u;}
			if (!ok[v][1]&&ok[u][0]) {flag=1; ok[v][1]=1; pre[v][1]=u;}
			if (deg[v]==0||flag) {
				if (!exist[v]) {q[r]=v; inc(r); exist[v]=1;}
			} //??????????
		}
	}
	int s; read(s);
	if (ok[s][1]) {
		puts("Win");
		int u=s,x=1;
		while (1) {
			printf("%d ",u); if (!pre[u][x]) break; u=pre[u][x]; x^=1;
		}
		return 0;
	}
	if (dfs(s)) puts("Draw"); else puts("Lose");
	return 0;
}