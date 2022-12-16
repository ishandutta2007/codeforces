#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  set<int> t;
  while (TT--) {
    t.clear();
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> m;
    for (int i=0; i<s.size(); ++i) {
      if (s[i] == 'T') {
        t.insert(i);
      }
      if (s[i] == 'M') {
        m.push_back(i);
      }
    }
    if (t.size() != m.size()*2) {
      cout << "NO\n";
      continue;
    }
    bool good = true;
    for (auto& x : m) {
      int a = *t.begin();
      if (!(a < x)) {
        good = false;
        break;
      }
      t.erase(a);
    }
    reverse(m.begin(), m.end());
    for (auto& x: m) {
      int a = *prev(t.end());
      if (!(a > x)) {
        good = false;
        break;
      }
      t.erase(a);
    }
    cout << (good ? "YES" : "NO") << endl;
  }
  return 0;
}