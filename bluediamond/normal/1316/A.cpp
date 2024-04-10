#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      sum += x;
    }
    cout << min(m, sum) << "\n";
  }

}