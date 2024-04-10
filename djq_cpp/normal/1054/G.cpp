#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i ++)
#define MP make_pair
typedef pair<int, int> PII;

struct my_bst
{
	unsigned long long dat[32];
	my_bst()
	{
		memset(dat, 0, sizeof(dat));
	}
	void addbit(int id)
	{
		dat[id >> 6] |= 1ull << (id & 63);
	}
	my_bst operator&(const my_bst& oth) const
	{
		my_bst ans;
		rep(i, 32) ans.dat[i] = dat[i] & oth.dat[i];
		return ans;
	}
	int do_count() const
	{
		int ans = 0;
		rep(i, 32) ans += __builtin_popcountll(dat[i]);
		return ans;
	}
};
struct dsu
{
	int pre[2005], sz[2005];
	void init(int n)
	{
		rep(i, n) {
			pre[i] = i;
			sz[i] = 1;
		}
	}
	int root(int x)
	{
		return pre[x] == x ? x : pre[x] = root(pre[x]);
	}
	bool unite(int u, int v)
	{
		u = root(u);
		v = root(v);
		if(u == v) return false;
		if(sz[u] < sz[v]) swap(u, v);
		pre[v] = u;
		sz[u] += sz[v];
		return true;
	}
};

my_bst hvg[2005];
dsu con;
vector<PII> edg[2005];
char hv[2005][2005];
vector<PII> ret;

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, n) hvg[i] = my_bst();
	for(int i = 0; i <= m; i ++) edg[i].clear();
	ret.clear();
	
	rep(i, m) {
		scanf("%s", hv[i]);
		rep(j, n) if(hv[i][j] == '1') hvg[j].addbit(i);
	}
	
	rep(i, n) rep(j, n)
	edg[(hvg[i] & hvg[j]).do_count()].push_back(MP(i, j));
	con.init(n);
	for(int i = m; i >= 0; i --) rep(j, edg[i].size()) {
		int u = edg[i][j].first, v = edg[i][j].second;
		if(con.unite(u, v)) ret.push_back(MP(u, v));
	}
	
	rep(i, m) {
		int cnt = 0;
		rep(j, ret.size()) if(hv[i][ret[j].first] == '1' && hv[i][ret[j].second] == '1') cnt ++;
		rep(j, n) if(hv[i][j] == '1') cnt --;
		if(cnt < -1) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	rep(i, ret.size()) printf("%d %d\n", ret[i].first + 1, ret[i].second + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}