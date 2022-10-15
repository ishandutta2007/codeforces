#include <bits/stdc++.h>

using namespace std;

///#define int ll
typedef long long ll;
typedef long double ld;

#define int ll

string solve(int n, int k, int x, string s) {
  x--;
  vector<int> lens, bits;
  string sol;
  int l = 0;
  while (l < n) {
    if (s[l] == 'a') {
      l++;
      continue;
    }
    int r = l;
    while (r + 1 < n && s[r + 1] == '*') {
      r++;
    }
    lens.push_back(k * (r - l + 1) + 1);
    l = r + 1;
  }
  reverse(lens.begin(), lens.end());
  int xinit = x;
  for (auto &base : lens) {
    bits.push_back(x % base);
    x /= base;
  }
  reverse(bits.begin(), bits.end());
  l = 0;
  int cur = 0;
  while (l < n) {
    if (s[l] == 'a') {
      l++;
      sol += 'a';
      continue;
    }
    int r = l;
    while (r + 1 < n && s[r + 1] == '*') {
      r++;
    }
    for (int j = 1; j <= bits[cur]; j++) {
      sol += 'b';
    }
    cur++;
    l = r + 1;
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    string s;
    cin >> n >> k >> x >> s;
    string sol = solve(n, k, x, s);
    cout << sol << "\n";
  }

  return 0;
}