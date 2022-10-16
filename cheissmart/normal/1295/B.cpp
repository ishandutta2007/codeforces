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

int solve() {
	int n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	int c = 0;
	map<int, int> cnt;
	for(int i=0;i<n;i++) {
		if(s[i] == '0') c++;
		else c--;
		cnt[c]++;
	}
	if(c == 0) {
		if(x == 0) return -1;
		if(cnt[x] == 0) return 0;
		else return -1;
	}
	int ans = 0;
	for(pi p:cnt) {
		int r = x - p.F;
		if(r % c == 0 && r / c >= 0) {
			ans += p.S;
		}
	}
	if(x == 0) ans++;
	return ans;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		cout << solve() << endl;
	}

}