#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<string, int> cnt;
  vector<string> s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    ++cnt[s[i]];
  }
  auto find = [&](char a, char b) -> char {
    const char option[] = {'S', 'E', 'T'};
    for (int i = 0; i < 3; i++) {
      if (option[i] != a && option[i] != b) {
        return option[i];
      }
    }
    assert(false);
  };
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (s[i] == s[j]) {
        ans += (cnt[s[i]] - 2);
      } else { 
        string need = s[i];
        for (int p = 0; p < k; p++) {
          if (s[i][p] == s[j][p]) {
            need[p] = s[i][p];
          } else {
            need[p] = find(s[i][p], s[j][p]);
          }
        }
        ans += cnt[need];
      }
    }
  }
  cout << ans / 3 << endl;
  return 0;
}