#include <bits/stdc++.h>

using namespace std;

bool home = 1;
const int N = (int)2e5 + 7;
const int K = 20;
int n, v[N], num[K];

bool print;

bool add(int x) {
  for (int i = K - 1; i >= 0; i--) {
    if (x & (1 << i)) {
      x ^= num[i];
    }
  }
  if (x == 0) {
    return 0; /// obtainable
  }
  for (int i = K - 1; i >= 0; i--) {
    if (x & (1 << i)) {
      if (num[i] == 0) {
        num[i] = x;
        return 1;
      }
    }
  }
  assert(0);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  vector<int> xorable;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (add(v[i])) {
      xorable.push_back(v[i]);
    }
  }

  int ninit = n;

  int n = (int)xorable.size();
  set<int> possible;
  map<int, int> inv, rinv;
  vector<int> cop = xorable;
  vector<int> totos;
  for (int mask = 0; mask < (1 << n); mask++) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        ret ^= xorable[i];
      }
    }
    possible.insert(ret);
    inv[mask] = ret;
    rinv[ret] = mask;
    cop.push_back(ret);
  }

  int sz = 1, pw = 0;
  while (1) {
    int dubsz = 2 * sz;
    bool ok = 1;
    for (int i = sz; i < dubsz && ok; i++) {
      ok &= (possible.count(i));
    }
    if (!ok) {
      break;
    }
    sz = dubsz;
    pw++;
  }
  for (int i = 0; i < K; i++) {
    num[i] = 0;
  }
  xorable.clear();
  print = 1;
  for (int i = 1; i <= ninit; i++) {
    int x = v[i];
    if (x < sz) {
      if (add(x)) {
        xorable.push_back(x);
      }
    }
  }
  pw = (int) xorable.size();
  vector<int> sol = { 0 };
  for (int p = 0; p < pw; p++) {
    for (int i = (1 << p) - 1; i >= 0; i--) {
      sol.push_back(sol[i] ^ xorable[p]);
    }
  }
  cout << pw << "\n";
  for (auto& x : sol) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}