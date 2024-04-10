#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair<LL, int> PLI;
typedef pair<int, LL> PIL;
typedef pair<LL, LL> PLL;
typedef double DB;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))
#define sqr(x) ((x)*(x))
#define bit(x) (1<<(x))
#define bitl(x) (1LL<<(x))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))

template<typename T, typename U>
inline void chkmin(T &x, U y) {
	if (y < x) x = y;
}

template<typename T, typename U>
inline void chkmax(T &x, U y) {
	if (x < y) x = y;
}

int n, m;

const int MAXN = 222222;

int L[MAXN];
vector<PII> V[MAXN];
int cnt[44], dp[44];

void del(int x) {
	int mod = L[x];
	cnt[mod]--;
	if (cnt[mod] == 0) dp[mod] = -1;
}

bool add(int x, int y) {
	int mod = L[x];
	cnt[mod]++;
	if (cnt[mod] == 1) {
		assert(dp[mod] == -1);
        for (int i = 1; i <= 40; i++) {
        	if (~dp[i]) {
        		int g = __gcd(i, mod);
                if ((y - dp[i]) % g != 0) {
                    cnt[mod]--;
                    return 0;
                }
        	}
        }
        dp[mod] = y;
	}
	else if (dp[mod] != y) {
		assert(dp[mod] != -1);
		cnt[mod]--;
		return 0;
	}
    return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &L[i]);
		for (int j = 0; j < L[i]; j++) {
			int x; scanf("%d", &x);
			V[x].push_back(PII(i, j));
		}
	}
    for (int i = 1; i <= m; i++) {
    	int ans = 0;
    	for (int j = 0, k = 0; j < V[i].size(); j = k) {
    		for (k = j+1; k < V[i].size() && V[i][k-1].first+1 == V[i][k].first; k++);
            memset(cnt, 0, sizeof cnt);
            memset(dp, -1, sizeof dp);
            for (int l = j, ll = j; l < k; l++) {
                if (l > j) del(V[i][l-1].first);
                for (; ll < k && add(V[i][ll].first, V[i][ll].second); ll++);
                chkmax(ans, ll - l);
            }
    	}
    	printf("%d\n", ans);
    }
	return 0;
}