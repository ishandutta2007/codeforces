#include <bits/stdc++.h>

using namespace std;

int st, dr, p, q, sol, reduction, coef, mod;

int f(int i) {
  return 1LL * i * coef % mod;
}

int getDist(int x) {
  x %= mod;
  if (x < 0) x += mod;
  return min(x, mod - x);
}

void relax(int x) {
  int dist_x = abs(f(x) - q);
  int dist_sol = abs(f(sol) - q);
  if (dist_x == dist_sol) {
    if (x < sol) {
      sol = x;
    }
    return;
  }
  if (dist_x < dist_sol) {
    sol = x;
  }
}

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE
  /// aplic jmen-ul cu radicalical

  int tests;
  cin >> tests;

  for (int tc = 1; tc <= tests; tc++) {

    cin >> st >> dr >> p >> q;

    reduction = __gcd(p, q);
    p /= reduction;
    q /= reduction;

    coef = 2 * p;
    mod = 2 * q;

    sol = st;

    int radical = sqrt(dr - st + 1) + 3;

    map<int, int> MAP_best;

    for (int j = 0; j < radical; j++) {
      int now = 1LL * j * coef % mod;
      if (!MAP_best.count(now)) {
        MAP_best[now] = j;
      }
    }

    vector<pair<int, int>> best;
    for (auto &it : MAP_best) {
      best.push_back(it);
    }

    while (st + radical - 1 <= dr) {
      int low = st, high = st + radical - 1;
      int target = (mod - (1LL * low * coef % mod + mod - q) % mod) % mod;

      int cnt_under = 0, lw = 0, hg = (int) best.size() - 1;

      while (lw <= hg) {
        int mid = (lw + hg) / 2;
        if (best[mid].first <= target) {
          cnt_under = mid + 1;
          lw = mid + 1;
        } else {
          hg = mid - 1;
        }
      }

      for (int r = cnt_under - 2; r <= cnt_under + 2; r++) {
        int pz = (r % (int) best.size() + (int) best.size()) % (int) best.size();
        int j = best[pz].second;
        int val = 1LL * j * coef % mod;
        relax(low + j);
      }

      st += radical;
    }

    for (int i = st; i <= dr; i++) {
      relax(i);
    }
    cout << sol << "\n";
  }
  exit(0);
}