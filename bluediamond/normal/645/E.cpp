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

const int N = (int) 2e6 + 7;
const int K = 26;
int n, m, k, last[K], a[N], dp[N], pre[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;

  {
    string str;
    cin >> str;
    m = (int) str.size();
    for (int i = 1; i <= m; i++) {
      a[i] = str[i - 1] - 'a';
      last[a[i]] = i;
    }
  }

  vector<int> cyc;
  {
    vector<pair<int, int>> v;
    for (int j = 0; j < k; j++) {
      v.push_back({last[j], j});
    }
    sort(v.begin(), v.end());
    for (auto &it : v) {
      cyc.push_back(it.second);
    }
  }

  int y = 0;
  for (int i = m + 1; i <= m + n; i++) {
    a[i] = cyc[y++ % k];
  }
  n += m;

  for (int i = 0; i < k; i++) {
    last[i] = 0;
  }
  dp[0] = 1;
  pre[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (last[a[i]] == 0) {
      dp[i] = pre[i - 1];
    } else {
      dp[i] = add(pre[i - 1], -pre[last[a[i]] - 1]);
    }
    last[a[i]] = i;
    pre[i] = add(pre[i - 1], dp[i]);
  }
  cout << pre[n] << "\n";
  return 0;

  cout << " : ";
  for (int i = 1; i <= n; i++) {
    cout << (char) ('a' + a[i]);
  }
  cout << "\n";

  return 0;
}