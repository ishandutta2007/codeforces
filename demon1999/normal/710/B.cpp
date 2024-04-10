#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	vector<ll> x;
	x.resize(n);
	forn (i, n)
		cin >> x[i];
	sort(x.begin(), x.end());
	ll sum = 0;
	forn (i, n) sum += x[i] - x[0];
	ll xa = x[0], ans = sum;
	for (int i = 1; i < n; i++) {
		sum -= ll(n - i) * ll(x[i] - x[i - 1]);
		sum += ll(i) * (x[i] - x[i - 1]);
		if (sum < ans){
			ans = sum, xa = x[i];
		}
	}
	cout << xa;
	re 0;
}