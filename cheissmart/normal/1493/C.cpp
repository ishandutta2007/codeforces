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

string solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	if(n % k) return "-1";
	vi cnt(26);
	for(char c:s)
		cnt[c - 'a']++;
	bool no = false;
	for(int i = 0; i < 26; i++)
		if(cnt[i] % k)
			no = true;
	if(!no) return s;
	vi take(26);
	auto ok = [&] (int len, char at_least) {
		take = vi(26);
		int need = 0;
		for(int i = 0; i < 26; i++) {
			if(cnt[i] % k) {
				need += k - cnt[i] % k;
				take[i] = k - cnt[i] % k;
			}
		}
		if(need > len) return false;
		if((len - need) % k) return false;
		bool have = false;
		for(int i = at_least - 'a'; i < 26; i++)
			if(take[i])
				have = true;
		if(!have && len - need == 0)
			return false;
		else {
			if(len - need) {
				if(take[at_least - 'a'] == 0) {
					take[at_least - 'a'] += k;
					need += k;
				}
			}
			take[0] += len - need;
			return true;
		}
	};
	for(int i = int(s.size()) - 1; i >= 0; i--) {
		cnt[s[i] - 'a']--;
		if(s[i] != 'z' && ok(int(s.size()) - i, s[i] + 1)) {
			string ans = s.substr(0, i);
			int c = s[i] - 'a' + 1;
			for(int i = c; i < 26; i++) {
				if(take[i]) {
					take[i]--;
					ans += 'a' + i;
					break;
				}
			}
			for(int i = 0; i < 26; i++) {
				while(take[i]) {
					take[i]--;
					ans += 'a' + i;
				}
			}
			return ans;
		}
	}
	throw;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cout << solve() << '\n';
	}
	
}