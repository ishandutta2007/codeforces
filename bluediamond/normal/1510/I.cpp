#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

///signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}
/**

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
}**/

const int N = 10000 + 7;
///const int C = 10;
int C = 100;
int n, m, matching[N], now[N];
int tricked[N], lazy[N];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
      now[i] = s[i - 1] - '0';
    }
    int s0 = 0, s1 = 0;
    for (int j = 1; j <= n; j++) {
      if (now[j] == 0) s0 += matching[j];
      else s1 += matching[j];
    }
    int me = (s1 >= s0);
    lazy[i] = 0;
    if (i - 1 >= C) {
      int cu = 0, fara = 0;
      for (int j = 0; j < C; j++) {
        int id = i - j - 1;
        if (tricked[id]) {
          cu++;
        } else {
          fara++;
        }
      }
      fara = C - cu;
      if (cu > fara) {
        lazy[i] = 1;
        me ^= 1;
      }
    }
    cout << me << endl;
    int sol;
    cin >> sol;
    tricked[i] = ((s1 >= s0) != sol);
    for (int i = 1; i <= n; i++) {
      matching[i] += (now[i] == sol);
    }
  }
  if (home) {
    for (int j = 1; j <= n; j++) {
      cout << matching[j] << " ";
    }
  }

  return 0;
}