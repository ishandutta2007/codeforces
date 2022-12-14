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

const int INF = 1e9 + 7, N = 5003;

bool ok[N][N];

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) ok[i][j] = 0;
	for(int i=0;i<n;i++) ok[i][i] = 1;
	for(int i=0;i<n-1;i++) if(s[i] == s[i+1]) ok[i][i+1] = 1;
	for(int len = 3; len <= n; len++) {
		for(int i=0;i+len-1<n;i++) {
			int j = i + len - 1;
			if(s[i] == s[j]) ok[i][j] = ok[i+1][j-1];
		}
	}
	string ans = "";
	for(int i=0;i<=n/2;i++) {
		int l = i, r = n - i - 1;
		int len = i * 2, mid = 0, midlen = 0, left = 1;
		for(int j=l;j<=r;j++) {
			if(ok[l][j] && j - l + 1 > midlen) {
				midlen = j - l + 1;
				mid = j;
			}
		}
		for(int j=l;j<=r;j++) {
			if(ok[j][r] && r - j + 1 > midlen) {
				midlen = r - j + 1;
				mid = j;
				left = 0;
			}
		}
		len += midlen;
		if(len > (int)ans.size()) {
			string t;
			t += s.substr(0, i);
			if(midlen) {
				if(left) {
					t += s.substr(l, midlen);
				} else {
					t += s.substr(mid, midlen);
				}
			}
			if(i) t += s.substr(n - i);
			ans = t;
		}
		if(i < n / 2) if(s[i] != s[n-1-i]) break;
	}
	cout << ans << endl;
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