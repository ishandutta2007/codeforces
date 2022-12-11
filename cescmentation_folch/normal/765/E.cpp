#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi M;
vi m;

int inf1 = 1e6;

void dfs(int x, int p) {
    m[x] = inf1;
    M[x] = 0;
    for (int i = 0; i < (int)G[x].size(); ++i) {
	int y = G[x][i];
	if (y == p) continue;
	dfs(y, x);
	m[x] = min(m[x], m[y] + 1);
	M[x] = max(M[x], M[y] + 1);
    }
    if (m[x] == inf1) m[x] = 0;
}

int res;

int div(int x) {
    while (x%2 == 0) x /= 2;
    return x;
}

void dfs2(int x, int p, int d) {
//     cerr << x << ' ' << d << endl;
    int mid = (int)G[x].size() + 1;
    
    int M1[mid];
    int m1[mid];
    int t = 0;
    for (int i = 0; i < (int)G[x].size(); ++i) {
	int y = G[x][i];
	if (y == p) continue;
	M1[t] = M[y] + 1;
	m1[t] = m[y] + 1;
	if (t != 0) {
	    M1[t] = max(M1[t - 1], M1[t]);
	    m1[t] = min(m1[t - 1], m1[t]);
	}
	++t;
    }
    
    int M2[mid];
    int m2[mid];
    bool tt = true;
    set<int>S;
    if (d != 0) S.insert(d);
    mid -= 3;
    if (x == 0) ++mid;
    t = mid;
    for (int i = (int)G[x].size() - 1; i >= 0; --i) {
	int y = G[x][i];
	if (y == p) continue;
	M2[t] = M[y] + 1;
	m2[t] = m[y] + 1;
	if (M2[t] != m2[t]) tt = false;
	else S.insert(M2[t]);
	if (t != mid) {
	    M2[t] = max(M2[t + 1], M2[t]);
	    m2[t] = min(m2[t + 1], m2[t]);
	}
	--t;
    }

    if (mid < 0) res = min(res, div(d));
    else if (tt and S.size() == 1) res = min(res, div(*S.begin()));
    else if (tt and S.size() == 2) {
	int kk = 0;
	for (auto it : S) kk += it;
	res = min(res, div(kk));
    }
    
    t = 0;
    for (int i = 0; i < (int)G[x].size(); ++i) {
	int y = G[x][i];
	if (y == p) continue;
	int tt1 = -2, tt2 = -3;
	if (t == 0) tt1 = -1;
	else if (M1[t - 1] == m1[t - 1]) tt1 = m1[t - 1];
	if (t == mid) tt2 = -1;
	else if (M2[t + 1] == m2[t + 1]) tt2 = m2[t + 1];
	if (tt1 == tt2 or (tt1 == -1 and tt2 != -3) or ( tt1 != -2 and tt2 == -1)) {
	    int kk = tt1;
	    if (kk == -1) kk = tt2;
	    if (d == 0 or kk == -1 or kk == d) {
		int rr = max(kk, d);
// 		cerr << y << ' ' << tt1 << ' ' << tt2 << ' ' << t << ' ' << mid << endl;
		dfs2(y, x, rr + 1);
	    }
	}
	++t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    G = vvi(n);
    M = m = vi(n);
    for (int i = 0; i < n - 1; ++i) {
	int x, y;
	cin >> x >> y;
	--x;
	--y;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(0, -1);
    res = inf1;
    dfs2(0, -1, 0);
    if (res == inf1) cout << -1 << endl;
    else cout << res << endl;
}