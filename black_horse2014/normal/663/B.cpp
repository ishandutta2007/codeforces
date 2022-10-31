#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

LL n;
int a[15], an;
char str[100];

LL calc(LL a, int t) {
	for (; a % 10 != t; a++);
	return a;
}

int main() {

	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		scanf("%s", str);
		an = 0;
		for (int i = 4; str[i]; i++) a[an++] = str[i] - '0';
		LL v = 1989;
		for (int i = an - 1; i >= 0; i--) {
			v = calc(v, a[i]);
			v /= 10;
			v++;
		}
		if (v - 1 != 0) printf("%lld%s\n", v - 1, str + 4);
		else printf("%s\n", str + 4);
	}

	return 0;
}