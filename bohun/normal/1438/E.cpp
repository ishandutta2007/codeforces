#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 50;

int n, a[N], p[N], border[N];
ll sum[N], res;
priority_queue <pair<ll, int>> P;

int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}

ll ff(int id, int delta) {
	return max((ll)a[id] + delta, sum[border[id] - 1] - sum[id] - a[id]);
}

bool isgood(int l, int r) {
	assert(r - l > 1);
	return sum[r - 1] - sum[l] == (a[l] ^ a[r]);
}

void solve(int delta) {
	rep(i, 1, n + 1) p[i] = i;
	rep(i, 1, n) {
		border[i] = i + 1;
		if (i != n)
			P.push({-ff(i, delta), i});
	}
	while (!P.empty()) {
		ll val = -P.top().fi;
		int id = P.top().se;
		P.pop();
		while (1) {
			int nxt = find(border[id] + 1);
			//~ cout << id << " " << border[id] << " " << nxt << " " << p[id] << endl;
			if (nxt >= n + 1) break;
			if (a[nxt] < val) {
				p[nxt] = find(nxt + 1);
				assert(find(nxt + 1) >= nxt + 1);
				continue;
			}
			res += isgood(id, nxt);
			border[id] = nxt;
			P.push({-ff(id, delta), id});
			break;
		}
	}
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i), sum[i] = sum[i - 1] + a[i];
	solve(0);
	reverse(a + 1, a + n + 1);
	rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
	solve(1);
	printf ("%lld\n", res);
	return 0;
}