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

int n, a, b, c;
multiset<int> S;
multiset<int>::iterator it;

int main() {
//#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
//#endif
  
  scanf("%d%d%d%d", &n, &a, &b, &c);
  
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    S.insert(t);
  }
  if (S.upper_bound(a + b + c) != S.end()) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  int ma = max(a + b, max(a + c, b + c));
  while (!S.empty()) {
    it = --S.end();
    if (*it <= ma) break;
    S.erase(it);
    ans++;
  }
  ma = max(a, max(b, c));
  while (!S.empty()) {
    it = --S.end();
    if (*it <= ma) break;
    int mx = -1;
    if (*it <= a + b) chkmax(mx, c);
    if (*it <= a + c) chkmax(mx, b);
    if (*it <= b + c) chkmax(mx, a);
    S.erase(it);
    it = S.upper_bound(mx);
    if (it != S.begin()) {
      it--;
      S.erase(it);
    }
    ans++;
  }
  int sum = a + b + c;
  int mi1 = min(a, min(b, c));
  int mi2 = sum - ma - mi1;
  while (!S.empty()) {
    it = --S.end();
    S.erase(it);
    
    int val1 = -1, val2 = -1;
    it = S.upper_bound(mi2);
    if (it != S.begin()) {
      it--;
      val1 = *it;
      S.erase(it);
    }
    it = S.upper_bound(mi1);
    if (it != S.begin()) {
      it--;
      val2 = *it;
      S.erase(it);
    }
    if (val1 == -1 || val2 == -1) {
      if (val1 != -1) S.insert(val1);
      if (val2 != -1) S.insert(val2);
      it = S.upper_bound(sum - ma);
      if (it != S.begin()) {
        it--;
        S.erase(it);
      }      
    }
    ans++;
  }
  printf("%d\n", ans);
    return 0;
}