#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 303;
int n, m, p[N], q[1 << 20], sz, a, b, c;
pair<ll, ll> ans[1 << 20];
vector<array<int, 3>> e;

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return 0;
	p[x] = y;
	return 1;
}

pair<ll, ll> solve(int x) {
	rep(i, 1, n) p[i] = i;
	sort(e.begin(), e.end(), [&](array<int, 3> a, array<int, 3> b) {
		return abs(a[2] - x) < abs(b[2] - x);
	});
	ll A = 0;
	ll B = 0;
	for (auto [a, b, c] : e) {
		if (join(a, b)) {
			if (x < c) {
				A -= 1;
				B += c;
			}
			else {
				A += 1;
				B -= c;
			}
		}
	}
	return {A, B};
}

ll get(int x) {
	auto [a, b] = ans[upper_bound(q + 1, q + sz + 1, x) - q - 1];
	return a * x + b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	rep(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({a, b, c});
	}
	int p, k;
	cin >> p >> k >> a >> b >> c;
	q[++sz] = 0;
	q[++sz] = c;
	rep(i, 0, m - 1) {
		q[++sz] = e[i][2];
		rep(j, i + 1, m - 1) {
			int mid = (e[i][2] + e[j][2]) / 2;
			q[++sz] = mid - 1;
			q[++sz] = mid;
			q[++sz] = mid + 1;
		}
	}
	sort(q + 1, q + sz + 1);
	sz = unique(q + 1, q + sz + 1) - q - 1;
	rep(i, 1, sz - 1) ans[i] = solve(q[i]);
	
	ll xo = 0, q;
	rep(i, 1, p) {
		cin >> q;
		xo ^= get(q);
	}
	rep(i, p + 1, k) {
		q = (1ll * q * a + b) % c;
		xo ^= get(q);
	}
	cout << xo << endl;
	return 0;
}