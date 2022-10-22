#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 1 << 20;
int n, a[N], res, xo[N], last[2][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    rep(i, 1, n)
	cin >> a[i];
    rep(j, 0, 19) {
	rep(i, 0, 1)
	    memset(last[i], -1, sizeof last[i]);
	for (int i = 1; i <= n;) {
	    if (!(a[i] >> j & 1)) {
		i++;
		continue;
	    }
	    int k = i;
	    while (k <= n && (a[k] >> j & 1))
		k++;

	    auto upd = [&](int a, int b, int c) {
		if (last[a][b] == -1)
		    last[a][b] = c;
	    };

	    xo[i - 1] = 0;
	    upd((i - 1) % 2, xo[i - 1], i - 1);
	    rep(q, i, k - 1) {
		xo[q] = xo[q - 1];
		rep(bit, j + 1, 19)
		    if (a[q] >> bit & 1)
			xo[q] ^= 1 << bit;
		upd(q % 2, xo[q], q);
		res = max(res, q - last[q % 2][xo[q]]);
	    }
	    rep(q, i - 1, k - 1)
		last[0][xo[q]] = last[1][xo[q]] = -1;

	    i = k;
	}
    }
    cout << res << '\n';

    return 0;
}