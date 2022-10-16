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

const int INF = 1e9 + 7, N = 1e5 + 7;

int cnt[6], dp[1 << 6], sos[1 << 6];
string can[N];

signed main()
{
	IO_OP;

	string s;
	int m, n;
	cin >> s >> m;
	n = s.size();

	for(char c:s) {
		cnt[c - 'a']++;
	}

	auto get_mask = [&] (string& s) {
		int mask = 0;
		for(char c:s)
			mask |= 1 << (c - 'a');
		return mask;
	};

	for(int i = 0; i < m; i++) {
		int pos;
		cin >> pos >> can[--pos];
		sort(ALL(can[pos]));
	}

	for(int i = 0; i < n; i++) {
		if(can[i].empty()) can[i] = "abcdef";
		int mask = get_mask(can[i]);
		dp[mask]++;
	}

	auto ok = [&] () -> bool { // Hall's theorem
		for(int i = 0; i < (1 << 6); i++) sos[i] = dp[i];
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < (1 << 6); j++)
				if(j >> i & 1)
					sos[j] += sos[j ^ (1 << i)];
		for(int i = 0; i < (1 << 6); i++) {
			int tot = 0;
			for(int j = 0; j < 6; j++) if(i >> j & 1)
				tot += cnt[j];
			if(tot > sos[(1 << 6) - 1] - sos[((1 << 6) - 1) ^ i]) {
				return false;
			}
		}
		return true;
	};

	if(!ok()) {
		cout << "Impossible\n";
		exit(0);
	}

	string ans;
	for(int i = 0; i < n; i++) {
		string& tt = can[i];
		int mask = get_mask(tt);
		char put = 'x';
		for(char c:tt) {
			cnt[c - 'a']--;
			dp[mask]--;
			if(ok()) {
				put = c;
				break;
			}
			cnt[c - 'a']++;
			dp[mask]++;
		}
		assert(put != 'x');
		ans += put;
	}
	cout << ans << '\n';

}