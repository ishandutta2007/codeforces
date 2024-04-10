#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = (int) 1e6 + 7;
int n, v[N], cur, dp[N], pre[N];
string s;
map<int, int> last;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  for (auto &ch : s) {
    if (ch == '0') {
      cur++;
    } else {
      v[++n] = cur;
      cur = 0;
    }
  }
  if (n == 0) {
    cout << cur << "\n";
    return 0;
  }
  /// keep a stack
  dp[1] = v[1] + 1;
  pre[1] = dp[1];
  last[v[1]] = last[M] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = mul(pre[i - 1], v[i] + 1);
    for (int x = 0; x <= v[i]; x++) {
      dp[i] = add(dp[i], -pre[last.lower_bound(x)->second - 1]);
    }
    while (!last.empty() && last.begin()->first <= v[i]) {
      last.erase(last.begin());
    }
    last[v[i]] = i;
    pre[i] = add(pre[i - 1], dp[i]);
  }
  cout << mul(pre[n], cur + 1) << "\n";
  return 0;
}