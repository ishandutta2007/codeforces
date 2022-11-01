#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int MAXN = 5 * 100 * 1000,/* ma = 128 * 1024,*/ mod = 1000 * 1000 * 1000 + 7;

int n, k, x, a[2001], b[2001];

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> k >> x;
	forn (i, n) {
		int b;
		cin >> b;
		a[b]++;
	}
	forn (i, k) {
		int cnt = 0;
		forn (i, 1024) {
			int cnt1 = a[i] / 2 + a[i] % 2, cnt2 = a[i] / 2;
			if (cnt % 2) {
				b[i ^ x] += cnt2;
				b[i] += cnt1;
			} else {
				b[i ^ x] += cnt1;
				b[i] += cnt2;
			}
			cnt += a[i];
		}
		forn (i, 1024) {
			a[i] = b[i];
			b[i] = 0;
		}
	}
	int mi = 1024, ma = 0;
	forn (i, 1024) {
		if (a[i]) {
			ma = max(ma, i);
			mi = min(mi, i);
		}
		/*forn (j, a[i])
			cout << i << " ";*/
	}
	//cout << "\n";
	cout << ma << " " << mi << "\n";
}