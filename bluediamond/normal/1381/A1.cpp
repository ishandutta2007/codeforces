#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int a[N];
int b[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (int i = 1; i <= n; i++) {
      a[i] = s[i - 1] - '0';
      b[i] = t[i - 1] - '0';
    }
    vector<int> sol;
    for (int suf = n; suf >= 1; suf--) {
      if (a[suf] == b[suf]) {
        continue;
      }
      if (a[1] != a[suf]) {
        sol.push_back(1);
      }
      sol.push_back(suf);
      reverse(a + 1, a + suf + 1);
      for (int i = 1; i <= suf; i++) {
        a[i] ^= 1;
      }
    }
    cout << (int) sol.size() << " ";
    for (auto &i : sol) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}