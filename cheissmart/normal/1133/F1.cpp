#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vi G[200005];
bool vis[200005];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int mxd = 0, v;
	for(int i=1;i<=n;i++) {
		if(G[i].size() > mxd) {
			mxd = G[i].size();
			v = i;
		}
	}
	vi q;
	q.PB(v);
	vis[v] = 1;
	for(int i=0;i<q.size();i++) {
		int u = q[i];
		for(int w:G[u]) {
			if(!vis[w]) {
				q.PB(w);
				vis[w] = 1;
				cout << u << " " << w << endl;
			}
		}
	}
}