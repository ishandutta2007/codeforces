#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	set<int> s;
	V<pi> ans, stk;
	stk.EB(INF, -INF);
	for(int i = 0; i < 2 * n; i++) {
		char c;
		cin >> c;
		if(c == '+') s.insert(i);
		else {
			int x;
			cin >> x;
			while(stk.size() && stk.back().F < x) stk.pop_back();
			assert(stk.size());
			int pos = stk.back().S;
			stk.EB(x, i);
			auto it = s.upper_bound(pos);
			if(it == s.end()) return cout << "NO" << endl, 0;
			ans.EB(*it, x);
			s.erase(it);
		}
	}
	sort(ALL(ans));
	cout << "YES" << endl;
	for(pi p:ans) cout << p.S << " ";
	cout << endl;

}