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
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 903000;
int n,col[N];
struct S{int a,b;} s[N];
int head[N],nxt[N],to[N],edgenum;
inline void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void add(int u, int v) {addedge(u,v); addedge(v,u);}

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void dfs(int u, int val) {
	col[u]=val;
	for (int i=head[u]; i!=0; i=nxt[i]) if (!col[to[i]]) dfs(to[i],val==1?2:1);
}
int main() {
	read(n); rep(i,1,n) {
		read(s[i].a),read(s[i].b); add(s[i].a,s[i].b);
	//	dy[s[i].a]=s[i].b; dy[s[i].b]=s[i].a;
	}
	rep(i,1,n) add(i*2,(i<n)?i*2+1:1);
	rep(i,1,n<<1) if (!col[i]) dfs(i,1); 
	rep(i,1,n) printf("%d %d\n",col[s[i].a],col[s[i].b]);
	return 0;
}