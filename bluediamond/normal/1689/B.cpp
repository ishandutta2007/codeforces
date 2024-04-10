#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
int n, p[N], sol[N];
bool done, av[N];

void bkt(int pos) {
  if (done) return;

  if (pos > n) {
    assert(pos == n + 1);
    done = 1;
    for (int i = 1; i <= n; i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int x = 1; x <= n; x++) {
    if (av[x] && x != p[pos]) {
      sol[pos] = x;
      av[x] = 0;
      bkt(pos + 1);
      av[x] = 1;
      if (done) {
        return;
      }
    }
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    done = 0;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      av[i] = 1;
    }
    bkt(1);
    if (!done) {
      cout << "-1\n";
    }
  }
}