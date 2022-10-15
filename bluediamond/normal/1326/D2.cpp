#include <bits/stdc++.h>

using namespace std;


vector<int> man1(vector<int> a) {
  int n = (int) a.size();
  int l = -1, r = -1;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    if (i <= r) {
      b[i] = min(b[l + r - i], r - i);
    } else {
      b[i] = 0;
    }
    while (i - b[i] - 1 >= 0 && i + b[i] + 1 < n && a[i - b[i] - 1] == a[i + b[i] + 1]) {
      b[i]++;
    }
    if (i + b[i] > r) {
      l = i - b[i];
      r = i + b[i];
    }
  }
  return b;
}

vector<int> man2(vector<int> a) {
  int n = (int) a.size();
  vector<int> b = {-1};
  for (int i = 0; i < n; i++) {
    b.push_back(a[i]);
    b.push_back(-1);
  }
  vector<int> c = man1(b), d;
  for (int i = 0; i < 2 * n - 1; i += 2) {
    d.push_back(c[i] / 2);
  }
  return d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    int l = 0;
    while (l < n - 1 - l && s[l] == s[n - 1 - l]) {
      l++;
    }
    vector<int> a;
    for (int i = l; i <= n - 1 - l; i++) {
      a.push_back(s[i] - 'a');
    }
    vector<int> b = man1(a), c = man2(a);
    n = (int) b.size();
    int __l = 1, __r = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int l = i - b[i], r = i + b[i];
      if (l == 0 || r == n - 1) {
        ans = max(ans, r - l + 1);
        if (r - l + 1 == ans) {
          __l = l;
          __r = r;
        }
      }
      l = i - c[i], r = i + c[i] - 1;
      if (l == 0 || r == n - 1) {
        ans = max(ans, r - l + 1);
        if (r - l + 1 == ans) {
          __l = l;
          __r = r;
        }
      }
    }
    for (int i = 0; i < l; i++) {
      cout << s[i];
    }
    for (int i = __l; i <= __r; i++) {
      cout << (char) (a[i] + 'a');
    }
    for (int i = l - 1; i >= 0; i--) {
      cout << s[i];
    }
    cout << "\n";
  }
}