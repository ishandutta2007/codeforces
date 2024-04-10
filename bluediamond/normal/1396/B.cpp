#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int solve(vector<int> a) {
  int sum = 0, mx = 0;
  for (auto &x : a) {
    sum += x;
    mx = max(mx, x);
  }
  if (mx > sum - mx) {
    return 1;
  } else {
    return sum % 2;
  }
}


signed main() {
  ios::sync_with_stdio(false);cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (solve(a)) {
      cout << "T\n";
    } else {
      cout << "HL\n";
    }
  }
  return 0;
}