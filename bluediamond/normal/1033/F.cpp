#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int long long
typedef long long ll;
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

int p3[100];
int w, n, m, f[531441 + 7], ret, sg[531441 + 7];
string s;

int op(int x, int y, char c) {
  if (c == 'A') return (x & y);
  if (c == 'O') return (x | y);
  if (c == 'X') return (x ^ y);
  if (c == 'a') return !(x & y);
  if (c == 'o') return !(x | y);
  if (c == 'x') return !(x ^ y);
  assert(0);
}

void bkt(int p, int sum) {
  if (p == w) {
    ret += f[sum];
    return;
  }
  char c = s[p];
  int b1 = 0, b2 = 0;
  for (int s = 0; s <= 2; s++) {
    if (s == 0) {
      b1 = b2 = 0;
    } else {
      b1 = 1;
      b2 = s - b1;
    }
    if (op(b1, b2, c) == 0) {
      bkt(p + 1, sum + p3[p] * s);
    }
  }
}

signed realMain() {
  p3[0] = 1;
  for (int i = 1; i < 100; i++) p3[i] = 3 * p3[i - 1];
  cin >> w >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int y = 0;
    for (int j = 0; j < w; j++) {
      if (x & (1 << j)) y += p3[j];
    }
    sg[y]++;
  }
  vector<int> kek;
  for (int i = 0; i < p3[w]; i++) if (sg[i]) kek.push_back(i);
  for (auto &i : kek) {
    for (auto &j : kek) {
      f[i + j] += sg[i] * sg[j];
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> s;
    reverse(s.begin(), s.end());
    ret = 0;
    bkt(0, 0);
    cout << ret << "\n";
  }
  return 0;
}