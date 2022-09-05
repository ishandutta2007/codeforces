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
const int N = 202000;
int n,m,G,S,f[N];
struct e {int u,v,g,s;} edge[N];
multiset<int> Set;
bool cmp(e a, e b) {return a.g!=b.g ? a.g<b.g : a.s<b.s;}
inline int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
int head[N],to[N],nxt[N],val[N],edgenum;
inline void add(int u, int v, int d) {
	to[++edgenum]=v; val[edgenum]=d;
	nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void del(int u, int v) {
	int lst=0;
	for (int i=head[u]; i; i=nxt[i]) {
		if (to[i]==v) {
			if (i==head[u]) head[u]=nxt[i]; else nxt[lst]=nxt[i];
			break;
		}
		lst=i; //WA2.
	}
}
inline bool dfs(int u, int t, int fa, int &a, int &b, int &c) {
	if (u==t) return 1;
	L(i,u) if (to[i]!=fa&&dfs(to[i],t,u,a,b,c)) {
		if (c<val[i]) {c=val[i]; a=u; b=to[i];}
		return 1;
	}
	return 0;
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); read(G); read(S);
	rep(i,1,m){read(edge[i].u);read(edge[i].v);read(edge[i].g);read(edge[i].s);}
	sort(edge+1,edge+m+1,cmp); rep(i,1,n) f[i]=i; int cnt=n; ll ans=6e18;
	rep(i,1,m) if (edge[i].u!=edge[i].v) {
		int fx=find(edge[i].u),fy=find(edge[i].v);
		if (fx!=fy) {
			f[fx]=fy,cnt--,Set.insert(edge[i].s);
			add(edge[i].u,edge[i].v,edge[i].s); add(edge[i].v,edge[i].u,edge[i].s);
		}
		else {
			int u=0,v=0,w=-1; dfs(edge[i].u,edge[i].v,0,u,v,w);
			if (edge[i].s<w) {
				del(u,v); del(v,u); Set.erase(Set.find(w)); //WA1. multiset; erase first !!
				add(edge[i].u,edge[i].v,edge[i].s); add(edge[i].v,edge[i].u,edge[i].s);
				Set.insert(edge[i].s);
			}
		}
		if (cnt==1) ans=min(ans,1LL*G*edge[i].g+1LL*S*(*Set.rbegin()));
	}
	if (ans<6e18) cout<<ans; else puts("-1");
	return 0;
}