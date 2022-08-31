#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

typedef PII hash_t;

int S[5] = {0, 758, 19, 2606, 20020626};
hash_t operator+(const hash_t& a, const hash_t& b)
{
	return MP((a.first + b.first) % 998244353, (a.second + b.second) % 1000000007);
}
hash_t operator*(const hash_t& a, const hash_t& b)
{
	return MP(1LL * a.first * b.first % 998244353, 1LL * a.second * b.second % 1000000007);
}

int n, m;
vector<int> G0[400005], G[400005];
int sid[400005];
int cor[400005];

void add_edge(int u, int v, vector<int> cur[])
{
	cur[u].push_back(v);
	cur[v].push_back(u);
}

int get_ver(char ch, int v)
{
	if(ch == 'T') return v;
	else if(ch == 'R') return v + m;
	else if(ch == 'B') return 2 * m + n + 1 - v;
	else return 2 * (m + n) + 1 - v;
}

bool vis[400005];
vector<int> cyc[400005], cyc0[400005];
pair<hash_t, int> hs[400005], hs0[400005];

void dfs(int v, vector<int> cg[], vector<int>& ret)
{
	vis[v] = true;
	ret.push_back(v);
	rep(i, cg[v].size()) {
		int u = cg[v][i];
		if(!vis[u]) dfs(u, cg, ret);
	}
}

void gen_hash(int cv, vector<int> cg[], pair<hash_t, int>& ret, vector<int> rcyc[])
{
	rcyc[cv].clear();
	dfs(cv, cg, rcyc[cv]);
	
	bool rev = false;
	hash_t sum, t;
	ret.first = MP(-1, -1);
	
	rep(R, 2) {
		sum = MP(0, 0); t = MP(1, 1);
		rep(i, rcyc[cv].size()) {
			sum = sum + t * MP(S[sid[rcyc[cv][i]]], S[sid[rcyc[cv][i]]]);
			t = t * MP(243, 1003);
		}
		for(int i = rcyc[cv].size() - 1; i >= 0; i --) {
			sum = sum * MP(243, 1003) + (MP(1, 1) + MP(998244352, 1000000006) * t) *
			MP(S[sid[rcyc[cv][i]]], S[sid[rcyc[cv][i]]]);
			if(sum > ret.first) {
				rev = R; ret = MP(sum, i);
			}
		}
		reverse(rcyc[cv].begin(), rcyc[cv].end());
	}
	
	if(rev) reverse(rcyc[cv].begin(), rcyc[cv].end());
	rotate(rcyc[cv].begin(), rcyc[cv].begin() + ret.second, rcyc[cv].end());
	ret.second = rcyc[cv][0];
	swap(rcyc[cv], rcyc[ret.second]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	rep1(i, 2 * (m + n)) sid[i] = (i > 0) + (i > m) + (i > m + n) + (i > 2 * m + n);
	rep1(i, m) {
		add_edge(i, 2 * m + n + 1 - i, G);
		add_edge(i, 2 * m + n + 1 - i, G0);
	}
	rep1(i, n) {
		add_edge(m + i, 2 * (m + n) + 1 - i, G);
		add_edge(m + i, 2 * (m + n) + 1 - i, G0);
	}
	
	int cnt = 0;
	rep(i, m + n) {
		char tu, tv;
		int pu, pv;
		cin >> tu >> tv >> pu >> pv;
		pu = get_ver(tu, pu);
		pv = get_ver(tv, pv);
		add_edge(pu, pv, G);
		if(sid[pu] + sid[pv] == 5) cnt ++;
	}
	cnt /= 2;
	rep1(i, cnt) {
		add_edge(2 * (m + n) + 1 - i, i, G0);
		add_edge(m + n + 1 - i, m + n + i, G0);
	}
	rep1(i, min(m, n) - cnt) {
		add_edge(m + 1 - i, m + i, G0);
		add_edge(2 * m + n + 1 - i, 2 * m + n + i, G0);
	}
	if(n < m) rep1(i, m - n) add_edge(cnt + i, 2 * m + cnt + 1 - i, G0);
	else if(n > m) rep1(i, n - m) add_edge(2 * m - cnt + i, 2 * (m + n) - cnt + 1 - i, G0);
	
	cnt = 0;
	int cnt0 = 0;
	rep1(i, 2 * (m + n)) vis[i] = false;
	rep1(i, 2 * (m + n)) if(!vis[i]) gen_hash(i, G, hs[cnt ++], cyc);
	rep1(i, 2 * (m + n)) vis[i] = false;
	rep1(i, 2 * (m + n)) if(!vis[i]) gen_hash(i, G0, hs0[cnt0 ++], cyc0);
	
	sort(hs, hs + cnt);
	sort(hs0, hs0 + cnt0);
	bool ok = cnt == cnt0;
	rep(i, cnt) ok &= hs[i].first == hs0[i].first;
	if(!ok) {
		cout << "No solution\n";
		return 0;
	}
	
	rep(i, cnt) rep(j, cyc[hs[i].second].size())
	cor[cyc0[hs0[i].second][j]] = cyc[hs[i].second][j];
	
	rep1(i, n) cout << cor[m + i] - m << (i == n ? '\n' : ' ');
	rep1(i, m) cout << cor[i] << (i == m ? '\n' : ' ');
	return 0;
}