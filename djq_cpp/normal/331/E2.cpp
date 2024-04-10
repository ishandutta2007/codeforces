#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, m;
bool edg[55][55];
vector<int> seq[55][55];

PII go_l(vector<int> cur, int beg = 1)
{
	while(beg < (int)cur.size()) {
		int u = cur[beg - 1], v = cur[beg];
		if(!edg[v][u]) return MP(-1, -1);
		for(int i = (int)seq[v][u].size() - 1; i >= 0; i --) cur.push_back(seq[v][u][i]);
		if((int)cur.size() >= 2 * n + 2) return MP(-1, -1);
		beg ++;
	}
	return MP((int)cur.size(), cur.back());
}

PII exp_l(int v, int nxt)
{
	if(seq[nxt][v].back() != nxt) return MP(-2, -1);
	vector<int> cur;
	cur.push_back(v);
	for(int i = (int)seq[nxt][v].size() - 1; i >= 0; i --) cur.push_back(seq[nxt][v][i]);
	PII ret = go_l(cur, 2);
	return MP(ret.first - 1, ret.second);
}

PII go_r(vector<int> cur, int beg = 1)
{
	while(beg < (int)cur.size()) {
		int u = cur[beg - 1], v = cur[beg];
		if(!edg[u][v]) return MP(-1, -1);
		rep(i, seq[u][v].size()) cur.push_back(seq[u][v][i]);
		if((int)cur.size() >= 2 * n + 2) return MP(-1, -1);
		beg ++;
	}
	return MP((int)cur.size(), cur.back());
}

PII exp_r(int v, int nxt)
{
	if(seq[v][nxt][0] != nxt) return MP(-2, -1);
	vector<int> cur;
	cur.push_back(v);
	rep(i, seq[v][nxt].size()) cur.push_back(seq[v][nxt][i]);
	PII ret = go_r(cur, 2);
	return MP(ret.first - 1, ret.second);
}

//(ML^kGR^k)^k
int cntg[55][55][105], cntl[55][55][105], cntr[55][55][105], mat[55][55];
int dp[55][105], dpm[55][105], dpl[55][105], dpg[55][105], dpr[55][105];

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int u, v, k, x;
		scanf("%d%d%d", &u, &v, &k);
		edg[u][v] = true;
		rep(j, k) {
			scanf("%d", &x);
			seq[u][v].push_back(x);
		}
	}
	
	rep1(i, n) rep1(j, n) if(edg[i][j]) {
		for(int k = 0; k + 1 < (int)seq[i][j].size(); k ++)
		if(seq[i][j][k] == i && seq[i][j][k + 1] == j) {
			vector<int> L, R;
			for(int k1 = k; k1 >= 0; k1 --) L.push_back(seq[i][j][k1]);
			for(int k1 = k + 1; k1 < (int)seq[i][j].size(); k1 ++) R.push_back(seq[i][j][k1]);
			PII PL = go_l(L), PR = go_r(R);
			if(PL.first != -1 && PR.first != -1 && PL.first + PR.first <= 2 * n + 1)
			cntg[PL.second][PR.second][PL.first + PR.first] ++;
		}
	}
	
	rep1(i, n) rep1(j, n) if(edg[i][j]) {
		if(seq[i][j].empty()) mat[i][j] ++;
		else {
			PII al = exp_l(j, i);
			PII ar = exp_r(i, j);
			if(al.first != -2) cntl[al.second][j][al.first] ++;
			if(ar.first != -2) cntr[i][ar.second][ar.first] ++;
		}
	}
	rep1(i, n) mat[0][i] = 1;
	
	rep(t, 2 * n + 2) {
		if(t == 0) dp[0][0] = 1;
		else {
			rep(i, n + 1) rep(j, n + 1) rep1(k, t) dpg[i][t] = (dpg[i][t] + 1LL * dpl[j][t - k] * cntg[j][i][k]) % MOD;
			rep(i, n + 1) {
				dpr[i][t] = dpg[i][t];
				rep(j, n + 1) rep1(k, t) dpr[i][t] = (dpr[i][t] + 1LL * dpr[j][t - k] * cntr[j][i][k]) % MOD;
			}
			rep(i, n + 1) dp[i][t] = dpr[i][t];
		}
		rep(i, n + 1) rep(j, n + 1) dpm[i][t] = (dpm[i][t] + 1LL * dp[j][t] * mat[j][i]) % MOD;
		rep(i, n + 1) {
			dpl[i][t] = dpm[i][t];
			rep(j, n + 1) rep1(k, t) dpl[i][t] = (dpl[i][t] + 1LL * dpl[j][t - k] * cntl[j][i][k]) % MOD;
		}
		
		if(t <= 1) continue;
		int sum = 0;
		rep(i, n + 1) sum = (sum + dp[i][t]) % MOD;
		printf("%d\n", sum);
	}
	
	return 0;
}