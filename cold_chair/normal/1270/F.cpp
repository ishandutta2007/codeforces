#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

char str[N];
int n, s[N];

map<int, int> p;
map<int, int> :: iterator it;

int T;

ll ans;

ll calc(int d, int x) {
	if(x <= d * T) return 0;
	return x / d - T;
}

int main() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	fo(i, 1, n) s[i] = s[i - 1] + str[i] - '0';
	T = sqrt((double) n / log2(n));
	fo(k, 1, T) {
		p.clear();
		fo(i, 0, n) p[i - k * s[i]] ++;
		for(it = p.begin(); it != p.end(); it ++) {
			ll x = (*it).second;
			ans += x * (x - 1) / 2;
		}
	}
	fo(d, 1, n / T) {
		int l = 0, r = 0;
		fo(i, 1, n) {
			while(s[i] - s[l] > d) l ++;
			while(s[i] - s[r] >= d) r ++;
			ans += calc(d, i - l) - calc(d, i - r);
		}
	}
	pp("%lld\n", ans);
}