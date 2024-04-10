#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; ++qq) {
    int n, r;
    cin >> n >> r;
    vector<int> x(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int answer = 0;
    n = x.size();
    for (int i = n - 1; i >= 0; --i) {
      if (x[i] <= answer * r) break;
      answer += 1;
    }
    cout << answer << endl;
  }
  return 0;
}