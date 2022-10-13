#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; cnt[x] += 1;
  }

  vector<int> v;
  while (cnt.size()) {
    for (auto it = cnt.begin(); it != cnt.end();) {
      v.push_back(it->first);
      it->second -= 1;
      if (it->second == 0) {
        it = cnt.erase(it);
      } else {
        it = next(it);
      }
    }
  }

  vector<vector<int>> divs(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i)
      divs[j].push_back(i);
  }

  cnt.clear();
  int maxcnt = 0;
  int aa = -1, bb = -1;

  for (int i = 0; i < n; ++i) {
    cnt[v[i]] += 1;
    maxcnt = max(maxcnt, cnt[v[i]]);
    for (auto a : divs[i + 1]) {
      int b = (i + 1) / a;
      if (a > b) continue;
      if (a >= maxcnt && b >= maxcnt) {
        aa = a; bb = b;
      }
    }
  }
  //for (auto x : v) cerr << x << " "; cerr << endl;

  v.resize(aa * bb);
  sort(v.begin(), v.end());
  //for (auto x : v) cerr << x << " "; cerr << endl;
  
  cout << aa * bb << endl;
  vector<vector<int>> ret(aa, vector<int>(bb));
  int at = 0;

  cnt.clear();
  for (auto x : v) {
    cnt[x] += 1;
  }

  vector<pair<int, int>> vp;
  for (auto p : cnt) {
    vp.emplace_back(p.second, p.first);
  }
  sort(vp.rbegin(), vp.rend());
  v.clear();
  for (auto p : vp) {
    for (int i = 0; i < p.first; ++i) {
      v.push_back(p.second);
    }
  }

  for (int i = 0; i < bb; ++i) {
    for (int j = 0; j < aa; ++j) {
      ret[j][(i + j) % bb] = v[at++];
    }
  }
  
  cout << aa << " " << bb << endl;
  for (int i = 0; i < aa; ++i) {
    for (int j = 0; j < bb; ++j) {
      cout << ret[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}