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

int n;

map<int, int> H;

int a[111111], b[111111];

bool can(int U) {
	H.clear();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 30; j++) {
			int x = a[i] >> j;
            if (x == 0) return 0;
            if (x <= U && !H.count(x)) {
            	b[i] = x;
            	H[x] = 1;
                break;
            }
		}
	}
	return 1;
}

int main() {
	
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int lo = 0, hi = a[1];
    while (hi - lo > 1) {
    	int mid = lo + hi >> 1;
        if (can(mid)) {
        	hi = mid;
        } else {
        	lo = mid;
        }
    }
    can(hi);
    for (int i = 1; i <= n; i++) printf("%d%c", b[i], i < n ? ' ' : '\n');
	return 0;
}