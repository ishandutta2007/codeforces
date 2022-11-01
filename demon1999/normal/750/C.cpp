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
const int mod = 1e9 + 7;

ll n, sum, k, l = -1e10, r = 1e10, d;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> k >> d;
	if (d == 1)
		l = 1900;
	else
		r = 1899;
	sum = k;
	ll prd;
	forn (i, n - 1) {
		cin >> k >> d;
		if (d == 1) {
			l = max(l, 1900 - sum);
		}
		else {
			r = min(r, 1899 - sum);
		}
		sum += k;
		//cout << l << " " << r << "\n";
	}
	if (l > r) {
		cout << "Impossible\n";
		re 0;
	}
	if (r == 1e10) {
		cout << "Infinity\n";
		re 0;
	}
	cout << r + sum << "\n";
	re 0;
}