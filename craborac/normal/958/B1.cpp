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


int n, m, a, b, cnt[10000];

int main() {
	iostream::sync_with_stdio(0);
	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cnt[a]++;
		if (b != a) cnt[b]++;
	}
	int ans =0;
	forn (i, n)
		if (cnt[i] <= 1) ans++;
	cout << ans;
}