#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

// #define int ll
#define int ll

const ld eps = 1e-14;

ld getpwin(ld total, ld good) {
  ld bad = total - good;
  ld sol = 0;
  if (good >= 3) { /// 3 good, 0 bad
    ld prob = 1;
    prob *= good / total;
    prob *= (good - 1) / (total - 1);
    prob *= (good - 2) / (total - 2);
    sol += prob;
  }

  if (good >= 2 && bad >= 1) { /// 2 good, 1 bad
    ld prob = 1;
    prob *= good / total;
    prob *= (good - 1) / (total - 1);
    prob *= bad / (total - 2);
    sol += prob * 3; /// * 3??
  }
  if (good >= 1 && bad >= 2) { /// 1 good, 2 bad

    /// G B B
    /// | | |

    ld prob = 1;
    prob *= good / total;
    prob *= bad / (total - 1);
    prob *= (bad - 1) / (total - 2);

    prob *= ((ld) 1 / (ld) 3 + (ld) 1 / (ld) 6);

    sol += prob * 3;
  }



  return sol;
}

int n;
ld p;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n >> p;


  for (int i = 0; i <= n; i++) {
    if (getpwin(n, i) - p >= -eps) {
      cout << i << "\n";
      return 0;
    }
  }

  return 0;
}