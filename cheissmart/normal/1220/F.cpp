#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], b[N], n;
pi st[N][20];

pi qry(int l, int r) {
	int k = __lg(r - l);
	return min(st[l][k], st[r-(1<<k)][k]);
}

pi dfs(int l, int r) {
	if(r - l == 0) return {0, 0};
	int m = qry(l, r).S;
	pi lp = dfs(l, m), rp = dfs(m + 1, r);
	return {max(lp.F, lp.S) + 1, max(rp.F, rp.S) + 1};
}

pi go(int shift) {
	for(int i = 0; i < n; i++) b[i] = a[(i + shift) % n], st[i][0] = {b[i], i};
	for(int j = 1; j < 20; j++) {
		for(int i = 0; i + (1 << j) - 1 < n; i++) {
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
	return dfs(0, n);
}

signed main()
{
	IO_OP;

	cin >> n;
	int pos = -1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] == 1) pos = i;
	}
	int shift = (pos + 1) % n;
	int lb = 0, rb = n - 1;
	while(lb <= rb) {
		int mb = (lb + rb) / 2;
		pi p = go((shift + mb) % n);
		if(p.F >= p.S) lb = mb + 1;
		else rb = mb - 1;
	}
	pi p1 = go((shift + lb) % n), p2 = go((shift + rb) % n);
	int ans1 = max(p1.F, p1.S), ans2 = max(p2.F, p2.S);
	if(ans1 < ans2) cout << ans1 << " " << (shift + lb) % n << endl;
	else cout << ans2 << " " << (shift + rb) % n << endl;
}