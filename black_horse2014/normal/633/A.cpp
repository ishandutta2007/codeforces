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
#define countl(x) (__builtin_popcountll(x))
#define clz(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctz(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))

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

int a, b, c;

int main() {
  
  scanf("%d%d%d", &a, &b, &c);
  int bf = 0;
  for (int i = 0; a * i <= c; i++) {
    if ((c - a * i) % b == 0) {
      bf = 1;
    }
  }
  printf("%s\n", bf ? "Yes" : "No");
  
  return 0;
}