#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int a[N];

void solve() {
  if (n % 2 == 1) {
    cout << "YES\n";
    cout << n - 2 << "\n";
    for (int i = 1; i + 2 <= n; i += 2) {
      cout << i << " " << i + 1 << " " << i + 2 << "\n";
    }
    for (int i = 1; i + 2 < n; i += 2) {
      cout << i << " " << i + 1 << " " << n << "\n";
    }
  } else {
    int t = 0;
    for (int i = 1; i < n; i++) {
      t ^= a[i];
    }
    if (t != a[n]) {
      cout << "NO\n";
    } else {
      n--;
      solve();
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  solve();

}