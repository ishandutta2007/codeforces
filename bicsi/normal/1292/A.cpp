#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, q; cin >> n >> q;

  set<int> obs[2];

  auto have = [&](int a, int b) {
    return obs[a].count(b);
  };
  
  int total = 0;
  for (int i = 0; i < q; ++i) {
    int r, c; cin >> r >> c; --r; 
    int oth = 1 - r;
    int now_cnt = have(oth, c - 1) + have(oth, c) + have(oth,c  + 1);
    if (have(r, c)) {
      obs[r].erase(c);
      total -= now_cnt;
    } else {
      obs[r].insert(c);
      total += now_cnt;
    }
    cerr << total << endl;
    if (total == 0) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}