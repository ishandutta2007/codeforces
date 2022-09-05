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
const int N = 8030;
bool gg[N];
int n,m,a[N],s[N];
int head[N],edgenum,nxt[N],to[N];
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(int x, int y) {return a[x]>a[y];}
int main() {
	read(n); read(m);
	rep(i,1,n) read(a[i]),s[i]=i;
	rep(i,1,m) {int x,y; read(x); read(y); add(x,y); add(y,x);}
	sort(s+1,s+n+1,cmp);
	ll ans=0;
	rep(j,1,n) {
		int u=s[j];
		gg[u]=1; for (int i=head[u]; i!=0; i=nxt[i]) if (!gg[to[i]]) ans+=a[to[i]];
	}
	cout<<ans;
	return 0;
}