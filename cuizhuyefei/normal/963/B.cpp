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
const int N = 600006;
int n,p[N],deg[N];
int head[N],edgenum,to[N<<1],nxt[N<<1];
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
	deg[u]++; deg[u]%=2;
}
int dep[N],ans[N]; bool gg[N];
void dfs(int u, int fa, int depth) {
	dep[u]=depth;
	L(i,u) if (to[i]!=fa) dfs(to[i],u,depth+1);
}
struct node {
	int u;
	node(int U=0) {u=U;}
	bool operator < (const node &x) const {return dep[u]!=dep[x.u] ? dep[u]>dep[x.u] : u>x.u;}
};
set<node> Set;
void GG() {puts("NO"); exit(0);}
int main() { int x;
	read(n); rep(i,1,n) {read(x); if (x) {add(i,x); add(x,i);}}
	dfs(1,0,0); rep(i,1,n) if (!deg[i]) Set.insert(node(i));
	rep(j,1,n) {
		if (Set.empty()) GG();
		node x=*Set.begin(); Set.erase(Set.begin()); int u=x.u; ans[j]=u;
	//	printf("%d : %d --> %d\n",j,u,Set.size());
		gg[u]=1; 
		L(i,u) if (!gg[to[i]]) {
			int v=to[i]; //printf("e %d %d %d\n",u,to[i],deg[v]);
			if (!deg[v]) {Set.erase(v);} else {Set.insert(v);}
			deg[v]^=1;
		}
	}
	puts("YES");
	rep(i,1,n) printf("%d\n",ans[i]);
	return 0;
}