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

int p[111];
char s[1111];

const char pat[] = "aeiouy";

int main() {
	
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    gets(s);
    int ret = 1;
    for (int i = 0; i < n; i++) {
        gets(s);
        int ans = 0;
        for (char *tok = strtok(s, " "); tok; tok = strtok(NULL, " ")) {
            for (int j = 0; tok[j]; j++) {
            	int found = 0;
            	for (int k = 0; k < 6; k++) {
            		if (tok[j] == pat[k]) {
            			found = 1;
            			break;
            		}
            	}
            	ans += found;
            }
        }
        if (ans != p[i]) ret = 0;
    }
    puts(ret ? "YES" : "NO");
	return 0;
}