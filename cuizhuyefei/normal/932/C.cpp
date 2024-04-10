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
const int N = 1020000;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline void exgcd(int a, int b, ll &x, ll &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
int n,a,b;
ll x,y;
int p[N];
inline void ff(int &cnt, int len) {
	p[cnt+len-1]=cnt;
	rep(i,1,len-1) {p[cnt]=cnt+1; cnt++;}
	cnt++;
}
int main() {
	read(n); read(a); read(b);
	exgcd(a,b,x,y); //ax+by=n;
	int GCD=gcd(a,b);
	if (n%GCD!=0) {puts("-1"); return 0;}
	x*=n/GCD; y*=n/GCD;
	ll X=b/GCD,Y=a/GCD;
	if (x<0) {x%=X; if (x<0) x+=X; y=(n-a*x)/b;}
//	printf("%lld %lld\n",x,y);
	if (y<0) {y%=Y; if (y<0) y+=Y; x=(n-b*y)/a;}
//	printf("%lld %lld\n",x,y);
	if (x<0||y<0) {puts("-1"); return 0;}
	int now=1;
	rep(i,1,x) ff(now,a);
	rep(i,1,y) ff(now,b);
	rep(i,1,n) printf("%d ",p[i]);
	return 0;
}