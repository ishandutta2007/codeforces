#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  vector<int> open, close;
  int n = (int) s.size();
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '(') {
      open.push_back(i);
    } else {
      close.push_back(i);
    }
  }
  reverse(close.begin(), close.end());
  vector<int> ids;
  int pclose = 0;
  for (auto &i : open) {
    if (pclose >= (int) close.size()) break;
    if (i > close[pclose]) break;
    ids.push_back(i);
    ids.push_back(close[pclose]);
    pclose++;
  }
  if (ids.empty()) {
    cout << "0\n";
  } else {
    sort(ids.begin(), ids.end());
    cout << "1\n";
    cout << (int) ids.size() << "\n";
    for (auto &i : ids) {
      cout << i << " ";
    }
    cout << "\n";
  }

}