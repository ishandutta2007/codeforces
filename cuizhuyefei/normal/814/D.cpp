#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define sqr(a) ((a)*(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1);
#define N 1005
int n,a[N];
ll x[N],y[N],r[N];
ld ans;

inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge(int a, int b) { //a is in b
	ld dis=sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b])); //!!!!!!!!
	return dis+r[a]<=r[b]+(1e-6);
}
int main() {
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) {read(x[i]);read(y[i]);read(r[i]);}
	rep(i,1,n) rep(j,1,n) if (i!=j)
		a[i]+=judge(i,j);
	ll tmp=0;
//	rep(i,1,n) printf("%d ",a[i]); puts("");
	rep(i,1,n) if (a[i]<=1||a[i]%2==1) tmp+=sqr(r[i]);
	else tmp-=sqr(r[i]);
	ans=tmp*pi;
	printf("%.8lf",(double)ans);
	return 0;
}