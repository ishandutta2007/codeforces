#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 5000 + 7;
const int INF = (int) 1e18;
int n, x[N], a[N], b[N], c[N], d[N];
vector<int> sol(2);

int f(int i, int j) {
  if (j < i) {
    return abs(x[i] - x[j]) + c[i] + b[j];
  } else {
    return abs(x[i] - x[j]) + d[i] + a[j];
  }
}

signed main() {
  cin >> n >> sol[0] >> sol[1];
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) cin >> d[i];
  for (int i = 1; i <= n; i++) {
    if (i == sol[0] || i == sol.back()) continue;
    int bestDelta = (int) 1e18, id = -1;
    for (int j = 0; j + 1 < (int) sol.size(); j++) {
      int curDelta = f(sol[j], i) + f(i, sol[j + 1]) - f(sol[j], sol[j + 1]);
      if (curDelta < bestDelta) {
        id = j;
        bestDelta = curDelta;
      }
    }
    vector<int> ret;
    for (int j = 0; j < (int) sol.size(); j++) {
      ret.push_back(sol[j]);
      if (j == id) {
        ret.push_back(i);
      }
    }
    sol = ret;
  }
  int ret = 0;
  for (int i = 1; i < n; i++) ret += f(sol[i - 1], sol[i]);
  cout << ret << "\n";
  return 0;
}