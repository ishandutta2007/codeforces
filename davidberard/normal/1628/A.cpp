#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int RT = 450;
const int N = RT * RT;

int have[N];

int n;
int a[N];
int b[N];
int revmex[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> n;
    memset(have, 0, sizeof(int)*(n+5));
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
    }
    int mx = 0;
    for (int i=n; i>=1; --i) {
      have[a[i]] = 1;
      while (have[mx]) {
        ++mx;
      }
      revmex[i] = mx;
    }

    int s = 1;
    int idx = 1;
    while (s <= n) {
      if (revmex[s] == 0) {
        b[idx] = 0;
        ++idx;
        ++s;
        continue;
      }
      memset(have, 0, sizeof(int)*(revmex[s] + 5));
      mx = 0;
      int t = s;
      while (mx < revmex[s]) {
        have[a[t]] = 1;
        while (have[mx]) {
          ++mx;
        }
        ++t;
      }
      b[idx] = revmex[s];
      ++idx;
      s = t;
    }
    cout << idx-1 << "\n";
    for (int i=1; i<idx; ++i) {
      cout << b[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}