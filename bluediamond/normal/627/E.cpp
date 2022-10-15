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

#define prev prvvvvvvvvvvvvvvvvvvvvvv

const int N = 3000 + 7;
int h, w, pts, k, totalitate[N], acum[N], pt[N], sol, nxt[N], prev[N];
vector<int> pos[N];

void del(int i) {
  nxt[prev[i]] = nxt[i];
  prev[nxt[i]] = prev[i];
}

signed realMain() {
  cin >> h >> w >> pts >> k;
  for (int i = 1; i <= pts; i++) {
    int r, c;
    cin >> r >> c;
    pos[r].push_back(c);
  }
  totalitate[0] = k + 1;
  totalitate[w + 1] = k + 1;
  for (int lo = h; lo >= 1; lo--) {
    for (auto &j : pos[lo]) {
      totalitate[j]++;
    }
    for (int j = 0; j <= w + 1; j++) {
      acum[j] = totalitate[j];
      prev[j] = j - 1;
      nxt[j] = j + 1;
    }
    for (int j = 1; j <= w; j++) {
      if (!acum[j]) {
        del(j);
      }
    }
    int cur = 0;
    {
      int j = 1, sum = acum[1];
      for (int i = 1; i <= w; i++) {
        while (sum < k) {
          j++;
          sum += acum[j];
        }
        pt[i] = j;
        cur += w + 1 - pt[i];
        sum -= acum[i];
      }
    }
    for (int hi = h; hi >= lo; hi--) {
      sol += cur;
      for (auto &j : pos[hi]) {
        /// o sa creasca pt-ul dar imi pasa doar de pozitiile nenule. trebuie sa scad din cur atat cat creste pt-ul
        int lft = j, rgh = j, sumlft = acum[j], sumrgh = 0;

        while (sumlft + sumrgh + acum[nxt[rgh]] <= k) {
          rgh = nxt[rgh];
          sumrgh += acum[rgh];
        }

        while (1) {

          /// recompute for lft
          /// daca e mai > k nu e pb ca tot o sa ramana asa...
          if (sumlft + sumrgh == k) {
            cur -= (lft - prev[lft]) * (nxt[rgh] - rgh);
          }
          lft = prev[lft];
          sumlft += acum[lft];
          if (sumlft > k) {
            break;
          }
          while (sumlft + sumrgh > k) {
            sumrgh -= acum[rgh];
            rgh = prev[rgh];
          }
        }

        acum[j]--;
        if (!acum[j]) {
          del(j);
        }
      }
    }
  }
  cout << sol << "\n";
  return 0;
}