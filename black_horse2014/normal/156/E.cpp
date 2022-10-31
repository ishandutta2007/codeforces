#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 11111;
const int MAXM = 4800000;

bool chk[111];
int prm[111], prn;

LL a[MAXN];

LL C[MAXN*3];
int D[MAXN*3];
char S[MAXN*3][33];
int ans[MAXN*3];
int pw[33], pw1[33];
int st[MAXN], state[MAXN*3];

int dp[5][MAXM];
vector<int> V[33];

void mul(int &x, int y, int MOD) {
	if (!x || y<0) return;
	if (x<0) x = y;
	else x = (LL)x*y % MOD;
}

const int INF = 1e9+7;
const char pat[] = "?0123456789ABCDEF";

vector<int> mod;
int lo[25], hi[25];

int main() {
	for (int i = 2; i < 100; i++) if (!chk[i]) {
		for (int j = i*i; j <= 100; j += i) chk[j] = 1;
		prm[prn++] = i;
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%s%lld", &D[i], S[i], &C[i]);
		ans[i] = -1;
		V[D[i]].push_back(i);
	}
	for (int i = 0, j; i < 25; i = j) {
		int cur = 1;
		for (j = i; j < 25 && 1LL * cur * prm[j] < INF; cur *= prm[j], j++);
		mod.pb(cur);
		lo[mod.size()-1] = i, hi[mod.size()-1] = j;
	}
	for (int d = 2; d <= 16; d++) if (!V[d].empty()) {
		int L = 0;
		for (int k = 1; k < n; k *= d, L++);
		for (int j = 0; j <= L; j++) pw1[j] = (j == 0 ? 1 : pw1[j-1] * (d+1));
		for (int j = 0; j <= L; j++) pw[j] = (j == 0 ? 1 : pw[j-1] * d);
		for (int j = 0; j < n; j++) {
			st[j] = 0;
			for (int k = 0; k < L; k++) st[j] += pw1[k] * ((j / pw[k]) % d + 1);
		}
		int maxs = pw1[L] - 1;
		for (int j = 0; j < sz(V[d]); j++) {
			int id = V[d][j];
			int len = strlen(S[id]);
			reverse(S[id], S[id] + len);
			for (int i = len; i < L; i++) S[id][i] = '0';
			state[id] = 0;
			for (int i = 0; i < L; i++) state[id] += pw1[i] * (strchr(pat, S[id][i]) - pat);
		}
		for (int p = 0; p < mod.size(); p++) {
			int MOD = mod[p];
			memset(dp[p], -1, sizeof(int)*(maxs+1));
			for (int j = 0; j < n; j++) dp[p][st[j]] = a[j]%MOD;
			for (int j = 0; j < L; j++) {
				for (int k = 0; k < pw1[j]; k++) {
					for (int s = k; s <= maxs; s += pw1[j+1]) {
						for (int l = 1, t = s + pw1[j]; l <= d; t += pw1[j], l++) {
							mul(dp[p][s], dp[p][t], MOD);
						}
					}
				}
			}
			for (int j = 0; j < sz(V[d]); j++) {
				int id = V[d][j];
				if (~ans[id]) continue;
				bool found = 0;
				long long ret = (C[id] + ((dp[p][state[id]] < 0) ? 1 : dp[p][state[id]])) % MOD;
				for (int q = lo[p]; !found && q < hi[p]; q++) {
					if (ret % prm[q] == 0) {
						ans[id] = prm[q];
						found = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}