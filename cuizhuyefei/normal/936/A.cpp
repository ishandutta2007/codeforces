#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
ll k,d,t,b;
int main() {
	read(k);read(d);read(t);
	b=k/d*d; while (b<k) b+=d; 
	long double x=(long double)k/t+(long double)(b-k)/2/t;
	ll zhouqi=(long double)1.0/x; long double val=1-zhouqi*x;
//	printf("%lld %lld %lf\n",zhouqi,t,(double)val);
	long double ans=0;
	if (val<=1.0*k/t) ans=val*t;
	else ans=2*t*val-k;
	ans+=(long double)zhouqi*b;
	printf("%lf",(double)ans);
	return 0;
}