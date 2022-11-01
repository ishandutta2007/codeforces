#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1000 * 1000 * 1000, mod = inf + 7, kkk = 10, ss = 8 * 1024;

int n, ans[10000], k[10000];
vector<int> a;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	cin >> n;
	a.resize(n);
	forn (i, n) {		
		cin >> a[i];
		a[i]--;
	}
	forn (i, n) {
		k[a[i]]++;
		int nu = a[i];
		for (int j = i; j < n; j++) {
			ans[nu]++;
			if (j + 1 < n) {
				k[a[j + 1]]++;
				if (k[a[j + 1]] > k[nu] || (k[a[j + 1]] == k[nu] && nu > a[j + 1]))
					nu = a[j + 1];
			}
		}
		for (int j = i; j < n; j++)
			k[a[j]]--;
	}
	forn (i, n)
		cout << ans[i] << " ";
	re 0;
}