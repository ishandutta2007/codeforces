#include <bits/stdc++.h>

const int MAXN = 1000010;
const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
void zalgo(char * S, int ss, char * T, int ts, int * A) {
	static int Z[MAXN << 1];
	static char buf[MAXN << 1];
	std::copy(S + 1, S + ss + 1, buf + 1);
	buf[ss + 1] = '#';
	std::copy(T + 1, T + ts + 1, buf + ss + 2);
	const int SZ = ss + ts + 1;
	buf[SZ + 1] = 0;
	for (int i = 2, l = 0, r = 0; i <= SZ; ++i) {
		int & z = Z[i] = 0;
		if (i <= r) z = std::min(r - i + 1, Z[i - l + 1]);
		while (i + z <= SZ && buf[i + z] == buf[z + 1]) ++z;
		if (i + z - 1 > r) l = i, r = i + z - 1;
		if (i > ss + 1) A[i - ss - 1] = z;
	}
}
char S[MAXN], L[MAXN], R[MAXN];
int al[MAXN], ar[MAXN];
int pre[MAXN], dp[MAXN];
bool le(char * B, int sl, int * A, int l, int r, bool eq) {
	int LL = r - l + 1;
	if (LL != sl) return LL < sl;
	int L = std::min(A[l], LL);
	if (L == LL) return eq;
	return S[l + L] < B[L + 1];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> S + 1 >> L + 1 >> R + 1;
	int ss = strlen(S + 1), sl = strlen(L + 1), sr = strlen(R + 1);
	zalgo(L, sl, S, ss, al);
	zalgo(R, sr, S, ss, ar);
	dp[0] = pre[0] = 1;
	int ll = 0, rr = 0;
	for (int i = 1; i <= ss; ++i) {
		while (ll < i && !le(L, sl, al, ll + 1, i, false)) ++ll;
		while (rr < i && !le(R, sr, ar, rr + 1, i, true)) ++rr;
		int f = (ll ? pre[ll - 1] : 0) - (rr ? pre[rr - 1] : 0);
		reduce(f);
		if (rr <= i - 1 && i - 1 < ll && S[i] == '0')
			reduce(f += dp[i - 1] - mod);
		dp[i] = f;
		if (i == ss) std::cout << f << std::endl;
		if (S[i + 1] == '0') f = 0;
		reduce(pre[i] = pre[i - 1] + f - mod);
	}
	return 0;
}