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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int p[200005], vis[200005], ans[200005];
vi s;

void dfs(int u) {
	vis[u] = 1;
	if(!vis[p[u]]) dfs(p[u]);
	s.PB(u);
}

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> p[i];

		for(int i=1;i<=n;i++) {
			if(!vis[i]) {
				dfs(i);
				int sz = s.size();
				while(s.size()) {
					ans[s.back()] = sz;
					s.pop_back();
				}
			}
		}
		for(int i=1;i<=n;i++) cout << ans[i] << " ";
		cout << endl;
		for(int i=1;i<=n;i++) vis[i] = 0;
	}
	
}