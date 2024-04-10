#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int tp(char x) {
  if (x == 'L') {
    return 0;
  } else {
    return 1;
  }
}

int f(int len) {
  return len / 3;
}

int g(int len) {
  if (len <= 2) {
    return 0;
  }
  if (len == 3) {
    return 1;
  }
  return (len + 2) / 3;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<pair<int, int>> a;
    for (auto &c : s) {
      int x = tp(c);
      if (a.empty() || a.back().first != x) {
        a.push_back({x, 0});
      }
      a.back().second++;
    }
    if ((int) a.size() == 1) {
      cout << g(a[0].second) << "\n";
    } else {
      if (a[0].first == a.back().first) {
        a[0].second += a.back().second;
        a.pop_back();
      }
      int sol = 0;
      for (auto &it : a) {
        sol += f(it.second);
      }
      cout << sol << "\n";
    }
  }
  return 0;
}