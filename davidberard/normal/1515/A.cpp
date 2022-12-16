#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;
int w[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, x;
    cin >> n >> x;
    ll wtot = 0;
    for (int i=1; i<=n; ++i) {
      cin >> w[i];
      wtot += w[i];
    }
    if (wtot == x) {
      cout << "NO\n";
      continue;
    }
    sort(w+1, w+n+1);
    ll ws = 0;
    for (int i=1; i<=n; ++i) {
      ws += w[i];
      if (ws == x) {
        ws -= w[i];
        swap(w[i], w[n]);
        ws += w[i];
      }
    }
    cout << "YES\n";
    for (int i=1; i<=n; ++i) {
      cout << w[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}