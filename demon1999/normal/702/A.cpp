#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define x first
#define y second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<int> a;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	a.resize(n);
	forn (i, n)
		cin >> a[i];
	int k = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] <= a[i - 1]) k = 0;
		k++;
		ans = max(ans, k);
 	}
 	cout << ans;
 	re 0;
}