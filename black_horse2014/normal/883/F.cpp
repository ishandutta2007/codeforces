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

char s[50];
char t[50];

bool convert(char *s, char *t) {
	int m = strlen(s);
	for (int j = m-2; j >= 0; j--) {
		if (s[j] == 'k' && s[j+1] == 'h') {
			s[j] = 0;
			strcpy(t, s);
			strcpy(t + j, s + j + 1);
			return 1;
		}
	}
	for (int j = m-1; j >= 0; j--) {
		if (s[j] == 'u') {
			s[j] = 0;
			strcpy(t, s);
			t[j] = 'o', t[j+1] = 'o';
			strcpy(t + j + 2, s + j + 1);
			return 1;
		}
	}
	return 0;
}

map<string, int> H;

int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		while (convert(s, t)) strcpy(s, t);
		if (!H.count(s)) ans++;
		H[s] = 1;
	}
	cout << ans << endl;
	return 0;
}