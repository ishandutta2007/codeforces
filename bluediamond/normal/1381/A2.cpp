#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int a[N];
int b[N];
int u[N];

int l, r, all;
bool rev;

int get(int i) {
  all %= 2;
  u[i] %= 2;
  a[i] %= 2;
  return a[i] ^ all ^ u[i];
}

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
      u[i] = 0;
    }
    l = 1;
    r = n;
    all = 0;
    rev = 0;

    vector<int> sol;
    for (int suf = n; suf >= 1; suf--) {
      int first, last;
      if (rev == 0) {
        first = l;
        last = r;
      } else {
        first = r;
        last = l;
      }
      if (get(last) == b[suf]) {
        if (rev == 0) {
          r--;
        } else {
          l++;
        }
        continue;
      }
      if (get(first) != get(last)) {
        u[first] ^= 1;
        sol.push_back(1);
      }
      sol.push_back(suf);
      rev ^= 1;
      all ^= 1;
      if (rev == 0) {
        r--;
      } else {
        l++;
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