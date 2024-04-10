#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, c = 0;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
      c += (s[i] == s[i - 1]);
    }
    cout << (c + 1) / 2 << "\n";
  }

}