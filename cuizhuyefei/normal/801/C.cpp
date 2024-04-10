#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
#define N 100005
int n,p;
int a[N],b[N];
const long double EPS=1e-8;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int ok(long double time) {
	long double Spare=time*p;
	rep(i,1,n) if ((long double)b[i]/a[i]-time<EPS) {
		Spare-=(time*a[i]-b[i]);
	}
	return Spare>=EPS;
}
int main()
{
//	freopen("1.in","r",stdin);
	read(n); read(p);
	rep(i,1,n) read(a[i]),read(b[i]);
	ll tot=0; rep(i,1,n) tot+=a[i];
	if (tot<=p) {puts("-1"); return 0;}
	long double l=0,r=1e12;
	while ((r-l)>EPS) {
		long double mid=(l+r)/2;
		if (ok(mid)) l=mid;
		else r=mid;
	}
	long double ans=(l+r)/2;
	printf("%.10lf",(double)ans);
	return 0;
}