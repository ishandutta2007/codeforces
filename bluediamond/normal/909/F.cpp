#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void print(int n) {
  if (n == 0) {
    return;
  } else {
    int k = log2(n);
    k = (1 << k);
    int h1 = n - k + 1;
    int h2 = k - 1;
    int h = min(h1, h2);
    int l = k - h;
    int r = k + h - 1;
    print(l - 1);
    for (int x = r; x >=l; x--) {
      cout << x << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if (n & 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    print(n);
  }
  if (n <= 5) {
    cout << "NO\n";
    return 0;
  }
  if (n == 6) {
    cout << "YES\n";
    cout << "3 6 2 5 1 4\n";
    return 0;
  }
  int k = log2(n);
  if ((1 << k) == n) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  cout << "3 6 1 5 4 7 2 ";
  int l = 8;
  while (l <= n) {
    int r = min(2 * l - 1, n);
    for (int j = l + 1; j <= r; j++) {
      cout << j << " ";
    }
    cout << l << " ";
    l = r + 1;
  }
  cout << "\n";
}