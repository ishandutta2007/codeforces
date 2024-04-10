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
int vis[200005];

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		vi a, b;
		int n, m;
		cin >> n >> m;
		for(int i=0;i<m;i++) {
			int u, v;
			cin >> u >> v;
			G[u].PB(v);
			G[v].PB(u);
		}
		
		vi v({1});
		vis[1] = 1;
		for(int i=0;i<v.size();i++) {
			if(vis[v[i]] == 1)
				a.PB(v[i]);
			else 
				b.PB(v[i]);
			for(int u:G[v[i]]) {
				if(!vis[u]) {
					vis[u] = vis[v[i]] ^ 3;
					v.PB(u);
				}
			}
		}
		if(a.size() > b.size()) swap(a, b);
		cout << a.size() << endl;
		for(int u:a)
			cout << u << " ";
		cout << endl;
		for(int i=1;i<=n;i++) {
			G[i].clear();
			vis[i] = 0;
		}
	
	}
}