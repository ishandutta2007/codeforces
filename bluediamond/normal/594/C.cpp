#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Magnet {
  int x;
  int y;
};

bool operator < (Magnet a, Magnet b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  return a.y < b.y;
}

const ll INF = (ll) 1e18;
const int N = (int) 1e5 + 7;
int n;
int k;
Magnet magnets[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> k;
  if (n == k) {
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    magnets[i] = {x1 + x2, y1 + y2};
  }

  sort(magnets + 1, magnets + n + 1);

  ll sol = (ll) 4e18 + 7;

  for (int l = 1; l <= n; l++) {
    for (int r = n; r >= l && l - 1 + n - r <= k; r--) {

      int outcasts = k - (l - 1 + n - r);
      vector<int> ys;
      for (int i = l; i <= r; i++) {
        ys.push_back(magnets[i].y);
      }
      sort(ys.begin(), ys.end());
      int rem = (int) ys.size() - outcasts;


      ll difx = magnets[r].x - magnets[l].x;
      ll dify = (ll) 1e18;
      for (int j = 0; j + rem - 1 < (int) ys.size(); j++) {
        dify = min(dify, (ll) ys[j + rem - 1] - ys[j]);
      }
      difx = max(difx, 2LL);
      dify = max(dify, 2LL);
      sol = min(sol, difx * dify);
    }
  }

  assert(sol % 4 == 0);
  sol /= 4;
  cout << sol << "\n";


  return 0;
}