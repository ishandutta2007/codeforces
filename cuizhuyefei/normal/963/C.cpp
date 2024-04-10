#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
map<ll,ll> map1,map2;
ll gcd(ll a, ll b) {return !b?a:gcd(b,a%b);}
int getans(ll n) {
	int res=1;
	for (int i=2; 1LL*i*i<=n; i++) if (n%i==0) {
		int cnt=1; while (n%i==0) n/=i,cnt++; res*=cnt;
	}
	if (n>1) res*=2;
	return res;
}
double eps =  1e-7;
ll U[233333],V[233333],W[233333];
double Abs(double a) {return a>0?a:-a;}
int main() {
//	freopen("1.in","r",stdin);
	ll n; read(n); ll a=0,b=0,c=0;
	rep(i,1,n) {
		ll a,b,C; read(a); read(b); read(C);
		c+=C; map1[a]+=C; map2[b]+=C;
		U[i]=a; V[i]=b; W[i]=C;
	}
	rep(i,1,n) if (Abs((long double)W[i]/map2[V[i]]-(long double)map1[U[i]]/c)>eps) {puts("0"); return 0;}
	while (!map1.empty()) {a=gcd(a,(*map1.begin()).se); map1.erase(map1.begin());}
	while (!map2.empty()) {b=gcd(b,(*map2.begin()).se); map2.erase(map2.begin());}
//	printf("%lld %lld %lld\n",a,b,c);
	ll GCD=gcd(a,c); a/=GCD; c/=GCD; GCD=gcd(b,c); b/=GCD; c/=GCD;
	if (c>1) puts("0");
	else {
		printf("%d",getans(a*b));
	}
	return 0;
}