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

const int INF = 1e9 + 7, N = 5005;

int l[N], r[N];

void pre() {
	for(int n=1;n<N;n++) {
		int depth = 0, ccc = 0;
		for(int i = 1; i <= n; i *= 2, ccc++) {
			int num = min(i * 2 - 1, n) - i + 1;
			depth += num * ccc;
		}
		l[n] = depth, r[n] = n * (n - 1) / 2;
	}
}

int p[N], cnt;
vi G[N];

void dfs(int u, int pa = 0) {
	p[u] = pa;
	for(int v:G[u]) if(v != pa && v != -1)
		dfs(v, u);
}

int go(int n, int d) {
	if(n == 0) return -1;
	if(n == 1) return cnt++;
	// if(d == r[n]) {
	// 	int cur = cnt++, ptr = cur;
	// 	for(int i=0;i<n-1;i++) {
	// 		G[ptr].PB(cnt);
	// 		ptr = cnt++;
	// 	}
	// 	return cur;
	// }
	int cur = cnt++;
	n--;
	d -= n;
	for(int ln = 0; ln <= n; ln++) {
		int rn = n - ln;
		if(l[ln] + l[rn] <= d && d <= r[ln] + r[rn]) {
			int ld, rd;
			if(l[ln] + r[rn] >= d) {
				ld = l[ln];
				rd = d - ld;
			} else {
				rd = r[rn];
				ld = d - rd;
			}
			G[cur].PB(go(ln, ld));
			G[cur].PB(go(rn, rd));
			break;
		}
	}
	return cur;
}

void solve() {
	int n, d;
	cin >> n >> d;
	if(d < l[n] || d > r[n]) {
		cout << "NO" << endl;
		return;
	}
	for(int i=1;i<=n;i++) G[i].clear();
	cnt = 1;
	go(n, d);
	dfs(1);
	cout << "YES" << endl;
	for(int i=2;i<=n;i++) cout << p[i] << " ";
	cout << endl;
	
}


signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	pre();
	while(t--) solve();
	
}