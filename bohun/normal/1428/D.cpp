#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using ld = long double;
using namespace std;	

const int N = 1e5 + 500;

int n, a[N], space;
vector <pair<int, int>> ans, one, two, three;

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", a + i);
	per(i, 1, n) {
		if (!a[i]) continue;
		if (a[i] == 1) {
			space++;
			ans.pb({i, space});
			one.pb({i, space});
		}
		if (a[i] == 3) {
			if (!sz(one) && !sz(two) && !sz(three)) return !printf ("-1\n");
			int x;
			if (sz(three)) {
				x = three.back().fi;
				three.pop_back();
			}
			else if (sz(two)) {
				x = two.back().fi;
				two.pop_back();
			}
			else {
				x = one.back().fi;
				one.pop_back();
			}
			space++;
			ans.pb({i, space});
			ans.pb({x, space});
			three.pb({i, space});
		}
		if (a[i] == 2) {
			if (!sz(one)) return !printf ("-1\n");
			auto [x, y] = one.back();
			one.pop_back();
			ans.pb({i, y});	
			two.pb({i, y});
		}
	}
	printf ("%d\n", sz(ans));
	for (auto [x, y] : ans)
		printf ("%d %d\n", n - y + 1, x);
	
	return 0;
}