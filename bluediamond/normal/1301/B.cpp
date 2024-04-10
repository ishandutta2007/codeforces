#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, a[N], small, big;

void ins(int x) {
  if (small == -1) {
    small = big = x;
  } else {
    small = min(small, x);
    big = max(big, x);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    small = -1, big = -1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        if (i - 1 >= 1 && a[i - 1] != -1) {
          ins(a[i - 1]);
        }
        if (i + 1 <= n && a[i + 1] != -1) {
          ins(a[i + 1]);
        }
      }
    }
    int half = max(0, (small + big) / 2);
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        a[i] = half;
      }
    }
    int sol = 0;
    for (int i = 1; i < n; i++) {
      sol = max(sol, abs(a[i] - a[i + 1]));
    }
    cout << sol << " " << half << "\n";
  }

}