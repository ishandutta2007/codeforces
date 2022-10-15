#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
int a[N];
int d[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int l = 2, y = 1;
    while (l <= n) {
      int r = l;
      while (r + 1 <= n && a[r] < a[r + 1]) {
        r++;
      }
      for (int j = l; j <= r; j++) {
        d[j] = d[y] + 1;
      }
      y++;
      l = r + 1;
    }
    cout << d[n] << "\n";
  }
}