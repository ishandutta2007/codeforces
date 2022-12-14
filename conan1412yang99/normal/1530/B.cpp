#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
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
		int n, m;
		cin >> n >> m;
		V<vi> ans(n, vi(m));
		for(int i = 0; i < m; i += 2)
			ans[0][i] = 1;
		for(int i = 2; i < n; i += 2)
			ans[i][m - 1] = 1;
		for(int i = m - 3; i >= 0; i -= 2)
			ans[n - 1][i] = 1;
		for(int i = n - 3; i >= 2; i -= 2)
			ans[i][0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++)
				cout << ans[i][j];
			cout << '\n';
		}
	}
	
}