#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, a[N], ans[N];
vector<int> pt[N];
vector<int> rev[N];

int aib[N];

void add(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int get(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n; i >= 1; i--) {
    rev[a[i]].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    if (!rev[i].empty()) {
      int first = rev[i].back();
      add(first, + 1);
    }
  }

  for (int i = 1; i <= n; i++) {
    pt[1].push_back(i);
  }

  for (int l = 1; l <= n; l++) {

    for (auto &cnt : pt[l]) {
      int sol = 0, cur = 0;
      for (int step = (1 << 20); step > 0; step /= 2) {
        if (sol + step <= n && cur + aib[sol + step] <= cnt) {
          sol += step;
          cur += aib[sol];
        }
      }
      assert(sol != -1);
      ans[cnt]++;
      pt[sol + 1].push_back(cnt);
    }
    pt[l].clear();

    int first = rev[a[l]].back();
    add(first, -1);
    rev[a[l]].pop_back();

    if (!rev[a[l]].empty()) {
      first = rev[a[l]].back();
      add(first, +1);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}