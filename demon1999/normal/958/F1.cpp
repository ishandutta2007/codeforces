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
typedef unsigned long long ull;
const ll ma = 128 * 1024;


int n, m;
vector<int> a, k;

int main() {
	iostream::sync_with_stdio(0);
	cin >> n >> m;
	a.resize(n);
	k.resize(m);
	forn (i, n) {
		cin >> a[i];
		a[i]--;
	}
	forn (i, m) cin >> k[i];
	forn (i, n) {
		vector<int> cnt(m, 0);
		for (int j = i; j < n; j++) {
			cnt[a[j]]++;
			bool ok = true;
			forn (q, m)
				if (cnt[q] != k[q]) ok = false;
			if (ok) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}