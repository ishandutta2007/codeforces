#include <bits/stdc++.h>

using namespace std;

int last[(int) 1e6 + 7];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  bool ok = 0;
  for (int tc = 1; tc <= t; tc++) {
    set<int> Sdifs;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    for (auto &x : a) {
      for (auto &y : a) {
        Sdifs.insert(x - y);
      }
    }
    vector<int> difs;
    for (auto &x : Sdifs) {
      if (x >= 0) difs.push_back(x);
    }
    int cur = 1;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
      while (last[cur] == tc) cur++;
      b.push_back(cur);
      for (auto &dif : difs) {
        int z = cur + dif;
        if (1 <= z && z <= (int) 1e6) last[z] = tc;
      }
    }
    cout << "YES\n";
    for (auto &x : b) {
      cout << x << " ";
    }
    cout << "\n";
  }

}