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

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int cnt[26] = {};
		for(char c:s) {
			cnt[c - 'a']++;
		}
		int ans = 0;
		for(int t = 1; t <= n; t++) {
			for(int g = 1; g <= n; g++) {
				if(k % g) continue;
				if(__gcd(k/g, t) != 1) continue;
				int tt = 0;
				for(int i = 0; i < 26; i++) tt += cnt[i] / t;
				if(tt >= g) ans = max(ans, g * t);
			}
		}
		cout << ans << endl;
	}	
	
}