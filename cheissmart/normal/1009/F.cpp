#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 1e6 + 7;

vi G[N];
int ans[N];

pair<vi*, int> dfs(int u, int p = 0) {
	vi* ret = new vi{1};
	int pos = 0;
	for(int v:G[u]) if(v != p) {
		auto[ret1, pos1] = dfs(v, u);
		ret1 -> push_back(0);
		pos1++;
		if(SZ(*ret) < SZ(*ret1))
			swap(ret, ret1), swap(pos, pos1);
		for(int i = 0; i < SZ(*ret1); i++) {
			(*ret)[SZ(*ret) - i - 1] += (*ret1)[SZ(*ret1) - i - 1];
			if((*ret)[SZ(*ret) - i - 1] > (*ret)[SZ(*ret) - pos - 1])
				pos = i;
			else if((*ret)[SZ(*ret) - i - 1] == (*ret)[SZ(*ret) - pos - 1])
				pos = min(pos, i);
		}
	}
	ans[u] = pos;
	return {ret, pos};
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v), G[v].PB(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}