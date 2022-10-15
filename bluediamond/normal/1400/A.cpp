#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < (int) s.size(); i += 2) {
      cout << s[i];
    }
    cout << "\n";
  }
  return 0;
}