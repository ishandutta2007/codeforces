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
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

typedef unsigned int uint;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;
typedef long double LD;

#define pb push_back
#define mset(a, b) (memset(a, b, sizeof a))
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define X first
#define Y second

template <typename T, typename U>
inline void chkmax(T& x, U y) {
    if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
    if (y < x) x = y;
}

const int MN = 120;
char b[3][MN];

int hd, tl, n, k;
PII q[3 * MN];
int chk[3][MN], T;

bool out(int x, int y) {
	return x < 0 || x >= 3;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  int tn;

  for (cin >> tn; tn--; ) {

		T++;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < 3; i++) {
			scanf("%s", b + i);
      for (int j = n; j < n + 10; j++) b[i][j] = '.';
      b[i][n + 10] = 0;
		}
		hd = tl = 0;
    for (int i = 0; i < 3; i++) if (b[i][0] == 's') {
			b[i][0] = '.';
			q[tl++] = PII(i, 0);
    }
    while (hd < tl) {
			PII u = q[hd];
			if (u.Y >= n) break;
			hd++;
			for (int i = -1; i <= 1; i++) {
				PII v = u;
        v.Y++;
        if (out(v.X, v.Y)) continue;
        if (b[v.X][v.Y] != '.') continue;
				v.X += i;
        if (out(v.X, v.Y)) continue;
        if (b[v.X][v.Y] != '.') continue;
        v.Y++;
        if (out(v.X, v.Y)) continue;
        if (b[v.X][v.Y] != '.') continue;
        v.Y++;
        if (out(v.X, v.Y)) continue;
        if (b[v.X][v.Y] != '.') continue;
        if (chk[v.X][v.Y] == T) continue;
        chk[v.X][v.Y] = T;
        q[tl++] = v;
			}
    }
    if (hd < tl) puts("YES");
    else puts("NO");
	}

  return 0;
}