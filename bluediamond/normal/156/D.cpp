#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll

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

int mod;

int rep(int x) {
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

int mul(int a, int b) {
  return rep(a * b);
}

const int N = (int) 1e5 + 7;
int n, m, k, t[N], cnt[N];

int root(int a) {
  if (t[a] == a) return a;
  return t[a] = root(t[a]);
}

signed realMain() {
  cin >> n >> m >> mod;
  if (mod == 1) {
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) t[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    t[root(x)] = root(y);
  }
  for (int i = 1; i <= n; i++) {
    cnt[root(i)]++;
  }
  vector<int> comps;
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) comps.push_back(cnt[i]);
  }
  if ((int) comps.size() == 1) {
    cout << "1\n";
    return 0;
  }
  int ret = 1;
  for (int j = 1; j <= (int) comps.size() - 2; j++) {
    ret = mul(ret, n);
  }
  for (auto &sz : comps) {
    ret = mul(ret, sz);
  }
  cout << ret << "\n";
  return 0;
}