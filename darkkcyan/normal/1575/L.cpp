#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int maxn = 201010;
int n;
int a[maxn];

struct BIT {
  vector<int> data;

  BIT(int len) : data(len + 10) {}

  void upd(int i, int u) {
    for (++i; i < (int) data.size(); i += i & -i)
      data[i] = max(data[i], u);
  }

  int get(int i) const {
    int ans = 0;
    for (++i; i > 0; i -= i & -i)
      ans = max(ans, data[i]);
    return ans;
  }
};

//int solve() {
//
//}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> b;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b.emplace_back(i - a[i], a[i]);
  }

  sort(b.begin(), b.end());

  BIT bit(maxn);
  int ans = 0;
  for (auto [x, y]: b) {
    if (x < 0) continue;
    auto cur = bit.get(y - 1) + 1;
//    cout << x << ' ' << y << ' ' << cur << endl;
    ans = max(ans, cur);
    bit.upd(y, cur);
  }

  cout << ans;

  return 0;
}