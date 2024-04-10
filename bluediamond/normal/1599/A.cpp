#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 2e5 + 7;
int n, a[N];
string s;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  vector<int> speciale, normale;
  cin >> s;

  int sch = 1;
  for (int i = 1; i < n; i++) {
    sch += (s[i] != s[i - 1]);
  }
  for (int i = 1; i <= n - sch; i++) {
    normale.push_back(a[i]);
  }
  for (int i = n - sch + 1; i <= n; i++) {
    speciale.push_back(a[i]);
  }
  reverse(speciale.begin(), speciale.end());
  s = "$" + s;
  string ant;
  for (int i = 1; i <= n; i++) {
    if (s[i] != s[i - 1]) {
      assert(!speciale.empty());
      cout << speciale.back() << " " << s[i] << "\n";
      if (i == 1) ant = s[i];
      speciale.pop_back();
    } else {
      if (ant == "L") ant = "R";
      else ant = "L";
      assert(!normale.empty());
      cout << normale.back() << " " << ant << "\n";
      normale.pop_back();
    }
  }



  return 0;
}