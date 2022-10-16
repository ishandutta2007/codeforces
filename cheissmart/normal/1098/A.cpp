#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N =1e5 + 87;

int p[N], s[N], a[N];
vi G[N];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=2;i<=n;i++) {
		cin >> p[i];
		G[p[i]].PB(i);
	}
	for(int i=1;i<=n;i++)
		cin >> s[i];
	a[1] = s[1];
	for(int i=2;i<=n;i++) {
		if(s[i] == -1) {
			if(G[i].size() == 0) continue;
			int mn = INF;
			for(int u:G[i])
				mn = min(mn, s[u]);
			s[i] = mn;
		}
		a[i] = s[i] - s[p[i]];
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(a[i] < 0) {
			cout << -1 << endl;
			return 0;
		}
		ans += a[i];
	}
	cout << ans << endl;
	
}