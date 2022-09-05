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
const int N = 600020;
int n,m,f[N],ans,vis[N];
struct P {
	int a,b,c;
} p[N];

inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(P a, P b) {
	return a.c>b.c;
}
inline int find(int x) {
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline void merge(int x, int y, int v) {
	int a=find(x),b=find(y);
	if (a!=b) {
		if (vis[a]==1&&vis[b]==1) return;
		else {f[a]=b; ans+=v; vis[b]|=vis[a];}
	}
	else if (vis[a]==0) {vis[a]=1; ans+=v;}
}
int main() {
	read(n); read(m);
	rep(i,1,m) {read(p[i].a);read(p[i].b);read(p[i].c);}
	sort(p+1,p+m+1,cmp);
	rep(i,1,n) f[i]=i;
	rep(i,1,m) merge(p[i].a,p[i].b,p[i].c);
	printf("%d\n",ans);
	return 0;
}