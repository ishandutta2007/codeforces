#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; ll a[N];
ll aabs(ll x){ return x>=0?x:-x; }
ll gcd(ll x,ll y){ return y==0?x:gcd(y,x%y); }
int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	ll g=0; rep(i,2,n) g=gcd(g,aabs(a[i]-a[i-1]));
	rep(i,1,m){
		ll b; scanf("%lld",&b);
		printf("%lld ",gcd(g,b+a[1]));
	}
	return 0;
}