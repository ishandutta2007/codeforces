#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll want;
int n, f[100];

void solve_test() {
  cin >> want >> n;
  for (int i = 0; i <= 60; i++) {
    f[i] = 0;
  }
  ll mx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mx += x;
    x = log2(x);
    f[x]++;
  }
  if (mx < want) {
    cout << "-1\n";
    return;
  }
  ll cost = 0;
  ll smaller = 0;
  for (int i = 0; (1LL << i) <= want; i++) {
    smaller += f[i] * (1LL << i);
    if (!(want & (1LL << i))) continue;
    if (smaller >= (1LL << i)) {
      smaller -= (1LL << i);
      continue;
    }
    for (int j = i + 1; j <= 60; j++) {
      if (f[j]) {
        for (int p = j; p > i; p--) {
          cost++;
          f[p]--;
          f[p - 1] += 2;
        }
        break;
      }
    }
  }
  cout << cost << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve_test();
  }


}