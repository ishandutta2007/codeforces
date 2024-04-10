#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl


using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vi G[1024];
int isx[1024], isy[1024], x[1024], y[1024];

int dfs(int u, int p = -1) {
	if(isx[u]) return u;
	for(int v:G[u]) {
		if(v != p) {
			int t = dfs(v, u);
			if(t != -1)
				return t;
		}
	}
	return -1;
}

void solve() {
	memset(isx, 0, sizeof isx);
	memset(isy, 0, sizeof isy);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=0;i<n-1;i++) {
		int a, b;
		cin >> a >> b;
		G[a].PB(b);
		G[b].PB(a);
	}
	int k1, k2;
	cin >> k1;
	for(int i=0;i<k1;i++) {
		cin >> x[i];
		isx[x[i]] = 1;
	}
	cin >> k2;
	for(int i=0;i<k2;i++) {
		cin >> y[i];
		isy[y[i]] = 1;
	}
	cout << "B " << y[0] << endl;
	int r;
	cin >> r;
	if(isx[r]) {
		cout << "C " << r << endl;
		return;
	}
	int t = dfs(r);
	cout << "A " << t << endl;
	cin >> r;
	if(isy[r]) {
		cout << "C " << t << endl;
		return;
	}
	cout << "C " << -1 << endl;
}

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;	
	while(t--) {
		solve();
	}
}