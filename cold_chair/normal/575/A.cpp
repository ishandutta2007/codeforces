#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 5e4 + 5;

ll k, mo;
struct M {
	ll a[2][2];
	M() {
		a[0][0] = a[1][1] = 1;
		a[0][1] = a[1][0] = 0;
	}
};

#define mem(a) memset(a, 0, sizeof a)
M operator * (M a, M b) {
	M c; mem(c.a);
	fo(k, 0, 1) fo(i, 0, 1) fo(j, 0, 1)
		c.a[i][j] += a.a[i][k] * b.a[k][j];
	fo(i, 0, 1) fo(j, 0, 1)
		c.a[i][j] %= mo;
	return c;
}

int n, m;
ll s[N];
struct P {
	ll x, y;
} q[N];

int cmpq(P a, P b) {
	return a.x < b.x;
}

int a2[17];
M a[N], ca;
M f[16][N];

M qu(int x, int y) {
	M a;
	fd(j, 15, 0) if(x + a2[j] <= y + 1) {
		a = a * f[j][x], x += a2[j];
	}
	return a;
}

M ksm(M x, ll y) {
	M s;
	for(; y; y /= 2, x = x * x)
		if(y & 1) s = s * x;
	return s;
}

M qq(ll x, ll y) {
	M a;
	if(x > y) return a;
	ll u = x % n, v = y % n;
	if(u <= v && y - x < n) return qu(u, v);
	a = qu(u, n - 1);
	x += (n - u); y -= v + 1;
	a = a * ksm(ca, (y - x + 1) / n);
	a = a * qu(0, v);
	return a;
}

M ma(ll s1, ll s2) {
	M c;
	c.a[0][0] = 0;
	c.a[1][0] = 1;
	c.a[0][1] = s1;
	c.a[1][1] = s2;
	return c;
}

int main() {
	//freopen("a.in", "r", stdin);
	a2[0] = 1; fo(i, 1, 16) a2[i] = a2[i - 1] * 2;
	scanf("%I64d %I64d", &k, &mo);
	if(k == 0) {
		pp("0\n");
		return 0;
	}
	if(k == 1) {
		pp("%I64d\n", 1 % mo);
		return 0;
	}
	scanf("%d", &n);
	ff(i, 0, n) scanf("%I64d", &s[i]);
	scanf("%d", &m);
	fo(i, 1, m) scanf("%I64d %I64d", &q[i].x, &q[i].y);
	sort(q + 1, q + m + 1, cmpq);
	while(m > 0 && q[m].x >= k) m --;
	ff(i, 0, n) {
		a[i] = ma(s[(i - 2 + n) % n], s[(i - 1 + n) % n]);
		ca = ca * a[i];
	}
	ff(i, 0, n) f[0][i] = a[i];
	fo(j, 1, 15) ff(i, 0, n) f[j][i] = f[j - 1][i] * f[j - 1][i + a2[j - 1]];
	q[0].x = 0, q[0].y = s[0];
	M t;
	fo(i, 1, m) {
		if(q[i - 1].x == q[i].x - 1) {
			t = t * ma(q[i - 1].y, q[i].y);
		} else {
			t = t * ma(q[i - 1].y, s[(q[i - 1].x + 1) % n]);
			t = t * qq(q[i - 1].x + 3, q[i].x);
			t = t * ma(s[(q[i].x - 1) % n], q[i].y);
		}
	}

	if(q[m].x < k - 1) {
		t = t * ma(q[m].y, s[(q[m].x + 1) % n]);
		t = t * qq(q[m].x + 3, k);
	}
	pp("%I64d\n", t.a[1][1]);
}