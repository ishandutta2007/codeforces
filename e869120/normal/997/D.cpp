#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

const int mod = 998244353;

int N1, N2, K;
int A1[4009], B1[4009], A2[4009], B2[4009], dp[77][4009];
int CA1[4009], CB1[4009], DA1[4009], DB1[4009], CA2[4009], CB2[4009], DA2[4009], DB2[4009];
int cnt_c1, cnt_d1, cnt_c2, cnt_d2;
long long ans1[77], ans2[77], nr[77][77];

vector<int>G1[4009], G2[4009]; int col1[4009], col2[4009];

void init() {
	for (int i = 0; i <= 75; i++) {
		for (int j = 0; j <= 75; j++) {
			if (i == 0 || j == 0) nr[i][j] = 1;
			else nr[i][j] = (nr[i - 1][j] + nr[i][j - 1]) % mod;
		}
	}
}

void dfs1(int pos, int dep) {
	if (col1[pos] >= 0) return;
	col1[pos] = dep;
	for (int i = 0; i < G1[pos].size(); i++) dfs1(G1[pos][i], dep ^ 1);
}
void dfs2(int pos, int dep) {
	if (col2[pos] >= 0) return;
	col2[pos] = dep;
	for (int i = 0; i < G2[pos].size(); i++) dfs2(G2[pos][i], dep ^ 1);
}

void solve_1() {
	for (int t = 1; t <= N1; t++) {
		for (int i = 0; i <= K; i++) {
			for (int j = 1; j <= N1; j++) dp[i][j] = 0;
		}
		dp[0][t] = 1;
		if (col1[t] == 0) {
			for (int i = 0; i < K; i++) {
				if ((i & 1) == 0) { for (int j = 0; j < cnt_c1; j++) { dp[i + 1][CB1[j]] += dp[i][CA1[j]]; if (dp[i + 1][CB1[j]] >= mod) dp[i + 1][CB1[j]] -= mod; } }
				if ((i & 1) == 1) { for (int j = 0; j < cnt_d1; j++) { dp[i + 1][DB1[j]] += dp[i][DA1[j]]; if (dp[i + 1][DB1[j]] >= mod) dp[i + 1][DB1[j]] -= mod; } }
			}
		}
		else {
			for (int i = 0; i < K; i++) {
				if ((i & 1) == 1) { for (int j = 0; j < cnt_c1; j++) { dp[i + 1][CB1[j]] += dp[i][CA1[j]]; if (dp[i + 1][CB1[j]] >= mod) dp[i + 1][CB1[j]] -= mod; } }
				if ((i & 1) == 0) { for (int j = 0; j < cnt_d1; j++) { dp[i + 1][DB1[j]] += dp[i][DA1[j]]; if (dp[i + 1][DB1[j]] >= mod) dp[i + 1][DB1[j]] -= mod; } }
			}
		}
		for (int i = 0; i <= K; i++) { ans1[i] += dp[i][t]; ans1[i] %= mod; }
	}
}

void solve_2() {
	for (int t = 1; t <= N2; t++) {
		for (int i = 0; i <= K; i++) {
			for (int j = 1; j <= N2; j++) dp[i][j] = 0;
		}
		dp[0][t] = 1;
		if (col2[t] == 0) {
			for (int i = 0; i < K; i++) {
				if ((i & 1) == 0) { for (int j = 0; j < cnt_c2; j++) { dp[i + 1][CB2[j]] += dp[i][CA2[j]]; if (dp[i + 1][CB2[j]] >= mod) dp[i + 1][CB2[j]] -= mod; } }
				if ((i & 1) == 1) { for (int j = 0; j < cnt_d2; j++) { dp[i + 1][DB2[j]] += dp[i][DA2[j]]; if (dp[i + 1][DB2[j]] >= mod) dp[i + 1][DB2[j]] -= mod; } }
			}
		}
		else {
			for (int i = 0; i < K; i++) {
				if ((i & 1) == 1) { for (int j = 0; j < cnt_c2; j++) { dp[i + 1][CB2[j]] += dp[i][CA2[j]]; if (dp[i + 1][CB2[j]] >= mod) dp[i + 1][CB2[j]] -= mod; } }
				if ((i & 1) == 0) { for (int j = 0; j < cnt_d2; j++) { dp[i + 1][DB2[j]] += dp[i][DA2[j]]; if (dp[i + 1][DB2[j]] >= mod) dp[i + 1][DB2[j]] -= mod; } }
			}
		}
		for (int i = 0; i <= K; i++) { ans2[i] += dp[i][t]; ans2[i] %= mod; }
	}
}

int main() {
	cin >> N1 >> N2 >> K;
	for (int i = 1; i <= N1 - 1; i++) { cin >> A1[i] >> B1[i]; G1[A1[i]].push_back(B1[i]); G1[B1[i]].push_back(A1[i]); }
	for (int i = 1; i <= N2 - 1; i++) { cin >> A2[i] >> B2[i]; G2[A2[i]].push_back(B2[i]); G2[B2[i]].push_back(A2[i]); }
	for (int i = 1; i <= N1; i++) col1[i] = -1; dfs1(1, 0);
	for (int i = 1; i <= N2; i++) col2[i] = -1; dfs2(1, 0);
	for (int i = 1; i <= N1 - 1; i++) { if (col1[A1[i]] == 0) { CA1[cnt_c1] = A1[i]; CB1[cnt_c1] = B1[i]; cnt_c1++; } else { DA1[cnt_d1] = A1[i]; DB1[cnt_d1] = B1[i]; cnt_d1++; } }
	for (int i = 1; i <= N1 - 1; i++) { if (col1[B1[i]] == 0) { CA1[cnt_c1] = B1[i]; CB1[cnt_c1] = A1[i]; cnt_c1++; } else { DA1[cnt_d1] = B1[i]; DB1[cnt_d1] = A1[i]; cnt_d1++; } }
	for (int i = 1; i <= N2 - 1; i++) { if (col2[A2[i]] == 0) { CA2[cnt_c2] = A2[i]; CB2[cnt_c2] = B2[i]; cnt_c2++; } else { DA2[cnt_d2] = A2[i]; DB2[cnt_d2] = B2[i]; cnt_d2++; } }
	for (int i = 1; i <= N2 - 1; i++) { if (col2[B2[i]] == 0) { CA2[cnt_c2] = B2[i]; CB2[cnt_c2] = A2[i]; cnt_c2++; } else { DA2[cnt_d2] = B2[i]; DB2[cnt_d2] = A2[i]; cnt_d2++; } }

	solve_1();
	solve_2();
	init();
	
	long long ans = 0;
	for (int i = 0; i <= K; i++) { ans += (nr[i][K - i] * ans1[i] % mod) * ans2[K - i] % mod; ans %= mod; }
	cout << ans << endl;
	return 0;
}