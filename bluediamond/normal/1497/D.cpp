#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 5000 + 7;
const int INF = (int) 1e18;
int n, tag[N], s[N], mx[N];
vector<int> val;

void algo(int now, int to) {
  if (tag[now] == tag[to]) {
    return;
  }
  val.push_back(-INF);
  val.back() = mx[now];
 /** for (int ant = 1; ant <= n; ant++) {
    val.back() = max(val.back(), dp[ant][now]);
  }
  assert(val.back() == mx[now]);**/
  val.back() += abs(s[now] - s[to]);
}

signed realMain() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> tag[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
      mx[i] = -INF;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      mx[i] = max(mx[i], 0LL);
      for (int j = i - 1; j >= 1; j--) {
        if (tag[i] == tag[j]) {
          continue;
        }
        val.clear();
        algo(i, j);
        algo(j, i);
        mx[j] = max(mx[j], val[0]);
        mx[i] = max(mx[i], val[1]);
        ret = max(ret, val[0]);
        ret = max(ret, val[1]);
      }
    }
    cout << ret << "\n";
 //   return 0;
  }
}