#include<bits/stdc++.h>
#define y0 y12
#define y1 y13
using namespace std;
const int MOD=1000000007;
typedef long long ll;

ll POW(ll a,ll b){
	if(b==0)return 1;
	if(b==1)return a%MOD;
	ll t=POW(a,b>>1);
	return (t*t%MOD*(b&1?a:1))%MOD;
}
ll solve(ll x1,ll y1,ll x2,ll y2){
	ll x3=2*x2-x1,y3=2*y2-y1;
	if(x3<=0 || y3<=0)return x1*y1-x2*y2;
	else return x1*y1-2*x2*y2+x3*y3+solve(x2,y2,x3,y3);
}
ll n,m,k,r,c;
int main() {
	scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&r,&c);
	ll x1,y1,x2,y2;
	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
	if(x1==x2 && y1==y2){
		ll t=n*m;
		return !printf("%lld\n",POW(k,t));
	}
	if(x1>x2){
		swap(x1,x2);
		swap(y1,y2);
	}
	ll r1,c1;
	if(y2<=y1){
		c1=y2+c-y1;
	}else{
		c1=y1+c-y2;
	}
	r1=x1+r-x2;
	ll t=0;
	if(r1<=0 || c1<=0){
		t=n*m-r*c;
	}else{
		t=n*m-2*r*c+r1*c1+solve(r,c,r1,c1);
	}
	printf("%lld\n",POW(k,t));
	return 0;
}