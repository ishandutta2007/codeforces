#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

bool divi(string a, string b) {
  if ((int) a.size() % (int) b.size() != 0) {
    return 0;
  }
  int k = (int) b.size();
  for (int j = 0; j < (int) a.size(); j++) {
    if (a[j] != b[j % k]) {
      return 0;
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s, t, ret, sol = "-1";
    cin >> s >> t;
    ret = s;
    for (int j = 1; j <= 20; j++) {
      if (divi(ret, t)) {
        sol = ret;
        break;
      }
      ret += s;
    }
    cout << sol << "\n";
  }
}