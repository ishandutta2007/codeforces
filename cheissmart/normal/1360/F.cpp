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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int diff(string s, string t) {
	int ans = 0;
	for(int i = 0; i < s.size(); i++)
		if(s[i] != t[i])
			ans++;
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;
	V<string> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < m; i++) {
		string s;
		for(char c = 'a'; c <= 'z'; c++) {
			s = v[0];
			s[i] = c;
			bool ok = 1;
			for(int j = 0; j < n; j++) {
				if(diff(v[j], s) > 1) {
					ok = 0;
					break;
				}
			}
			if(ok) {
				cout << s << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
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