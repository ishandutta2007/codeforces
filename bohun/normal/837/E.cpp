#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const LL INF = 1e18;

LL gcd(LL a, LL b) {
	return (b == 0 ? a : gcd(b, a % b));
}

pair<LL, LL> euklid(LL a, LL b) {
	LL ax = 1;
	LL ay = 0;
	LL bx = 0;
	LL by = 1;
	while (b != 0) {
		LL r = a / b;
		ax -= bx * r;
		ay -= by * r;
		a -= r * b;
		swap(a, b);
		swap(ax, bx);
		swap(ay, by);
	}
	return {ax, ay};
}

LL rus(LL a, LL b, LL MOD) {
	LL c = 0;
	while (b) {
		if (b & 1) c = (a + c) % MOD;
		a = (a + a) % MOD;
		b /= 2;
	}
	return c;
}

LL rus2(LL a, LL b) {
	LL c = 0;
	while (b) {
		if (b & 1) c = (a + c);
		a = (a + a);
		a = min(a, INF);c = min(c, INF);
		b /= 2;
	}
	return c;
}

LL sol(LL a, LL b, LL MOD) { // najmniejsze roz a * x = b % MOD
	a %= MOD;
	b %= MOD;
	LL g = gcd(a, MOD);
	if (b % g != 0) return INF;
	LL odw = (rus(euklid(a, MOD).fi, b / g, MOD) % MOD + MOD) % MOD;
	return odw;
}

LL a, b, c;

vector <LL> d;

int main() {	
	scanf ("%lld%lld", &a, &b);
	
	LL g = gcd(a, b);
	
	for (LL i = 1; i * i <= a; ++i) {
		if (a % i == 0) {
			d.pb(i);
			if (i * i != a) 
				d.pb(a / i);
		}
	}
	
	sort(d.begin(), d.end());
	
	int k = 0;
	
	while (b != 0) {
		pair <LL, LL> best = {INF, 0};
		
		while (k < ss(d) && d[k] <= g) k++;
		
		for (int i = k; i < ss(d); ++i) {
			LL it = d[i];
			if (it % g == 0 && it <= b)
				best = min(best, {sol(g, b, it), it});
		}
				
		if (best.fi == INF || b - rus2(g, best.fi) < 0) {
			g = __gcd(a, b);
			c += b / g;
			break;
		}
		
		c += best.fi;
		b -= g * best.fi;
		g = gcd(a, b);
	}
	
	printf ("%lld", c);
		
	
	
	
	return 0;
}