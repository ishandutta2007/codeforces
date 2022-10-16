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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	V<vi> v(n + 1, vi(26));
	s = ' ' + s;
	for(int i=1;i<=n;i++) {
		v[i] = v[i-1];
		v[i][s[i]-'a']++;
	}
	vi ans(26);
	while(m--) {
		int tt;
		cin >> tt;
		for(int i=0;i<26;i++)
			ans[i] += v[tt][i];
	}
	for(int i=0;i<26;i++)
		ans[i] += v[n][i];
	for(int i=0;i<26;i++) cout << ans[i] << " ";
	cout << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();	
	
}