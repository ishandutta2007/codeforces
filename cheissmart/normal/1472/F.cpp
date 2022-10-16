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

bool solve() {
	int n, m;
	cin >> n >> m;
	map<int, vi> mp;
	for(int i = 0; i < m; i++) {
		int r, c;
		cin >> r >> c;
		mp[c].PB(r);
	}
	int state = 0;
	// 1: r + c even
	// 2: r + c odd
	for(auto p:mp) {
		if(p.S.size() == 2) {
			if(state != 0) return false;
			continue;
		}
		int c = p.F, r = p.S[0];
		if(state == 0) {
			if((r + c) % 2 == 0) state = 2;
			else state = 1;
		} else {
			int now = (r + c) % 2 ? 2 : 1;
			if(now != state) return false;
			state = 0;
		}
	}
	return state == 0;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}

	
}