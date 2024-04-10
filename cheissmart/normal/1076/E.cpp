#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int t[1200001], dp[300005], ans[300005], n;
vi G[300005];
vector<pi> in[300005];

void bld(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        bld(a, v*2, tl, tm);
        bld(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int qry(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return qry(v*2, tl, tm, l, min(r, tm))
           + qry(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void upd(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            upd(v*2, tl, tm, pos, new_val);
        else
            upd(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void dfs(int u, int p, int d) {
	dp[u] = d;
	for(pi& p:in[u])  {
		p.F = min(dp[u]+p.F,n-1);
		upd(1, 0, n, p.F, p.S);
	}
	ans[u] = qry(1,0,n,d,n);
	for(auto& v : G[u]) {
		if(v != p) {
			dfs(v, u, d+1);
		}
	}
	for(pi& p:in[u])  {
		upd(1, 0, n, p.F, -p.S);
	}
}

int32_t main()
{
	IO_OP;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int q;
	cin >> q;
	while(q--) {
		int v, d, x;
		cin >> v >> d >> x;
		in[v].PB({d, x});
	}
	dfs(1, -1, 0);
	for(int i=1;i<=n;i++)
		cout << ans[i] << ' ';
}