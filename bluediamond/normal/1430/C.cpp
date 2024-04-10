#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
      s.insert(i);
    }
    vector<pair<int, int>> ret;
    while ((int) s.size() > 1) {
      auto a = s.end();
      a--;
      auto b = a;
      b--;
      int sum = *a + *b;
      ret.push_back({*a, *b});
      s.erase(a);
      s.erase(b);
      s.insert((sum + 1) / 2);
    }
    cout << *s.begin() << "\n";
    for (auto &x : ret) {
      cout << x.first << " " << x.second << "\n";
    }
  }

}