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
const int N = 303000;
int n,m,a[N],s[N];
int head[N],edgenum,nxt[N],to[N];
inline void add(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
bool cmp(int x, int y) {return a[x]>a[y];}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int f[N],siz[N];
inline int find(int x) {
	if (f[x]==x) return x;
	f[x]=find(f[x]); return f[x];
}
int main() {
	read(n); read(m); rep(i,1,n) read(a[i]),s[i]=i,f[i]=i,siz[i]=1;
	rep(i,1,m) {int x,y; read(x); read(y); add(x,y); add(y,x);}
	sort(s+1,s+n+1,cmp); ll ans=0;
	rep(j,1,n) {
		int u=s[j];
		for (int i=head[u]; i!=0; i=nxt[i]) if (a[to[i]]>=a[u]&&find(to[i])!=find(u)) {
			int fx=f[to[i]],fy=f[u]; 
			ans+=1LL*siz[fx]*siz[fy]*a[u];
			f[fx]=fy; siz[fy]+=siz[fx];
		}
	}
	printf("%lf",(double)ans*2/n/(n-1));
	return 0;
}