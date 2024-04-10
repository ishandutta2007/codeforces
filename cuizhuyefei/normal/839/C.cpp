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
const int N=200005;
double ans;
int n;
int head[N],edgenum;
struct Edge {
	int to,nxt;
} edge[N<<1];
inline void add(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}
 
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
void dfs(int u, int fa, int len, ld gl) {
	int x=0;
	L(i,u) if (edge[i].to!=fa) x++;
	if (!x) ans+=len*gl;
	L(i,u) if (edge[i].to!=fa) dfs(edge[i].to,u,len+1,gl/x);
}
int main() {
	read(n);
	rep(i,1,n-1) {
		int a,b; read(a);read(b);
		add(a,b); add(b,a);
	}
	dfs(1,-1,0,1);
	printf("%.15lf",ans);
	return 0;
}