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
const int N = 50055;
int l[N];
int head[N],edgenum,to[N<<1],nxt[N<<1];
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool gg;
void dfs(int u) {
	L(i,u) dfs(to[i]);
	int deg=0,cnt=0; L(i,u) deg++; if (!deg) l[u]=1;
	L(i,u) cnt+=l[to[i]];
	if (deg&&cnt<3) gg=1;
}
int main() {
	int n; read(n); rep(i,2,n) {int x;read(x);add(x,i);}
	dfs(1); printf("%s",!gg?"Yes":"No");
	return 0;
}