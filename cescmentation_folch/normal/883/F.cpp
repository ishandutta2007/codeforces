#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_set<string> M;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int m = s.size();
    string t;
    for (int j = 0; j < m; ) {
      if (s[j] == 'u') {
        t += "oo";
        ++j;
        continue;
      }
      if (s[j] != 'k') {
        t += s[j];
        ++j;
        continue;
      }
      int cont = 0;
      while (j + cont < m and s[j + cont] == 'k') {
        ++cont;
      }
      if (j + cont < m and s[j + cont] == 'h') {
        t += 'h';
        j += cont + 1;
      } else {
        t += string(cont, 'k');
        j += cont;
      }
    }
    M.insert(t);
  }
  cout << M.size() << endl;
}