#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define gc getchar
template<class T> void read(T &x) {
	char c = ' '; int f = 1; x = 0;
	while(c != '-' && (c < '0' || c > '9')) c = gc();
	if(c == '-') c = gc(), f = -1;
	for(; c >= '0' && c <= '9'; c = gc()) x = x * 10 + c - '0';
	x *= f;
}

const int mo = 1e9 + 7;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

const int N = 1e6 + 5;

int n;

struct P {
	ll x, y;
	P(ll _x = 0, ll _y = 0) {
		x = _x, y = _y;
	}
} a[N];

P operator - (P a, P b) { return P(a.x - b.x, a.y - b.y);}
ll operator ^ (P a, P b) { return a.x * b.y - a.y * b.x;}

struct Q {
	ll x, y, z;
} b[N], c[N], c2[N];

Q operator + (Q a, Q b) { return (Q) {a.x + b.x, a.y + b.y, a.z + b.z};}
Q operator - (Q a, Q b) { return (Q) {a.x - b.x, a.y - b.y, a.z - b.z};}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) read(a[i].x), read(a[i].y);
	reverse(a + 1, a + n + 1);
	fo(i, 1, n) a[n + i] = a[i];
	ll sum = 0;
	fo(i, 2, n - 1) sum += (a[i + 1] - a[i]) ^ (a[1] - a[i]);
	fo(i, 1, 2 * n - 1) {
		P c = a[i + 1] - a[i];
		b[i].x = -c.y, b[i].y = c.x, b[i].z = c.x * -a[i].y + c.y * a[i].x;
	}
	fo(i, 1, 2 * n - 1) {
		c[i].x = (c[i - 1].x + b[i].x % mo * i) % mo;
		c[i].y = (c[i - 1].y + b[i].y % mo * i) % mo;
		c[i].z = (c[i - 1].z + b[i].z % mo * i) % mo;
		c2[i] = c2[i - 1] + b[i];
		c2[i].x %= mo; c2[i].y %= mo; c2[i].z %= mo;
	}
	ll ans = 0;
	int l = 1; ll s1 = 0;
	fo(i, 1, n) {
		if(l <= i) {
			l = i; s1 = 0;
		} else {
			s1 -= ((a[l + 1] - a[i]) ^ (a[i - 1] - a[i]));
		}
		while(l < n + i - 1) {
			ll v = (a[l + 2] - a[l + 1]) ^ (a[i] - a[l + 1]);
			if((s1 + v) > sum / 2) break;
			s1 += v;
			l ++;
		}
		ans = (ans + sum % mo * (l - i)) % mo;
		Q d = c2[l] - c2[i];
		ll s = (d.x * a[i].x + d.y * a[i].y + d.z) % mo * (l + 1) % mo;
		d = c[l] - c[i];
		s = (s - (d.x * a[i].x + d.y * a[i].y + d.z)) % mo;
		ans = (ans - 2 * s) % mo;
	}
	ans = (ans % mo + mo) % mo;
	pp("%lld\n", ans);
}