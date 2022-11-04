#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define fl fflush(stdout)

ll a, b, c;

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	pp("First\n");
	ll v = 10000000000ll;
	pp("%lld\n", v); fl;
	int x; scanf("%d", &x);
	if(x == 1) a += v;
	if(x == 2) b += v;
	if(x == 3) c += v;
	ll mx = max(a, max(b, c));
	v = 2 * mx - (a + b + c - mx);
	pp("%lld\n", v); fl;
	scanf("%d", &x);
	if(x == 1) a += v;
	if(x == 2) b += v;
	if(x == 3) c += v;
	pp("%lld\n", (max(a, max(b, c)) - min(a, min(b, c))) / 2); fl;
}