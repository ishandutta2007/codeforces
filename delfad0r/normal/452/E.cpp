#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300010;
const int MOD = 1000000007;

typedef long long int ll;
typedef pair< int, int > ii;

int N;
char S[MAXN];
int owner[MAXN];

int SA[MAXN], tmpSA[MAXN];
int RA[MAXN], tmpRA[MAXN];

int c[MAXN];
void counting_sort(int k) {
	memset(c, 0, max(300, N) * sizeof(int));
	for(int i = 0; i < N; ++i)
		++c[(i + k < N) ? (RA[i + k]) : (0)];
	for(int i = 0, sum = 0; sum < N; ++i) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(int i = 0; i < N; ++i)
		tmpSA[c[(SA[i] + k < N) ? (RA[SA[i] + k]) : (0)]++] = SA[i];
	memcpy(SA, tmpSA, N * sizeof(int));
}

void suffix_array() {
	iota(SA, SA + N, 0);
	for(int i = 0; i < N; ++i) RA[i] = S[i];
	for(int k = 1; k < N; k <<= 1) {
		counting_sort(k);
		counting_sort(0);
		int r = tmpRA[SA[0]] = 0;
		for(int i = 1; i < N; ++i)
			tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? (r) : (++r);
		memcpy(RA, tmpRA, N * sizeof(int));
		if(RA[SA[N - 1]] == N - 1) return;
	}
}

int phi[MAXN];
int LCP[MAXN], PLCP[MAXN];
void build_lcp() {
	for(int i = 1; i < N; ++i) phi[SA[i]] = SA[i - 1];
	for(int i = 0, L = 0; i < N; ++i) {
		if(i == SA[0]) {
			PLCP[i] = 0;
			continue;
		}
		while(S[i + L] == S[phi[i] + L]) ++L;
		PLCP[i] = L;
		L = max(0, L - 1);
	}
	for(int i = 0; i < N; ++i) LCP[i] = PLCP[SA[i]];
}

class dsu_t {
	int f[MAXN];
public:
	ll c[3][MAXN];
	ll sum;
	
	void init() {
		iota(f, f + N, 0);
		for(int i = 0; i < N; ++i) ++c[owner[SA[i]]][i];
	}
	int find(int i) {
		return (f[i] == i) ? (i) : (f[i] = find(f[i]));
	}
	#define union my_union
	void union(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		f[x] = y;
		sum -= c[0][x] * c[1][x] * c[2][x] + c[0][y] * c[1][y] * c[2][y];
		for(int i = 0; i < 3; ++i) c[i][y] += c[i][x];
		sum = (sum + c[0][y] * c[1][y] * c[2][y]) % MOD;
	}
} DSU;

char terminating_c[] = {'$', '#', '\0'};
int ans[MAXN];
int sortedLCP[MAXN];
int main() {
	int minL = 1 << 30;
	for(int i = 0; i < 3; ++i) {
		scanf("%s", S + N);
		int l = strlen(S + N);
		minL = min(l, minL);
		S[(N += l)++] = terminating_c[i];
	}
	for(int i = 0, o = 0; i < N; ++i)
		if(S[i] == '$' || S[i] == '#' || S[i] == '\0') ++o;
		else owner[i] = o;
	
	suffix_array();
	build_lcp();
	/*printf("%s\n", S);
	for(int i = 0; i < N; ++i) printf("%d ", SA[i]);
	putchar('\n');
	for(int i = 0; i < N; ++i) printf("%d ", LCP[i]);
	putchar('\n');*/
	
	iota(sortedLCP, sortedLCP + N, 0);
	sort(sortedLCP, sortedLCP + N, [&](int i, int j) { return LCP[i] > LCP[j]; });
	
	DSU.init();
	for(int l = minL, i = 0; l; --l) {
		for(; LCP[sortedLCP[i]] >= l; ++i)
			DSU.union(sortedLCP[i], sortedLCP[i] - 1);
		ans[l] = DSU.sum;
	}
	
	for(int l = 1; l <= minL; ++l) printf("%d ", ans[l]);
}