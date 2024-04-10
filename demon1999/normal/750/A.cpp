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
	int n, k;
	cin >> n >> k;
	k = 240 - k;
	for (int i = 1; i <= n; i++) {
		if (k < 5 * i) {
			cout << i - 1;
			re 0;
		}
		k -= 5 * i;
	}
	cout << n;
	re 0;
}