#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];

		int pos = min_element(ALL(a)) - a.begin();
		auto he = [&] (int pos) {
			vi mn(n), mx(n);
			for(int i = 0; i < n; i++) {
				mn[i] = mx[i] = i;
				if(i && a[mn[i - 1]] < a[i])
					mn[i] = mn[i - 1];
				if(i && a[mx[i - 1]] > a[i])
					mx[i] = mx[i - 1];
			}
			int u = pos, ans = 0;
			while(u != 0) {
				assert(mn[u] == u || mx[u] == u);
				if(mn[u] == u) {
					u = mx[u];
				} else {
					u = mn[u];
				}
				ans++;
			}
			return ans;
		};
		auto be = [&] (int pos) {
			vi mn(n), mx(n);
			for(int i = n - 1; i >= 0; i--) {
				mn[i] = mx[i] = i;
				if(i + 1 < n && a[mn[i + 1]] < a[i])
					mn[i] = mn[i + 1];
				if(i + 1 < n && a[mx[i + 1]] > a[i])
					mx[i] = mx[i + 1];
			}
			int u = pos, ans = 0;
			while(u != n - 1) {
				assert(mn[u] == u || mx[u] == u);
				if(mn[u] == u) {
					u = mx[u];
				} else {
					u = mn[u];
				}
				ans++;
			}
			return ans;
		};
		cout << he(pos) + be(pos) << '\n';
	}

}