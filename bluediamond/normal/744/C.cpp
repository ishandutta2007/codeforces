#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 16;
const int INF = (int) 1e9;
int n, type[N], red[N], blue[N], addToCost, sol, dpRed[1 << N][N * N + 7], dpBlue[1 << N][N * N + 7], cntRed[1 << N], cntBlue[1 << N];

void upd(int &a, int x) {
  a = min(a, x);
}

void propag(int mask, int extraRed, int extraBlue, int val) {
  if (val == INF) return;

///  cout << " = " << mask << ", " << extraRed << " " << extraBlue << " and " << val << "\n";

  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) {
      int nmask = mask + (1 << i);
      int needRed = max(0, red[i] - cntRed[mask] - extraRed);
      int needBlue = max(0, blue[i] - cntBlue[mask] - extraBlue);

      int newRed = extraRed + max(needRed, needBlue) - max(0, red[i] - cntRed[mask]);
      int newBlue = extraBlue + max(needRed, needBlue) - max(0, blue[i] - cntBlue[mask]);

      ///cout << newRed + extraRed << " and " << max(0, red[i] - cntRed[mask]) << "\n";
      ///cout << newBlue + extraBlue << " and " << max(0, blue[i] - cntBlue[mask]) << "\n\n";

      //assert(newRed + extraRed >= max(0, red[i] - cntRed[mask]));
      //assert(newBlue + extraBlue >= max(0, blue[i] - cntBlue[mask]));
    ////  cout << " = " << newRed << " and " << newBlue << "\n";

      assert(newRed >= 0 && newBlue >= 0);
      assert(newRed == 0 || newBlue == 0);

      upd(dpRed[mask + (1 << i)][newRed], val + max(needRed, needBlue));
      upd(dpBlue[mask + (1 << i)][newBlue], val + max(needRed, needBlue));
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int eRed = 0, eBlue = 0;
  cin >> n;
  addToCost += n;
  vector<vector<int>> vec;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s >> red[i] >> blue[i];
    type[i] = (s == "B" ? 0 : 1);
    eRed += max(0, red[i] - n);
    eBlue += max(0, blue[i] - n);
    red[i] = min(red[i], n);
    blue[i] = min(blue[i], n);
  }

  /**
  cout << " = " << addToCost << "\n";
  for (int i = 0; i < n; i++) {
    cout << type[i] << " : " << red[i] << " and " << blue[i] << "\n";
  }**/

  for (int mask = 0; mask < (1 << N); mask++) {
    for (int j = 0; j < N * N + 7; j++) {
      dpRed[mask][j] = dpBlue[mask][j] = INF;
    }
  }

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        cntRed[mask] += (type[i] == 1);
        cntBlue[mask] += (type[i] == 0);
      }
    }
  }

  dpRed[0][0] = dpBlue[0][0] = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int x = 0; x <= n * n; x++) {
      propag(mask, x, 0, dpRed[mask][x]);
      propag(mask, 0, x, dpBlue[mask][x]);
    }
  }
  int mn = min(eRed, eBlue);
  eRed -= mn;
  eBlue -= mn;
  addToCost += mn;

  sol = INF;
  for (int j = 0; j <= n * n; j++) {
    int cost = dpRed[(1 << n) - 1][j];

    sol = min(sol, dpRed[(1 << n) - 1][j] + eBlue + max(0, eRed - j));
    sol = min(sol, dpBlue[(1 << n) - 1][j] + eRed + max(0, eBlue - j));
  }
  cout << sol + addToCost << "\n";
  return 0;
}