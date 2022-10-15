#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> kek[4];
bool ok[4];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      kek[(i + j) % 2 + 1].push_back({i, j});
    }
  }
  for (int it = 1; it <= n * n; it++) {
    ok[1] = ok[2] = ok[3] = 1;
    int blo;
    cin >> blo;
    ok[blo] = 0;
    if (ok[1] && !kek[1].empty()) {
      cout << 1 << " " << kek[1].back().first << " " << kek[1].back().second << endl;
      kek[1].pop_back();
      continue;
    }
    if (ok[2] && !kek[2].empty()) {
      cout << 2 << " " << kek[2].back().first << " " << kek[2].back().second << endl;
      kek[2].pop_back();
      continue;
    }
    assert(kek[1].empty() || kek[2].empty());
    if (!kek[1].empty()) {
      cout << 3 << " " << kek[1].back().first << " " << kek[1].back().second << endl;
      kek[1].pop_back();
    } else {
      cout << 3 << " " << kek[2].back().first << " " << kek[2].back().second << endl;
      kek[2].pop_back();
    }
  }
  return 0;
}