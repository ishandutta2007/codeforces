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
struct HashMap {
	static const int MOD = 999983;
	int head[MOD], num, next[1234567];
	int edge[1234567], V[1234567];
	HashMap() {init();}
	void init() {
		num = 0;
		memset(head, -1, sizeof head);
	}
	void Insert(int val, int v) {
		int rem = val % MOD;
		if (rem < 0) rem += MOD;
		edge[num] = val;
		V[num] = v;
		next[num] = head[rem];
		head[rem] = num++;
	}
	void add(int val, int v) {
	  int rem = val % MOD;
		if (rem < 0) rem += MOD;
		for (int i = head[rem]; ~i; i = next[i]) {
			if (edge[i] == val) {
			  V[i] += v;
			  return;
      }
		}
		Insert(val, v);
  }
	int get(int val) {
		int rem = val % MOD;
		if (rem < 0) rem += MOD;
		for (int i = head[rem]; ~i; i = next[i]) {
			if (edge[i] == val) return V[i];
		}
		return 0;
	}
}H;
int n, m;
int a[1005];
int tmp[1005], tn;
int main() {
	
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    H.add(a[i], 1);
  }
  
  int ans = H.get(0);
  for (int i = 0; i < n; i++) {
    H.add(a[i], -1);
    for (int j = 0; j < n; j++) if (i != j) {
      if (a[i] == 0 && a[j] == 0) continue;
      H.add(a[j], -1);
      int x = a[i], y = a[j], cnt = 2;
      tn = 0;
      while (1) {
        int z = x + y;
        if (abs(z) > 1000000000) break;
        if (!H.get(z)) break;
        H.add(z, -1);
        tmp[tn++] = z;
        x = y, y = z;
        cnt++;
      }
      chkmax(ans, cnt);
      for (int i = 0; i < tn; i++) H.add(tmp[i], 1);
      H.add(a[j], 1);
    }
    H.add(a[i], 1);
  }
  cout << ans << endl;
  return 0;
}