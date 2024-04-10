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

int out[100005];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		out[u] += w;
		out[v] -= w;
	}
	V<pi> topay;
	for(int i=1;i<=n;i++) {
		if(out[i] < 0) {
			topay.EB(i, -out[i]);
		}
	}
	V<pair<pi, int>> ans;
	for(int i=1;i<=n;i++) {
		while(out[i] > 0) {
			int pay = min(topay.back().S, out[i]);
			out[i] -= pay;
			topay.back().S -= pay;
			ans.PB({{i, topay.back().F},pay});
			if(topay.back().S == 0) topay.pop_back();
		}
	}
	cout << ans.size() << endl;
	for(auto e:ans)
		cout << e.F.F << " " << e.F.S << " " << e.S << endl;
	
	
}