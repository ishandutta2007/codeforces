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

int kek;
bool acum;
time_t bg, nd;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  bg = clock();
  realMain();
}

const int N = (int) 4e5 + 7; 
const int INF = (int) 1e18;
int n, c, s[N], pre[N], sol[N], p = 0, best = -INF;
deque<int> dq;

int eval(int j) {
  return sol[j - 1] - pre[2 * j - 2];
}

signed realMain() {
  cin >> n >> c;
  for (int i = 1; i <= 2 * n - 1; i++) {
    cin >> s[i];
    pre[i] = pre[i - 1] + s[i];
  }
  for (int i = 1; i <= n; i++) {
    while (p + 1 <= i && pre[2 * i - 1] - pre[2 * (p + 1) - 2] >= c) {
      p++;
      best = max(best, sol[p - 1]);
    }
    while (!dq.empty() && dq.front() <= p) {
      dq.pop_front();
    }
    while (!dq.empty() && eval(i) > eval(dq.back())) {
      dq.pop_back();
    }
    dq.push_back(i);
    int kek = -INF, val = 0;
    val = max(val, best + c - sol[i - 1]);
    kek = -INF;
    if (p + 1 <= i) {
      kek = eval(dq.front());
    }

    val = max(val, kek + pre[2 * i - 1] - sol[i - 1]);
    sol[i] = sol[i - 1] + val;
  }
  cout << sol[n] << "\n";
  return 0;
}