#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
const int INF = (int) 2e9;
int n, a[N];
bool b[N];

int f(int i) {
  if (2 <= i && i < n) {
    if (a[i - 1] < a[i] && a[i + 1] < a[i]) return 1;
    if (a[i - 1] > a[i] && a[i + 1] > a[i]) return 1;
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int sum = 0, ret;
    for (int i = 1; i <= n; i++) {
      sum += f(i);
    }
    ret = sum;
    for (int i = 1; i <= n; i++) {
      vector<int> values = {-INF, +INF};
      if (i >= 2) {
        values.push_back(a[i - 1] - 1);
        values.push_back(a[i - 1] + 1);
        values.push_back(a[i - 1]);
      }
      if (i < n) {
        values.push_back(a[i + 1] - 1);
        values.push_back(a[i + 1] + 1);
        values.push_back(a[i + 1]);
      }
      int initial = a[i];
      for (auto &x : values) {
        sum -= f(i - 1);
        sum -= f(i);
        sum -= f(i + 1);
        a[i] = x;
        sum += f(i - 1);
        sum += f(i);
        sum += f(i + 1);
        ret = min(ret, sum);
      }
      sum -= f(i - 1);
      sum -= f(i);
      sum -= f(i + 1);
      a[i] = initial;
      sum += f(i - 1);
      sum += f(i);
      sum += f(i + 1);
    }
    cout << ret << "\n";
  }
}