#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
int a[N];
int b[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    a[n] = a[0];
    int id = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == a[i + 1]) {
        id = i;
      }
    }
    if (id == -1) {
      if (n % 2 == 0) {
        cout << "2\n";
        for (int i = 1; i <= n; i++) {
          cout << i % 2 + 1 << " ";
        }
      } else {
        cout << "3\n";
        for (int i = 1; i < n; i++) {
          cout << i % 2 + 1 << " ";
        }
        cout << "3";
      }
      cout << "\n";
    } else {
      bool all = 1;
      for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
          all = 0;
        }
      }
      if (all) {
        cout << "1\n";
        for (int i = 1; i <= n; i++) {
          cout << "1 ";
        }
        cout << "\n";
      } else {
        for (int j = 0; j < n; j++) {
          int i = (j + 1 + id) % n;
          b[i] = j % 2 + 1;
        }
        cout << "2\n";
        for (int i = 0; i < n; i++) {
          cout << b[i] << " ";
        }
        cout << "\n";
      }
    }
  }

}