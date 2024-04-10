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

vector<pi> G[500005];
int t[2000006], vis[500005], n, ans[500005], bit[500005];
vi tp;

int lowbit(int x) {
	return x & -x;
}

int query(int x) {
	int ret = 0;
	while(x) {
		ret += bit[x];
		x -= lowbit(x);
	}
	return ret;
}
int query(int l, int r) {
	return query(r) - query(l-1);
}

void add(int x, int v) {
	while(x < 500005) {
		bit[x] += v;
		x += lowbit(x);
	}
}

void bld(int v = 1, int tl = 1, int tr = n) {
	if(tl == tr) {
		t[v] = tl;
	} else {
		int tm = (tl + tr) / 2;
		bld(v*2, tl, tm);
		bld(v*2+1, tm+1, tr);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}

void upd(int pos, int v = 1, int tl = 1, int tr = n) {
	if(tl == tr) {
		t[v] = 0;
	} else {
		int tm = (tl + tr) / 2;
		if(pos <= tm)
			upd(pos, v*2, tl, tm);
		else
			upd(pos, v*2+1, tm+1, tr);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}

int qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if(l > r) return 0;
	if(l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return max(qry(l, min(r, tm), v*2, tl, tm),
			   qry(max(l, tm+1), r, v*2+1, tm+1, tr));
}

bool dfs(int u) {
	vis[u] = 1;
	upd(u);
	add(u,1);
	for(pi p:G[u]) {
		while(true) {
			int v = qry(p.F, p.S);
			if(query(p.F, p.S))
				return false;
			if(v) {
				if(!dfs(v))
					return false;	
			} else
				break;
		}
	}
	add(u,-1);
	tp.PB(u);
	return true;
}

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		tp.clear();
		memset(vis, 0, sizeof vis[0] * (n + 1));
		memset(bit, 0, sizeof bit[0] * (n + 1));
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<=n;i++) {
			int nxt;
			cin >> nxt;
			if(nxt != -1) {
				G[i].EB(i+1, nxt-1);
				G[nxt].EB(i, i);
			}
		}
		bld();
		int noans = 0;
		for(int i=1;i<=n;i++) {
			if(!vis[i] && !dfs(i)) {
				noans = 1;
				break;
			}
		}
		if(noans) {
			cout << -1 << endl;
			continue;
		}
		for(int i=0;i<tp.size();i++)
			ans[tp[i]] = i + 1;
		for(int i=1;i<=n;i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	
}