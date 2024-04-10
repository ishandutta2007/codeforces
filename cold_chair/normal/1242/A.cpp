#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

ll n;
ll p[100], p0;

int main() {
	scanf("%lld", &n);
	if(n == 1) {
		pp("1\n");
		return 0;
	}
	ll x = n;
	for(ll i = 2; i * i <= n; i ++) if(n % i == 0) {
		p[++ p0] = i;
		while(n % i == 0) n /= i;
	}
	if(n > 1) p[++ p0] = n;
	if(p0 > 1) pp("1\n"); else pp("%lld\n", p[1]);
}