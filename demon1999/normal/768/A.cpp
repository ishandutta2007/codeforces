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

int n,  mi, ma;
vector<int> a;
int main() {
	iostream::sync_with_stdio(0);
//	freopen("a.in", "r", stdin);
	cin >> n;
	a.resize(n);
	cin >> a[0];
	mi = ma = a[0];
	forn (i, n - 1) {
		cin >> a[i + 1];
		mi = min(mi, a[i + 1]);
		ma = max(ma, a[i + 1]);
	}
	int ans = 0;
	forn (i, n) {
		if (a[i] != mi && a[i] != ma) ans++;
	}
	cout << ans;
}