#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n, a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int pos = n - 1;
    while (pos >= 1 && a[pos] >= a[pos + 1]) {
      pos--;
    }
    while (pos >= 1 && a[pos] <= a[pos + 1]) {
      pos--;
    }
    cout << pos << "\n";
  }
  return 0;
}