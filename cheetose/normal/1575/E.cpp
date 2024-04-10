#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long a[212121];
vector<pair<long long, long long>>edge[212121];
long long ans = 0, mod = 1e9 + 7;
long long is_cent[212121];
long long S[212121], cent;
void mk_s(long long w, long long bef) {
	S[w] = 1;
	for (auto [nxt, ncol] : edge[w]) {
		if (is_cent[nxt])continue;
		if (nxt == bef)continue;
		mk_s(nxt, w);
		S[w] += S[nxt];
	}
}
long long get_cent(long long w, long long bef, long long all) {
	for (auto [nxt, ncol] : edge[w]) {
		if (is_cent[nxt])continue;
		if (nxt == bef)continue;
		if (S[nxt] > all / 2) return get_cent(nxt, w, all);
	}
	return w;
}
vector<pair<long long, long long>>G[212121];
vector<long long>cnt[212121], SUM[212121];
void mk_G(long long w, long long bef, long long bef_col, long long sum, long long trans, long long rep) {
	G[rep].push_back({ sum, trans });
	for (auto [nxt, ncol] : edge[w]) {
		if (is_cent[nxt])continue;
		if (nxt == bef)continue;
		mk_G(nxt, w, ncol, (sum + a[nxt])%mod, trans + (ncol != bef_col), rep);
	}
}
void decomp(long long w) {
	mk_s(w, -1);
	long long cent = get_cent(w, -1, S[w]);
	is_cent[cent] = 1;
	vector<long long>ALLcnt[2], ALLS[2];
	ALLcnt[0].resize(S[w], 0); ALLS[0].resize(S[w], 0);
	ALLcnt[1].resize(S[w], 0); ALLS[1].resize(S[w], 0);
	for (auto [nxt, ncol] : edge[cent]) {
		if (is_cent[nxt])continue;
		G[nxt].clear();
		mk_G(nxt, cent, ncol, a[nxt], 0, nxt);
		long long mxt = 0;
		for (auto [sum, trans] : G[nxt]) {
			ALLcnt[ncol][trans]++;
			mxt = max(mxt, trans);
		}
		cnt[nxt].clear(); cnt[nxt].resize(mxt + 1, 0);
		SUM[nxt].clear(); SUM[nxt].resize(mxt + 1, 0);
		for (auto [sum, trans] : G[nxt]) cnt[nxt][trans]++;
		for (long long i = 0; i <= mxt; i++) {
			SUM[nxt][i] += cnt[nxt][i];
			if (i > 0)SUM[nxt][i] += SUM[nxt][i - 1];
		}
	}
	for (long long i = 0; i < ALLcnt[0].size(); i++) {
		ALLS[0][i] = ALLcnt[0][i] + (i > 0 ? ALLS[0][i - 1] : 0);
		ALLS[1][i] = ALLcnt[1][i] + (i > 0 ? ALLS[1][i - 1] : 0);
	}
	long long allcount = 0;
	for (auto [nxt, ncol] : edge[cent]) {
		if (is_cent[nxt])continue;
		for (auto [sum, trans] : G[nxt]) {
			//  k - trans
			if (k - trans >= 0) {
				long long SnxtIdx = k - trans;
				long long ncolIdx = k - trans;
				if (SnxtIdx >= SUM[nxt].size())SnxtIdx = SUM[nxt].size() - 1;
				if (ncolIdx >= ALLS[ncol].size())ncolIdx = ALLS[ncol].size() - 1;
				long long gaesu = ALLS[ncol][ncolIdx] - SUM[nxt][SnxtIdx];
				allcount += gaesu;
				ans += sum * (gaesu % mod) % mod;
				ans %= mod;
			}
			if (k - trans - 1 >= 0) {
				long long ncolIdx = k - trans - 1;
				if (ncolIdx >= ALLS[ncol].size())ncolIdx = ALLS[ncol].size() - 1;
				long long gaesu = ALLS[!ncol][ncolIdx];
				allcount += gaesu;
				ans += sum * (gaesu % mod) % mod;
				ans %= mod;
			}
		}
	}
	allcount /= 2;
	allcount %= mod;
	allcount++;
	for (auto [nxt, ncol] : edge[cent]) {
		if (is_cent[nxt])continue;
		for (auto [sum, trans] : G[nxt]) {
			if (trans <= k) {
				ans = (ans + sum) % mod;
				allcount++;
			}
		}
	}
	ans += allcount * a[cent];
	ans %= mod;
	for (auto [nxt, ncol] : edge[cent]) {
		if (is_cent[nxt])continue;
		decomp(nxt);
	}
}
int main() {
	long long i, j;
	scanf("%lld%lld", &n, &k);
	for (i = 1; i <= n; i++)scanf("%lld", &a[i]);
	for (i = 0; i < n - 1; i++) {
		long long s, e, col; scanf("%lld%lld%lld", &s, &e, &col);
		edge[s].push_back({ e,col });
		edge[e].push_back({ s,col });
	}
	decomp(1);
	printf("%lld\n", ans % mod);
	return 0;
}