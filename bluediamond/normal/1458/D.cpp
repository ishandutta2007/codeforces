#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int x = 0;
    map<int, int> l, r;
    for (auto &ch : s) {
      if (ch == '0') {
        l[x]++;
        r[x - 1]++;
        x--;
      } else {
        r[x]++;
        l[x + 1]++;
        x++;
      }
    }
    function<void(int)> dfs = [&] (int x) {
      if (l[x] == 0 && r[x] == 0) {
        return;
      }
      if (l[x] >= 2 || r[x] == 0) {
        cout << 0;
        l[x]--;
        r[x - 1]--;
        dfs(x - 1);
      } else {
        cout << 1;
        r[x]--;
        l[x + 1]--;
        dfs(x + 1);
      }
    };
    dfs(0);
    cout << "\n";
  }
}