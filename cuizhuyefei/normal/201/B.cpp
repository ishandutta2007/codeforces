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
const int N = 1020;
ll n,m,a[N][N];

inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline ll dis(int x, int y) {return (1LL*x*x+1LL*y*y);}
inline ll getans(int x, int y) {
	x*=4; y*=4;
	ll res=0;
	rep(i,1,n) rep(j,1,m) {
		res+=dis(i*4-2-x,j*4-2-y)*a[i][j];
	}
	return res;
}
int main() { //freopen("1.in","r",stdin);
	read(n);read(m);rep(i,1,n)rep(j,1,m)read(a[i][j]);
	int x=0,y=0;
	ll v=getans(0,0); int l=1,r=n;
	while (r-l>=4) {
		int m1=(l*2+r)/3,m2=(l+r*2)/3;
		if (getans(m1,0)>getans(m2,0)) l=m1; else r=m2;
	}
	rep(i,l,r) if (getans(i,0)<v) {v=getans(i,0); x=i;}
	
	v=getans(0,0); l=1,r=m;
	while (r-l>=4) {
		int m1=(l*2+r)/3,m2=(l+r*2)/3;
		if (getans(0,m1)>getans(0,m2)) l=m1; else r=m2;
	}
	rep(i,l,r) if (getans(0,i)<v) {v=getans(0,i); y=i;}
	printf("%lld\n%d %d",getans(x,y),x,y);
//	rep(i,0,n) {rep(j,0,m)printf("%lld ",getans(i*4,j*4));puts("");}
	return 0;
}