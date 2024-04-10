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
#include <bitset>

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
void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
void chkmin(T& x, U y) {
	if (y < x) x = y;
}

int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char p[][20] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
char s[2][20];
int f, g;

int get(char *s) {
	for (int i = 0; i < 7; i++) if (strcmp(s, p[i]) == 0) return i;
	return -1;
}

int main() {
	
	scanf("%s%s", s[0], s[1]);
	f = get(s[0]), g = get(s[1]);
	for (int i = 0; i < 10; i++) {
		int d = f + mon[i];
		if (d % 7 == g % 7) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}