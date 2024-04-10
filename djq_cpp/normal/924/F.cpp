#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

bitset<175> F[50005];
int par[50005], nxt[50005][15], tot, vn;
void dfs(int val, int cnt, int sum, bitset<175> S)
{
	int m = sum >> 1, l = m, r = m;
	for(; l >= 0 && S[l]; l --) ;
	for(; r <= sum && S[r]; r ++) ;
	if(r - l >= 10) return;
	F[tot ++] = S;
	if(cnt == 19) return;
	for(int i = val; i <= 9; i ++) dfs(i, cnt + 1, sum + i, S | S << i);
}

bool cmp(const bitset<175>& A, const bitset<175>& B)
{
	for(int i = 174; i >= 0; i --) if(A[i] != B[i]) return A[i] < B[i];
	return false;
}

mt19937 rng(20191124);
int hs[50005], nhs[50005], pos[50005], coef[15];
int st[5005], fst[5005], tr[5005][15];

int T, qk[50005];
LL ql[50005], qr[50005], ans[50005];
vector<int> qs[15];
LL dp[25][15][5005];

int dig[25];
LL solve(LL x)
{
	int len = 0;
	while(x > 0) {
		dig[len ++] = x % 10; x /= 10;
	}
	int cur = pos[0];
	LL ret = 0;
	for(int i = len - 1; i >= 0; i --) {
		ret += dp[i + 1][dig[i]][cur];
		cur = tr[cur][dig[i]];
	}
	return ret;
}
int main()
{
//	freopen("name.in", "r", stdin);
//	freopen("name.out", "w", stdout);
	
	F[0] = 1; tot = 1;
	dfs(1, 0, 0, bitset<175>(1));
	sort(F, F + tot, cmp);
	tot = unique(F, F + tot) - F;
	rep(i, tot) rep(j, 175) if(F[i][j]) par[i] = j;
	rep(i, tot) rep(j, 10) {
		bitset<175> N = F[i] | F[i] << j;
		nxt[i][j] = lower_bound(F, F + tot, N, cmp) - F;
		if(F[nxt[i][j]] != N) nxt[i][j] = tot + ((par[i] + j) & 1);
	}
	rep(i, 2) rep(j, 10) nxt[tot + i][j] = tot + ((i + j) & 1);
	rep(i, tot) par[i] = !(par[i] & 1) && F[i][par[i] >> 1];
	par[tot] = 1;
	tot += 2;
	
	rep(i, tot) hs[i] = par[i];
	rep(i, 19) {
		rep(j, 10) coef[j] = rng() % MOD;
		rep(j, tot) {
			nhs[j] = 0;
			rep(k, 10) nhs[j] = (nhs[j] + 1ULL * coef[k] * hs[nxt[j][k]]) % MOD;
		}
		rep(j, tot) hs[j] = nhs[j];
	}
	sort(nhs, nhs + tot);
	vn = unique(nhs, nhs + tot) - nhs;
	rep(i, tot) pos[i] = lower_bound(nhs, nhs + vn, hs[i]) - nhs;
	rep(i, tot) {
		st[pos[i]] = par[i];
		rep(j, 10) tr[pos[i]][j] = pos[nxt[i][j]];
	}
	
	rep(i, vn) rep(j, 10) if(st[tr[i][j]]) {
		fst[i] = j; break;
	}
	
	scanf("%d", &T);
	rep(i, T) scanf("%lld%lld%d", &ql[i], &qr[i], &qk[i]);
	rep(i, T) qs[qk[i]].push_back(i);
	rep(i, 10) {
		memset(dp, 0, sizeof(dp));
		rep(j, vn) dp[0][10][j] = fst[j] <= i;
		rep1(j, 19) rep(k, 10) rep(l, vn) dp[j][k + 1][l] = dp[j][k][l] + dp[j - 1][10][tr[l][k]];
		
		rep(j, qs[i].size()) {
			int cq = qs[i][j];
			ans[cq] = solve(qr[cq] + 1) - solve(ql[cq]);
		}
	}
	rep(i, T) printf("%lld\n", ans[i]);
	return 0;
}