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

void solve() {
	int n;
	cin >> n;
	V<vi> a(n, vi(5));
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < 5; j++)
			cin >> a[i][j];
	auto better = [&] (int i, int j) {
		int cnt = 0;
		for(int k = 0; k < 5; k++)
			if(a[i][k] < a[j][k])
				cnt++;
		return cnt >= 3;
	};
	int who = 0;
	for(int i = 1; i < n; i++) {
		if(better(i, who)) {
			who = i;
		}
	}
	for(int i = 0; i < n; i++) if(i != who)
		if(better(i, who)) {
			cout << -1 << '\n';
			return;
		}
	cout << who + 1 << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}