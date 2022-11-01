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

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	int k = 0;
	forn (i, n) {
		int t;
		string s;
		cin >> t >> s;
		if (s == "North") {
			if (k - t < 0) {
				cout << "NO\n";
				re 0;
			}
			k -= t;
		}
		if (s == "South") {
			if (k + t > 20000) {
				cout << "NO\n";
				re 0;
			}
			k += t;
		}
		if ((s == "East" || s == "West") && (k == 0 || k == 20000)) {
			cout << "NO\n";
			re 0;
		}
	}
	if (k != 0) {
		cout << "NO\n";
		re 0;
	}
	cout << "YES\n";
	re 0;
}