#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, m, a[N];

vector<int> get_divs(int num) {
  vector<int> sol;
  for (int i = 1; i * i < num; i++) {
    if (num % i == 0) {
      sol.push_back(i);
      sol.push_back(num / i);
    }
  }
  int i = sqrt(num);
  if (i * i == num) {
    sol.push_back(i);
  }
  return sol;
}

bool ok(int dif) {
  for (int i = 1; i <= n; i++) {
    if ((a[i] - 1) % dif) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  vector<int> divs = get_divs(a[1] - 1);
  for (auto &dif : divs) {
    if (dif % 2 == 1 && ok(dif)) {
      for (int d = dif; d <= m; d *= 2) {
        ans += m - d;
      }
    }
  }
  cout << ans << "\n";
}