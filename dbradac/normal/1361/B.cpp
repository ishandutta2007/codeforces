#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<20;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return (int) (((ll) a * b) % MOD);
}

int eksp(int b, int e) {
  int ret=1;
  for (; e; e /= 2, b = mul(b, b))
    if (e & 1)
      ret = mul(ret, b);
  return ret;
}

int k[MAX];
int n, p;

ll get_value(ll diff, ll pot) {
  if (!diff) return 0;

  ll b = p;
  for (; pot; pot /= 2, b = b*b) {
    if (pot & 1) diff *= b;
    if (diff > MAX || b > MAX) return INF;
  }

  return diff;
}

int main()
{
  int ttt;
  scanf("%d", &ttt);

  while(ttt--) {
    scanf("%d%d", &n, &p);
    REP(i, n) scanf("%d", &k[i]);

    if (p == 1) {
      printf("%d\n", n % 2);
      continue;
    }

    int diff_mod;
    ll diff = 0;
    ll pot = 0;

    sort(k, k+n, greater<int>());
    
    diff_mod = eksp(p, k[0]);
    diff = 1;
    pot = k[0];

    int done = 0;
    FOR(i, 1, n) {
      ll real_diff = get_value(diff, pot - k[i]);
      if (real_diff > MAX) {
        int ans = diff_mod;
        for (int j=i; j<n; j++) 
          ans = sub(ans, eksp(p, k[j]));

        done = 1;
        printf("%d\n", ans);
        break;
      }

      if (real_diff > 0) {
        real_diff--;
        diff_mod = sub(diff_mod, eksp(p, k[i]));
      }
      else {
        real_diff = 1;
        diff_mod = eksp(p, k[i]);
      }

      diff = real_diff;
      pot = k[i];
    }

    if (!done) printf("%d\n", diff_mod);
  }

  return 0;
}