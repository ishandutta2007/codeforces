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

	int t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		// k <= 2 ^ (n - 1)
		if(n - 1 < 60 && k > 1LL << (n - 1)) {
			cout << -1 << '\n';
			continue;
		}
		k--;
		vi v;
		for(int i = 0; i < n - 1; i++) {
			int bit = min(n - i - 2, 63LL);
			if((k >> bit & 1) == 0) v.PB(i + 1);
		}
		v.PB(n);
		int p = 0;
		for(int i:v) {
			cout << i << ' ';
			for(int j = i - 1; j > p; j--) cout << j << ' ';
			p = i;
		}
		cout << '\n';
	}

}