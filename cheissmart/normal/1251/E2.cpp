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

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];

void solve() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int m, p;
		cin >> m >> p;
		G[m].PB(p);
	}
	int pre = n, cnt = 0, ans = 0;
	multiset<int> s;
	for(int i = n - 1; i >= 0; i--) {
		if(G[i].empty()) continue;
		pre -= G[i].size();
		int need = i - pre - cnt;
		for(int j : G[i]) s.insert(j);
		while(need-- > 0) {
			ans += *s.begin();
			s.erase(s.begin());
			cnt++;
		}
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++) G[i].clear();

}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();	
	
}