#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[310];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int cnt = 1;
    for (int i = 1; i <= n; i += 2) {
      cout << a[cnt] << " ";
      if (cnt != n - cnt + 1) cout << a[n - cnt + 1] << " ";
      cnt++;
    }
    cout << endl;
  }
}