#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
const int N = 40;
int n, h;
ll ans[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> h;
  ans[1][1] = 1;

  for (int cnt = 2; cnt <= n; cnt++) {
    for (int h = 1; h <= n; h++) {
      ans[cnt][h] = 2 * ans[cnt - 1][h - 1];
      for (int a = 1; a + 1 < cnt; a++) {
        int b = cnt - a - 1;
        for (int ha = 1; ha <= h - 1; ha++) {
          for (int hb = 1; hb <= h - 1; hb++) {
            if (ha == h - 1 || hb == h - 1) {
              ans[cnt][h] += ans[a][ha] * ans[b][hb];
            }
          }
        }
      }
    }
  }
  ll sol = 0;
  for (int rh = h; rh <= n; rh++) {
    sol += ans[n][rh];
  }
  cout << sol << "\n";

}