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
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

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

const int N = 500000 + 7;
const int H = 60 + 7;
int q, n = 1, par[N], path[N], sz;
ld prob[N][H];

signed realMain() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < H; j++) prob[i][j] = 1;
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int paps, cur;
      cin >> paps;
      cur = paps;
      par[++n] = paps;
      sz = 0;
      while (cur && sz <= 61) {
        path[++sz] = cur;
        cur = par[cur];
      }
      /// update prob[path[j]][j]
      for (int j = sz - 1; j >= 1; j--) {
        prob[path[j + 1]][j + 1] /= (0.5 + 0.5 * prob[path[j]][j]);
      }
      prob[paps][1] *= 0.5;
      for (int j = 1; j <= sz - 1; j++) {
        prob[path[j + 1]][j + 1] *= (0.5 + 0.5 * prob[path[j]][j]);
      }
    } else {
      int no;
      cin >> no;
      ld sol = 0;
      for (int j = 1; j < H; j++) {
        sol += (ld) 1 - prob[no][j];
      }
      cout << fixed << setprecision(6) << sol << "\n";
    }
  }
  return 0;
}