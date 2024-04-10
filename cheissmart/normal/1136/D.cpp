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

vi G[300005];
int a[300005];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for(int i=0;i<n;i++) cin >> a[i];
	set<pi> s;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		s.insert(MP(u, v));
		G[v].PB(u);
	}
	map<int, int> mp;
	int ct = 0, ans = 0;
	for(int i=n-2;i>=0;i--) {
		if(s.count(MP(a[i], a[n-1])) && mp[a[i]] == ct) {
			ans++;
			continue;
		}
		ct++;
		for(int j:G[a[i]]) mp[j]++;
	}
	cout << ans << endl;
	
}