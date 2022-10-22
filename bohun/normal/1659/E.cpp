#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 200200;
int n, m, good[N];

struct DSU {
	int p[N], good[N];
	DSU() { rep(i, 0, N - 1) p[i] = i; }
	int get(int x) {
		return x == p[x] ? x : p[x] = get(p[x]);
	}
	bool merge(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return false;
		p[x] = y;
		return true;
	}
	bool same(int x, int y) {
		return get(x) == get(y);
	}
} UF[31];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	rep(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		rep(i, 0, 29)
			if (c >> i & 1)
				UF[i].merge(a, b);
		if (~c & 1) {
			// cat(a);cat(b);
			good[a] = 1;
			good[b] = 1;
		}
	}

	rep(i, 1, n) {
		if (good[i]) {
			rep(j, 1, 29) {
				UF[j].good[UF[j].get(i)] = 1;
			}
		}
	}

	int q;
	cin >> q;
	rep(_, 1, q) {
		int a, b;
		cin >> a >> b;
		int res = 2;
		rep(i, 0, 29) if (UF[i].same(a, b)) res = 0;
		rep(i, 1, 29) if (UF[i].good[UF[i].get(a)] == 1) { res = min(res, 1); }
		cout << res << "\n";
	}

	return 0;
}