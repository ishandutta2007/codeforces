#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int tin[100005];

struct s{
	int mx1, mx2;
	int mn1, mn2;
	s operator+(const s t) const{
		vi mxs, mns;
		if(mx1) mxs.PB(mx1);
		if(mx2) mxs.PB(mx2);
		if(t.mx1) mxs.PB(t.mx1);
		if(t.mx2) mxs.PB(t.mx2);
		sort(mxs.begin(), mxs.end(), [&](int i, int j)->bool{return tin[i] > tin[j];});
		s res = {0, 0, 0, 0};
		res.mx1 = mxs[0];
		if(mxs.size() > 1) res.mx2 = mxs[1];
		if(mn1) mns.PB(mn1);
		if(mn2) mns.PB(mn2);
		if(t.mn1) mns.PB(t.mn1);
		if(t.mn2) mns.PB(t.mn2);
		sort(mns.begin(), mns.end(), [&](int i, int j)->bool{return tin[i] < tin[j];});
		res.mn1 = mns[0];
		if(mns.size() > 1) res.mn2 = mns[1];
		return res;
	}
};

vi G[100005], d;
int p[21][100005], de[100005];
s t[400005];

s qry(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {0,0,0,0};
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return qry(v*2, tl, tm, l, min(r, tm))
           + qry(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void upd(int v, int tl, int tr, int pos, s new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            upd(v*2, tl, tm, pos, new_val);
        else
            upd(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void dfs(int u) {
	d.PB(u);
	tin[u] = d.size();
	for(auto& v : G[u]) {
		p[0][v] = u;
		de[v] = de[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v) {
	if(de[u] > de[v])
		swap(u, v);
	for(int k = 20;k>=0;k--) {
		if(de[v] - de[u] >= (1<<k))
			v = p[k][v];
	}
	if(u == v) return u;
	for(int k = 20;k>=0;k--) {
		if(p[k][u] != p[k][v]) {
			u = p[k][u];
			v = p[k][v];
		}
	}
	return p[0][u];
}

int main()
{
	IO_OP;

	int n, q;
	cin >> n >> q;
	for(int i=2;i<=n;i++) {
		int u;
		cin >> u;
		G[u].PB(i);
	}
	dfs(1);
	for(int i=1;i<20;i++) {
		for(int j=2;j<=n;j++) {
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}
	for(int i=1;i<=n;i++) {
		upd(1, 1, n, i, {i, 0, i, 0});
	}
	// for(int i=1;i<=n;i++)
	// 	cout << de[i] << endl;
	while(q--) {
		int l, r;
		cin >> l >> r;
		s res = qry(1, 1, n, l, r);
		int mx1 = res.mx1, mx2 = res.mx2, mn1 = res.mn1, mn2 = res.mn2;
		pi ans = max(MP(de[lca(mx1, mn2)], mn1), MP(de[lca(mx2, mn1)], mx1));
		// cout << lca(mx1, mn2) << "  (" << mx1 << ", " << mn2 << ") " << mn1 << endl;
		// cout << lca(mx2, mn1) << "  (" << mx2 << ", " << mn1 << ") " << mx1 << endl;
		cout << ans.S << " " << ans.F << endl;
	}
}