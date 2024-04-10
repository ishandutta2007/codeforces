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

const int INF = 1e9 + 7, N = 200005;

int d[N][2], a[N], n;
bool vis[N];
vi G[N];

void BFS(vi & v, int p) {
	memset(vis, 0, sizeof vis);
	for(int u:v)
		vis[u] = true, d[u][p] = 0;
	for(int i=0;i<v.size();i++) {
		int u = v[i];
		for(int w:G[u])
			if(!vis[w]) {
				vis[w] = true;
				d[w][p] = d[u][p] + 1;
				v.PB(w);
			}
	}
}

signed main()
{
	IO_OP;
	
	cin >> n;
	vi x, y;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i]&1) x.PB(i);
		else y.PB(i);
	}
	for(int i=1;i<=n;i++) {
		int l = i - a[i], r = i + a[i];
		if(l >= 1) G[l].PB(i);
		if(r <= n) G[r].PB(i);
	}
	memset(d, 0xff, sizeof d);
	BFS(x,1);
	BFS(y,0);
	for(int i=1;i<=n;i++) {
		int p = !(a[i] & 1);
		cout << d[i][p] << " ";
	}
}