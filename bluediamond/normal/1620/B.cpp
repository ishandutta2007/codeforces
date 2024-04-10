#include <bits/stdc++.h>

using namespace std;

///#define int ll
typedef long long ll;
typedef long double ld;

#define int ll

void rd(vector<int> &v) {
  int l;
  cin >> l;
  v.resize(l);
  for (auto &x : v) {
    cin >> x;
  }
}

struct pt {
  int x, y;
};

int area(pt a, pt b) {
  return (a.x - b.x) * (a.y + b.y);
}

int area(pt a, pt b, pt c) {
  return abs(area(a, b) + area(b, c) + area(c, a));
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

//  freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> w >> h;
    vector<int> y0, yh, x0, xw;
    rd(y0);
    rd(yh);
    rd(x0);
    rd(xw);

    vector<vector<pt>> a(4);
    for (auto &it : y0) a[0].push_back({it, 0});
    for (auto &it : yh) a[1].push_back({it, h});
    for (auto &it : x0) a[2].push_back({0, it});
    for (auto &it : xw) a[3].push_back({w, it});


    int sol = 0;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) {
          continue;
        }
        for (auto &lol : a[i]) {
          sol = max(sol, area(lol, a[j][0], a[j].back()));
        }
      }
    }
    cout << sol << "\n";

  }

  return 0;
}