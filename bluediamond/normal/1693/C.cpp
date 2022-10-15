#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
const int INF = (int) 1e9 + 7;
int n;
int m;
int dp[N];
int need_to_block[N];
vector<int> g[N];
vector<int> ginv[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    ginv[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    dp[i] = INF;
    need_to_block[i] = (int) g[i].size() - 1;
  }

  priority_queue<pair<int, int>> Q;
  dp[n] = 0;
  Q.push({-dp[n], n});


  while (!Q.empty()) {
    auto it = Q.top();
    Q.pop();
    int dist = -it.first;
    int a = it.second;
    if (dp[a] != dist) {
      continue;
    }
    for (auto &b : ginv[a]) {
      /// le tai pe alea mai proaste decat b
      int relax = 1 + dp[a] + need_to_block[b];

      if (relax < dp[b]) {
        dp[b] = relax;
        Q.push({-dp[b], b});
      }

      /// acum pe asta nu mai trebuie sa il tai
      need_to_block[b]--;
    }
  }


  cout << dp[1] << "\n";


}


/**

**/