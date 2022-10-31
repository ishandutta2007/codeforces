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
#define counti(x) (__builtin_popcount(x))
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define Error(x) cout << #x << " = " << endl
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

const int MN = 505;
int H, W;
char b[MN][MN];
int A[MN][MN];
int B[MN][MN];
int C[MN][MN];

int getA(int r1, int r2, int c1, int c2) {
  return A[r2][c2] - A[r1 - 1][c2] - A[r2][c1 - 1] + A[r1 - 1][c1 - 1];
}

int getB(int r1, int r2, int c1, int c2) {
  return B[r2][c2] - B[r1 - 1][c2] - B[r2][c1 - 1] + B[r1 - 1][c1 - 1];
}

int getC(int r1, int r2, int c1, int c2) {
  return C[r2][c2] - C[r1 - 1][c2] - C[r2][c1 - 1] + C[r1 - 1][c1 - 1];
}

int main() {
//#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
//#endif
 
  scanf("%d%d", &H, &W);
  for (int i = 1; i <= H; i++) {
    scanf("%s", b[i] + 1);
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (b[i][j] == '.' && b[i][j + 1] == '.') A[i][j]++, C[i][j]++;
      if (b[i][j] == '.' && b[i + 1][j] == '.') B[i][j]++, C[i][j]++;
    }
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
      B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
      C[i][j] += C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];
    }
  }
  int q;
  
  scanf("%d", &q);
  while (q--) {
    int r1, r2, c1, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int ans = 0;
    ans += getC(r1, r2 - 1, c1, c2 - 1);
    ans += getA(r2, r2, c1, c2 - 1);
    ans += getB(r1, r2 - 1, c2, c2);
    printf("%d\n", ans);
  }
  
    return 0;
}