#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 2e5+5;

int x[N], y[N];

set<int> G[N];
int ans[N];
int verts, n, m, k;
bool out[N];

void update(int i) {
	if(out[i]) return;
	if(G[i].size() < k) {
		--verts;
		out[i] = true;
		for(int x : G[i]) {
			G[x].erase(i);
			update(x);
		}
	}
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i];
		G[x[i]].insert(y[i]);
		G[y[i]].insert(x[i]);
	}
	verts = n;
	for(int i = 1; i <= n; ++i)
		update(i);

	for(int i = m-1; i >= 0; --i) {
		ans[i] = verts;
		G[x[i]].erase(y[i]);
		G[y[i]].erase(x[i]);
		update(x[i]);
		update(y[i]);
	}
	for(int i = 0; i < m; ++i) {
		cout << ans[i] << "\n";
	}
}