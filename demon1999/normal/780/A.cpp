#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int ma = 128 * 1024;
const ll mod = ll(1e9) + 7;
const int N = 5 * 100 * 1000;

int n, a[N];
vector<int> e[N];


int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	int k = 0, ans = 0;
	cin >> n;
	forn (i, 2 * n) {
		int p;
		cin >> p;
		p--;
		a[p]++;
		if (a[p] == 2) {
			k--;
			a[p] = 0;
		} else 
		k++;
		ans = max(ans, k);
	}
	cout << ans << '\n';

}