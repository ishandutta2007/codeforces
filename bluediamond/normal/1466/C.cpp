#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int y;
int n;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    n = (int) str.size();
    for (int i = 1; i <= n; i++) {
      a[i] = str[i - 1];
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      if (i - 1 >= 1 && a[i] == a[i - 1]) {
        ret++;
        a[i] = --y;
      }
      if (i - 2 >= 1 && a[i] == a[i - 2]) {
        ret++;
        a[i] = --y;
      }
    }
    cout << ret << "\n";
  }
}