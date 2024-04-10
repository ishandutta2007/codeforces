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
#define MX 512345
int len[MX];

int main() {
	
  VI V;
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= 5 * (m + 1); i++) {
    int k = i;
    int x = 0;
    while (k) x += k / 5, k /= 5;
    if (x == m) V.pb(i);
  }
  cout << V.size() << endl;
  for (int i = 0; i < V.size(); i++) {
    if (i) putchar(' ');
    printf("%d", V[i]);
  }
  puts("");
  return 0;
}