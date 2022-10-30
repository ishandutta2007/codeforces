#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "? " << 1 << " " << n << endl;
    string ans;
    cin >> ans;
    cout << "! " << ans << endl;
    return 0;
  }
  cout << "? " << 1 << " " << n << endl;
  vector<int> cnt(26);
  vector<vector<int>> S(26, vector<int>(n + 2));
  for (int i = 1; i <= n * (n + 1) / 2; i++) {
    string s;
    cin >> s;
    int len = s.size();
    if (len == n) {
      for (int i = 0; i < len; i++) {
        ++cnt[s[i] - 'a'];
      }
    }
    for (char c = 'a'; c <= 'z'; c++) {
      for (int i = 0; i < len; i++) {
        if (s[i] == c) {
          ++S[c - 'a'][len];
        }
      }
    }
  }
  vector<vector<int>> poss(n + 1);
  for (int i = 0; i < 26; i++) {
    for (int j = n; j >= 1; j--) {
      for (int q = 0; q < (S[i][j] - S[i][j + 1]) - (S[i][j - 1] - S[i][j]); q++) {
        poss[j].push_back(i);
      }
    }
  }
  cout << "? " << 1 << " " << n - 1 << endl;
  vector<int> cnt2(26);
  vector<vector<int>> S2(26, vector<int>(n + 1));
  for (int i = 1; i <= (n - 1) * n / 2; i++) {
    string s;
    cin >> s;
    int len = s.size();
    if (len == n - 1) {
      for (int i = 0; i < len; i++) {
        ++cnt2[s[i] - 'a'];
      }
    }
    for (char c = 'a'; c <= 'z'; c++) {
      for (int i = 0; i < len; i++) {
        if (s[i] == c) {
          ++S2[c - 'a'][len];
        }
      }
    }
  }
  vector<vector<int>> poss2(n);
  for (int i = 0; i < 26; i++) {
    for (int j = n - 1; j >= 1; j--) {
      for (int q = 0; q < (S2[i][j] - S2[i][j + 1]) - (S2[i][j - 1] - S2[i][j]); q++) {
        poss2[j].push_back(i);
      }
    }
  }
  /*
  for (int i = 1; i <= n - 1; i++) {
    for (auto p: poss2[i]) cout << p << " ";
    cout << endl;
    // assert((int)poss[i].size() == 2);
  }
  */
  vector<int> ans(n + 1, -1);
  for (int i = 0; i < 26; i++) {
    if (cnt[i] != cnt2[i]) {
      ans[n] = i;
    }
  }
  // n -> 1 -> n - 1 -> 2 ...
  for (int i = 1; i < n; i++) {
    if (ans[i] == -1) {
      if (ans[n - i + 1] == poss[i][0]) {
        ans[i] = poss[i][1]; 
      } else {
        ans[i] = poss[i][0];
      }
    }
    if (ans[n - i] == -1) {
      if (ans[i] == poss2[n - i][0]) {
        ans[n - i] = poss2[n - i][1];
      } else {
        ans[n - i] = poss2[n - i][0];
      }
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << char(ans[i] + 'a');
  }
  cout << endl;
  return 0;
}