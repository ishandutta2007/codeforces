#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 2100;

int n, y[N], xl[N], xr[N];

vector <pair<ld, int>> v;

ld angle(int x, int y, int xx, int yy) {
	return (ld) (xx - x) / (y - yy);
}

void add(ld a, ld b) {
	if (a > b) swap(a, b);
	v.pb({a, +1});
	v.pb({b, -1});
}

struct hull {
	struct line {
		int a, b;
		ld val(ld x) {
			return a * x + b;
		} 
	};
	vector <line> v;
	void add(int a, int b) {
		v.pb({a, b});
	}
	ld inter(line p, line q) {
		return (ld) (q.b - p.b) / (p.a - q.a);
	}
	void build() {
		sort(all(v), [&](line p, line q) {
			if (p.a != q.a) return p.a > q.a;
			return p.b < q.b;
		});
		vector <line> f;
		for (auto p : v) {
			if (!f.empty() && f.back().a == p.a) continue;
			while (ss(f) >= 2 && inter(p, f.back()) <= inter(f[ss(f) - 2], f.back())) f.pop_back();
			f.pb(p);
		}
		v = f;
		reverse(all(v));
	}
	
	ld opt(ld x) {
		while (ss(v) >= 2 && v.back().val(x) > v[ss(v) - 2].val(x)) v.pop_back();
		return v.back().val(x);
	}
} Max, Min;

ld out = 1e30;

void gao(ld x) {
	//cout << "kat = " << x << endl;
	out = min(out, -Max.opt(x) - Min.opt(x));
	//cout << "out = " << out << endl;
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) 
		scanf ("%d%d%d", xl + i, xr + i, y + i);
	
	rep(i, 1, n)
		rep(j, 1, n)
			if (y[i] > y[j]) 
				add(angle(xr[i], y[i], xl[j], y[j]), angle(xl[i], y[i], xr[j], y[j])); 
			
	sort(all(v));
	
	if (v.empty()) {
		int l = 1e9, r = -1e9;
		rep(i, 1, n) {
			l = min(l, xl[i]);
			r = max(r, xr[i]);
		}
		return printf ("%d\n", r - l), 0;
	}
	
	rep(i, 1, n) {
		Max.add(-y[i], -xl[i]);
		Max.add(-y[i], -xr[i]);
		Min.add(y[i], xl[i]);
		Min.add(y[i], xr[i]);
	}
	Max.build();
	Min.build();
		
	int b = 0;
	rep(i, 0, ss(v) - 1) {
		ld x = v[i].fi;
		int k = v[i].se;
		if (k == -1) {
			b--;
			if (!b) gao(x);
		}
		if (k == 1) {
			if (!b) gao(x);
			b++;
		}
	}
	printf ("%.15Lf\n", out);
	
	return 0;
}