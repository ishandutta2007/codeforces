#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	y = min(y, x * 2);
	int ans = 0;
	for(int j = 0; j < n; j++) {
		string s;
		cin >> s;
		for(int i = 0; i < m;) {
			while(i < m && s[i] == '*') i++;
			if(i == m) continue;
			int j = i;
			while(i < m && s[i] == '.') i++;
			int tt = i - j;
			ans += tt / 2 * y + (tt % 2) * x;
		}
	}
	cout << ans << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();	
	
}