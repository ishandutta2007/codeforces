#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int n, mo, a[N];
int c[1005];

int main() {
	scanf("%d %d", &n, &mo);
	if(n > mo) {
		pp("0\n"); return 0;
	}
	fo(i, 1, n) scanf("%d", &a[i]);
	ll s = 1;
	fo(i, 1, n) fo(j, i + 1, n)
		s = s * abs(a[i] - a[j]) % mo;
	pp("%lld\n", s);
}