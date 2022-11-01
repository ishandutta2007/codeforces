#include <bits/stdc++.h>

using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const ll mod = int(1e9) + 7, pq = 2, szz = 131072, szz1 = 8;

ll seg[2 * szz], seg2[2 * szz], n, m;

void neww(int l, int r, ll k) {
	if (l > r) re;
	if (l % 2) {
		seg[l] |= k;
		neww(l + 1, r, k);
		re;
	}
	if (r % 2 == 0) {
		seg[r] |= k;
		neww(l, r - 1, k);
		re;
	}
	neww(l / 2, r / 2, k);
}

int get_(int l, int r) {
	if (l > r) re ll(1LL << 30LL) - 1;
	if (l % 2) {
		re (seg[l] & get_(l + 1, r));
	}
	if (r % 2 == 0) {
		re (seg[r] & get_(l, r - 1));
	}
	re get_(l / 2, r / 2);
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m;
	vector<int> l(m, 0), r(m, 0), q(m, 0);
	forn (i, m) {
		cin >> l[i] >> r[i] >> q[i];
		l[i]--;
		r[i]--;
		neww(l[i] + szz, r[i] + szz, q[i]);
	}
	forn (i, szz) {
		seg2[i + szz] = 0;
		int k = i + szz;
		while (k) {
			seg2[i + szz] |= seg[k];
			k /= 2;
		}
	}
	for (int i = szz - 1; i; i--)
		seg2[i] = (seg2[2 * i] & seg2[2 * i + 1]);
	forn (i, m) {
		if (get_(l[i] + szz, r[i] + szz) != q[i]) {
			cout << "NO\n";
			re 0;
		}
	}
	cout << "YES\n";
	forn (i, n)
		cout << seg2[i + szz] << " ";
	re 0;
}