#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    vector<int> cnt(2);
    for (auto c: s) {
      cnt[c - '0'] += 1;
    }
    int ans = c0 * cnt[0] + c1 * cnt[1];
    ans = min(ans, cnt[0] * h + n * c1);
    ans = min(ans, cnt[1] * h + n * c0);
    cout << ans << "\n";
  }
  return 0;
}