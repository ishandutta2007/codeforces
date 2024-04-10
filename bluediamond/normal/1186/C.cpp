#include <bits/stdc++.h>

using namespace std;

int bit(char ch) {
  return (ch - '0');
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string a, b;
  cin >> a >> b;
  int la = (int) a.size(), lb = (int) b.size();
  int c = 0;

  for (int i = 0; i < lb; i++) {
    c ^= bit(a[i]);
    c ^= bit(b[i]);
  }

  int sol = 0;
  for (int l = 0; l + lb - 1 < la; l++) {
    int r = l + lb - 1;
    sol += !(c & 1);
    c ^= bit(a[r + 1]);
    c ^= bit(a[l]);
  }
  cout << sol << "\n";

  return 0;
}