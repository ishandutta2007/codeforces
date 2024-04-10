#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

int T, n, b;
ll a, y;
inline ll mul(ll a, ll b, ll P){
	return (a*b%P-(ll)((double)a*b/P)*P+P)%P;
}
inline ll Log(ll x, int p, int a){ // log_2 x mod p^a
	ll pa=p, phi=p-1;
	for(int i=1; i<a; ++i) pa*=p, phi*=p;
	ll g=0, now=1;
	while((now-x)%p) ++g, now=now*2%pa;
	ll y=1;
	for(int i=1; i<p; ++i) y=y*2%pa;
	for(ll i=1, pp=p; i<a; ++i, pp*=p){
		while((now-x)%(pp*p)) g=(g+pp/p*(p-1))%phi, now=mul(now, y, pa);
		ll z=y;
		for(int j=1; j<p; ++j) y=mul(y, z, pa);
	}
	return g;
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%lld", &a), n=0;
		for(ll i=a; i; i/=10) ++n;
		b=(1<<(n+6))-a*1000000%(1<<(n+6));
		if(b%5==0) b+=1<<(n+6);
		y=(a*1000000+b)>>(n+6);
		printf("%lld\n", Log(y, 5, n+6)+n+6);
	}
	return 0;
}