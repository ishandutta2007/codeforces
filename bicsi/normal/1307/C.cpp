#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s; cin >> s;
  map<char, int> freq;
  int n = s.size();
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    freq[s[i]] += 1;
    ans = max(ans, (long long)freq[s[i]]);
  }

  for (char c = 'a'; c <= 'z'; ++c) {
    for (char d = 'a'; d <= 'z'; ++d) {
      long long now = 0;
      int cnt = 0;

      for (int i = 0; i < n; ++i) {
        if (s[i] == c) {
          now += cnt;
        } 
        if (s[i] == d) {
          cnt += 1;
        }
      }

      ans = max(ans, now);
    }
  }

  cout << ans << endl;

  return 0;
}