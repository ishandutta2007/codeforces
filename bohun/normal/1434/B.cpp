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

const int N = 1e5 + 50;

vector <int> groups[N];
int n, a, ans[N], sz, p[N], val[N];
char c;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	p[x] = y;
	for (auto z : groups[x])
		groups[y].pb(z);
}

set <pair<int, int>> S;

int main() {
	scanf ("%d", &n);
	rep(i, 1, 2 * n) {
		scanf (" %c", &c);
		if (c == '+') {
			++sz;
			p[sz] = sz;
			val[sz] = 0;
			groups[sz] = {sz};
			S.insert(mp(0, sz));
		}
		else {
			int x;
			scanf ("%d", &x);
			auto it = S.upper_bound(mp(x, 1 << 30));
			if (it == S.begin()) return !printf ("NO\n");
			it--;
			
			int id = it->se;
			int f = groups[id].back();
			ans[f] = x;
			groups[id].pop_back();
			if (groups[id].empty()) 
				S.erase(it);
			
			vector <int> a;
			while (!S.empty() && S.begin()->fi <= x) {
				a.pb(S.begin()->se);
				S.erase(S.begin());
			}
			
			int big = -1;
			for (auto z : a)
				if (big == -1 || sz(groups[z]) > sz(groups[big]))
					big = z;
			if (big == -1) continue;
			val[big] = x;
			S.insert(mp(x, big));
			for (auto z : a)
				if (big != z)
					unite(z, big);
		}
	}
	printf ("YES\n");
	rep(i, 1, n)
		printf ("%d ", ans[i]);
	return 0;
}