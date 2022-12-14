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
		int n;
		cin >> n;
		vi a(n);
		int cnt[2] = {};
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] %= 2;
			cnt[a[i]]++;
		}
		if(abs(cnt[0] - cnt[1]) > 1) {
			cout << -1 << '\n';
			continue;
		}
		auto go = [&] (int first) -> ll {
			ll ans = 0, has = 0;
			for(int i = 0; i < n; i++) {
				int x = a[i] ^ first;
				if(x == 0) {
					ans += abs(has - i / 2);
				} else {
					ans += abs(i - has - (i + 1) / 2);
				}
				has += x;
			}
			return ans;
		};
		if(n & 1) {
			if(cnt[0] > cnt[1])
				cout << go(0) << '\n';
			else 
				cout << go(1) << '\n';
		} else {
			cout << min(go(0), go(1)) << '\n';
		}
	}


}