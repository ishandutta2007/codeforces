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

map<pi, int> m;
vi G[100005];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	V<pi> e;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
		e.EB(u, v);
	}
	int s = 0;
	for(int i=1;i<=n;i++) {
		if(G[i].size() >= 3) {
			s = i;
			break;
		}
	}
	if(!s) {
		for(int i=0;i<n-1;i++) cout << i << endl;
		return 0;
	}
	int cnt = 0;
	for(int v:G[s]) {
		m[MP(s, v)] = m[MP(v, s)] = cnt++;		
	}
	for(int u=1;u<=n;u++) {
		for(int v:G[u]) {
			if(!m.count(MP(u, v))) {
				m[MP(u, v)] = m[MP(v, u)] = cnt++;
			}
		}
	}
	for(int i=0;i<n-1;i++)
		cout << m[MP(e[i].F, e[i].S)] << endl;

	
}