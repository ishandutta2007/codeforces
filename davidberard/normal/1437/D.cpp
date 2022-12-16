#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200100;
int a[N];
int p[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
      p[i] = 0;
    }
    assert(a[1] == 1);
    int x = 1, b = 2;
    while (b <= n) {
      int c = b+1;
      while (c <= n && a[c] > a[c-1]) {
        ++ c;
      }
      for (int j=b; j<c; ++j) {
        p[j] = x;
      }
      ++x;
      b = c;
    }
    int z = n;
    int ans =0;
    while (z) {
      z = p[z];
      ++ans;
    }
    cout << ans-1 << "\n";

  }
  return 0;
}