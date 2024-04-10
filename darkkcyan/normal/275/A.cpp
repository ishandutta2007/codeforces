#include <bits/stdc++.h>
using namespace std;

int a[5][5] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (int i = 0; i ++ < 3; ) for (int f = 0; f ++ < 3; ) {
    int u; cin >> u;
    for (auto g: vector<pair<int, int>>({{-1, 0}, {0, 0}, {1, 0}, {0, -1}, {0, 1}}))
      a[i + g.first][f + g.second] ^= u & 1;
  }
  for (int i = 0; i ++ < 3;) {
    for (int f = 0; f ++ < 3; ) cout << !a[i][f];
    cout << '\n';
  }

  return 0;
}