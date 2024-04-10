#include <bits/stdc++.h>

using namespace std;

vector <char> c = {'Q', 'R', 'U', 'O', 'P', 'S', 'D', 'G', 'J', 'C', 'B'};

bool foo(char ch) {
  for (auto &x : c) {
    if (x == ch) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  bool bar = foo(s[0]);
  for (int i = 1; i < (int) s.size(); i++) {
    bool bar2 = foo(s[i]);
    if (bar2 != bar) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}