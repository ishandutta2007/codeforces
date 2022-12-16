#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100200;

void try_insert(pair<int, int> x, set<pair<int, int>>& st) {
  if (x.first <= x.second) {
    st.insert(x);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> pts(m);
  map<int, vector<int>> mp;
  mp[n] = {};
  for (auto& [x, y] : pts) {
    cin >> x >> y;
    mp[x].push_back(y);
  }
  sort(pts.begin(), pts.end());
  vector<pair<int, int>> pre, cur;
  pre.push_back({1, 1});
  int px = 0;
  for (auto& [x, vec] : mp) {
    sort(vec.begin(), vec.end());
    if (x-px > 1 && !pre.empty()) {
      int z = pre.begin()->first;
      pre.clear();
      pre.push_back({z, n});
    }
    int r = 1;
    auto jt = pre.begin();
    vec.push_back(n+1);
    for (auto& y : vec) {
      if (r < y) {
        int q = y-1;
        while (jt != pre.end() && jt->second < r) {
          ++jt;
        }
        if (jt != pre.end() && jt->first <= q) {
          cur.push_back({max(r, jt->first), q});
        }
      }
      r = y+1;
    }
    /*
    cerr << "~~~ \n";
    for (auto& [a, b] : cur) {
      cerr << a << "," << b << endl;
    }
    */

    swap(pre, cur);
    cur.clear();
    px = x;
  }
  cout << (!pre.empty() && pre.rbegin()->second == n ? n*2-2 : -1) << "\n";
  return 0;
}