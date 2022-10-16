#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;
const int N = 150000 + 87;

int p[N], h[N], nxt[N];
vi G[N];

void dfs(int u) {
	cout << u << " ";
	for(int v:G[u]) {
		dfs(v);
	}
}

void init(int n) {
	for(int i=1;i<=n;i++)
		p[i] = i;
}

int find(int x) {
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
} 

void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	if(h[x] > h[y]) {
		p[ry] = rx;
		G[rx].PB(ry);
	} else if (h[y] > h[x]) {
		p[rx] = ry;
		G[ry].PB(rx);
	} else {
		p[ry] = rx;
		h[rx]++;
		G[rx].PB(ry);
	}
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	init(n);
	vi ans;
	for(int i=0;i<n-1;i++) {
		int x, y;
		cin >> x >> y;
		unite(x, y);
	}
	int r = find(1);
	dfs(r);
}