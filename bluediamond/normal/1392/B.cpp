#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n;
ll k;
int a[N];

void op() {
  int d = a[1];
  for (int i = 2; i <= n; i++) {
    d = max(d, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = d - a[i];
  }
}

void print() {
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int mn = a[1], mx = a[1];
    for (int i = 2; i <= n; i++) {
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
    }
    if (mn == mx) {
      for (int i = 1; i <= n; i++) {
        a[i] = 0;
      }
    } else {
      k--;
      op();
      if (k % 2) {
        op();
      }
    }
    print();
  }
  return 0;
}