#include <bits/stdc++.h>

using namespace std;

int f[26];
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  for (auto &c : s) {
    f[c - 'a']++;
  }

  vector <int> imps;
  for (int c = 0; c < 26; c++) {
    if (f[c] & 1) {
      imps.push_back(c);
    }
  }

  for (int i = 0; i < (int) imps.size() - 1 - i; i++) {
    f[imps[(int) imps.size() - 1 - i]]--;
    f[imps[i]]++;
  }

  string a, mid;
  for (int c = 0; c < 26; c++) {
    if (f[c] & 1) {
      mid = (char) (c + 'a');
    }
    for (int i = 1; i <= f[c] / 2; i++) {
      a += (char) (c + 'a');
    }
  }

  string b = a;
  reverse(b.begin(), b.end());
  cout << a + mid + b << "\n";



  return 0;
}