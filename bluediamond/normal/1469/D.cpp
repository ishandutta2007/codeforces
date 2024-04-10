#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = (int) 2e5 + 7;
int n;
int a[N];
vector<pair<int, int>> sol;

void op(int i, int j) {
  sol.push_back({i, j});
  if (a[i] % a[j]) {
    a[i] = a[i] / a[j] + 1;
  } else {
    a[i] = a[i] / a[j];
  }
}

bool t[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int Tt;
  cin >> Tt;
  while (Tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      t[i] = 0;
    }
    int x = n;
    while (x > 1) {
      t[x] = 1;
      if (x == 2) {
        break;
      }
      int y = sqrt(x);
      if (y * y == x) {
        x = y;
      } else {
        x = y + 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    sol.clear();
    for (int i = 2; i <= n; i++) {
      if (!t[i]) {
        op(i, n);
      }
    }
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
      if (t[i]) {
        nums.push_back(i);
      }
    }
    for (int i = (int) nums.size() - 1; i > 0; i--) {
      op(nums[i], nums[i - 1]);
      op(nums[i], nums[i - 1]);
    }
    assert((int) sol.size() <= n + 5);
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
      c1 += (a[i] == 1);
      c2 += (a[i] == 2);
    }
    assert(c1 == n - 1);
    assert(c2 == 1);
    cout << (int) sol.size() << "\n";
    for (auto &it : sol) {
      cout << it.first << " " << it.second << "\n";
    }
  }
}