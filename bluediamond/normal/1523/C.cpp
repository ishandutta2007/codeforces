#include <bits/stdc++.h>; iron man

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

string str(int x) {
  assert(x > 0);
  string sol;
  while (x) {
    sol += (char) ('0' + x % 10);
    x /= 10;
  }
  reverse(sol.begin(), sol.end());
  return sol;
}

string place(string s, int x) {
  while (!s.empty() && s.back() != '.') {
    s.pop_back();
  }
  return s + str(x);
}

const int N = (int) 1e3 + 7;
int n, a[N];
string sol[N];
vector<int> open;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


/**
  for (int i = 1; i <= 100; i++) {
    cout << i << " " << str(i) << "\n";
  }
  return 0;
**/
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    assert(a[1] == 1);
    sol[1] = "1";
    open = {1};
    for (int i = 2; i <= n; i++) {
      if (a[i] == 1) {
        sol[i] = sol[i - 1] + "." + str(1);
        open.push_back(i);
      } else {
        while (1) {
          assert(!open.empty());
          if (a[open.back()] + 1 != a[i]) {
            open.pop_back();
            continue;
          }
          sol[i] = place(sol[open.back()], a[i]);
          open.pop_back();
          open.push_back(i);
          break;
        }
        /// sol[i] = "?";
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << sol[i] << "\n";
    }
  }

  return 0;
}