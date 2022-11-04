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

int n, m, cmx = 0;
vector<int> a, k, v[2 * ma];

int main() {
	iostream::sync_with_stdio(0);
	cin >> n >> m;
	a.resize(n);
	k.resize(m);
	//pos.assign(m, 0);
	forn (i, n) {
		cin >> a[i];
		a[i]--;
		v[a[i]].push_back(i);
	}
	int cm = 0;
	forn (j, m) {
		cin >> k[j];
		cm += k[j];
		k[j]--;
		if (k[j] >= 0) {
			if (k[j] >= sz(v[j])) {
				cout << -1;
				return 0;
			}
			cmx = max(cmx, v[j][k[j]]);
		}
	}
	int ans = int(1e9);
	forn (i, n + 1) {
		ans = min(ans, cmx - i + 1 - cm);
		if (i < n) {
			if (k[a[i]] != -1) {
				k[a[i]]++;
				if (k[a[i]] >= sz(v[a[i]])) break;
				cmx = max(cmx, v[a[i]][k[a[i]]]);		
			}
		}
	}	
	cout << ans;
}