#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int a[N];
int b[N];
int f[40];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; (1 << j) <= a[i]; j++) {
      if (a[i] & (1 << j)) {
        f[j]++;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; (1 << j) <= a[i]; j++) {
      if (a[i] & (1 << j)) {
        if (f[j] == 1) {
          b[i] += (1 << j);
        }
      }
    }
  }

  int m = -1, id = 1;
  for (int i = 1; i <= n; i++) {
    if (b[i] > m) {
      m = b[i];
      id = i;
    }
  }
  cout << a[id] << " ";
  for (int i = 1; i <= n; i++) {
    if (i != id) {
      cout << a[i] << " ";
    }
  }
  cout << "\n";



}