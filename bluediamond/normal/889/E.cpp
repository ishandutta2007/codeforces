#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

///#pragma GCC target("avx2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 200000 + 7;
int n, a[N];
map<int, int> memo;

/**

la pasul i: memo[x] = ceva => am dp[i][y] = y * i + memo[x]  | pentru fiecare y=0...x

**/

void rec(int a, int relax) {
  memo[a] = max(memo[a], relax);
}

int getdp(int i, int x) {
  int ret = 0;
  for (auto &it : memo) {
    if (x <= it.first) {
      ret = max(ret, i * x + it.second);
    }
  }
  return ret;
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = 1;
  memo[a[1] - 1] = 0;
  for (int i = 2; i <= n + 1; i++) {
    int mod = a[i];
    while (1) {
      auto it = memo.end();
      it--;
      if (it->first < mod) {
        break;
      }
      int pre = it->first, add = it->second;
      memo.erase(it);
      rec(pre % mod, add + (pre / mod) * mod * (i - 1));
      if (pre % mod != mod - 1) {
        pre = pre - pre % mod - 1;
      }
      rec(pre % mod, add + (pre / mod) * mod * (i - 1));
    }
  }
  cout << memo[0] << "\n";
  return 0;
}