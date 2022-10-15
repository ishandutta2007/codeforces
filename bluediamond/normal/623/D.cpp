#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
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

const int N = 100 + 7;
const int K = 300000 + 7; /// this looks dumb but ok :))
int n;
int cnt[N];
ld pfail[N];
ld curfail[N];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> pfail[i];
    pfail[i] = 100 - pfail[i];
    pfail[i] /= (ld) 100;
    curfail[i] = 1;
  }
  ld p = 1, ret = 0;
  for (int i = 1; i <= n; i++) {
    curfail[i] *= pfail[i];
    cnt[i]++;
    p *= (1 - curfail[i]);
  }
  ld ant = 0;
  for (int step = n; step < K; step++) {
    ret += (ld) step * (p - ant);
    ld bestcoef = -1;
    int j = -1;
    for (int i = 1; i <= n; i++) {
      ld cur = (1 - curfail[i] * pfail[i]) / (1 - curfail[i]);
      if (cur > bestcoef) {
        bestcoef = cur;
        j = i;
      }
    }

    assert(j != -1);

    ant = p;
    p *= bestcoef;
    curfail[j] *= pfail[j];
    cnt[j]++;
  }
  cout << fixed << setprecision(6) << ret << "\n";
  return 0;
}