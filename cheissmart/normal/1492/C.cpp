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

	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vi l(m), r(m);
	for(int i = 0, j = 0; i < n && j < m; i++) {
		if(s[i] == t[j]) {
			l[j] = i;
			j++;
		}
	}
	for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
		if(s[i] == t[j]) {
			r[j] = i;
			j--;
		}
	}
	int ans = 0;
	for(int i = 0; i < m - 1; i++) {
		ans = max(ans, r[i + 1] - l[i]);
	}
	cout << ans << '\n';

}