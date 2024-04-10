#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 400000 + 7;
const int K = 20;
int cntq, last, a[N], n = 1, mx[K][N], anc[K][N], spre[K][N], sum[K][N], dep[N];

signed realMain() {
  cin >> cntq;
  dep[1] = 1;
  for (int iq = 1; iq <= cntq; iq++) {
    int tp, p, q;
    cin >> tp >> p >> q;
    p ^= last;
    q ^= last;
    if (tp == 1) {
      n++;
      a[n] = q;
      /// anc(?, n)
      anc[0][n] = p;
      for (int k = 1; k < K; k++) {
        anc[k][n] = anc[k - 1][anc[k - 1][n]];
      }
      /// mx(?, n)
      mx[0][n] = a[n];
      for (int k = 1; k < K; k++) {
        mx[k][n] = max(mx[k - 1][n], mx[k - 1][anc[k - 1][n]]);
      }
      int vertex = p;
      for (int k = K - 1; k >= 0; k--) {
        if (mx[k][vertex] < a[n]) {
          vertex = anc[k][vertex];
        }
      }
      if (a[vertex] < a[n]) {
        vertex = anc[0][vertex];
      }
      /// spre(?, n)
      dep[n] = 1 + dep[vertex];
      spre[0][n] = vertex;
      for (int k = 1; k < K; k++) {
        spre[k][n] = spre[k - 1][spre[k - 1][n]];
      }
      /// sum(?, n)
      sum[0][n] = a[n];
      for (int k = 1; k < K; k++) {
        sum[k][n] = sum[k - 1][n] + sum[k - 1][spre[k - 1][n]];
      }
    } else {
      bool now = (iq == cntq);
      int sol = 0;
      for (int k = K - 1; p && k >= 0; k--) {
       // cout << "aici : " << k << "\n";
        if (dep[p] < (1 << k)) {
          continue;
        }
        if (q >= sum[k][p]) {
          q -= sum[k][p];
          sol += (1 << k);
          p = spre[k][p];
        }
      }
      last = sol;
      cout << sol << "\n";
    }
  }
  return 0;
}