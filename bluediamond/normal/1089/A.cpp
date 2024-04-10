#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 200 + 7;
const int WRONG = -(int) 1e9;
const int UND = -99;
int best[N][N][4][4], cnt = 0;
pair<int, int> par[N][N][4][4];

int compute(int a, int b, int s1, int s2) {
  if (s1 == 3) {
    return (a == 0 && b == 0) ? 0 : WRONG;
  }
  if (s2 == 3) {
    return (a == 0 && b == 0) ? 0 : WRONG;
  }
  cnt++;
  if (best[a][b][s1][s2] != UND) return best[a][b][s1][s2];
  int ret = WRONG;
  int need = (s1 + s2 == 4) ? 15 : 25;
  for (int na = 0; na <= min(a, need); na++) {
    for (int nb = 0; nb <= min(b, need); nb++) {
      if (max(na, nb) >= need && abs(na - nb) >= 2) {
        if (na > nb) {
          int x = 1 + compute(a - na, b - nb, s1 + 1, s2);
          if (x > ret) {
            ret = x;
            par[a][b][s1][s2] = {na, nb};
          }
        } else {

          int x = -1 + compute(a - na, b - nb, s1, s2 + 1);
          if (x > ret) {
            ret = x;
            par[a][b][s1][s2] = {na, nb};
          }
        }
      }
    }
  }
  for (int na = need + 1; na <= a; na++) {
    int nb = na - 2;
    if (nb > b) {
      break;
    }
    if (max(na, nb) >= need && abs(na - nb) >= 2) {
      if (na > nb) {
        int x = 1 + compute(a - na, b - nb, s1 + 1, s2);
        if (x > ret) {
          ret = x;
          par[a][b][s1][s2] = {na, nb};
        }
      } else {
        int x = -1 + compute(a - na, b - nb, s1, s2 + 1);
        if (x > ret) {
          ret = x;
          par[a][b][s1][s2] = {na, nb};
        }
      }
    }
  }
  for (int nb = need + 1; nb <= b; nb++) {
    int na = nb - 2;
    if (na > a) {
      break;
    }
    if (max(na, nb) >= need && abs(na - nb) >= 2) {
      if (na > nb) {
        int x = 1 + compute(a - na, b - nb, s1 + 1, s2);
        if (x > ret) {
          ret = x;
          par[a][b][s1][s2] = {na, nb};
        }
      } else {
        int x = -1 + compute(a - na, b - nb, s1, s2 + 1);
        if (x > ret) {
          ret = x;
          par[a][b][s1][s2] = {na, nb};
        }
      }
    }
  }
  /**for (int na = 0; na <= a; na++) {
    for (int nb = 0; nb <= b; nb++) {
      if (max(na, nb) >= need && abs(na - nb) >= 2) {
        if (na > nb) {
          ret = max(ret, 1 + compute(a - na, b - nb, s1 + 1, s2));
        } else {
          ret = max(ret, -1 + compute(a - na, b - nb, s1, s2 + 1));
        }
      }
    }
  }**/
  best[a][b][s1][s2] = ret;
  return best[a][b][s1][s2];
}

vector<pair<int, int>> sol;

void reconst(int a, int b, int s1, int s2) {
  if (s1 == 3 || s2 == 3) {
    return;
  }
  int na = par[a][b][s1][s2].first, nb = par[a][b][s1][s2].second;
  sol.push_back({na, nb});
  reconst(a - na, b - nb, s1 + (na > nb), s2 + (na < nb));
}

signed realMain() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int s1 = 0; s1 < 4; s1++) {
        for (int s2 = 0; s2 < 4; s2++) {
          best[i][j][s1][s2] = UND;
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    int ret = compute(a, b, 0, 0);
    if (ret <= WRONG / 2) {
      cout << "Impossible\n";
      continue;
    }
    sol.clear();
    reconst(a, b, 0, 0);
    cout << (ret + (int) sol.size()) / 2 << ":" << (ret + (int) sol.size()) / 2 - ret << "\n";
    for (auto &it : sol) {
      int na = it.first, nb = it.second;
      cout << na << ":" << nb << " ";
    }
    cout << "\n";
  }
  return 0;
}