#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    // cerr << "TEST: " << tt << endl;
    int n, x, y; cin >> n >> x >> y;
    vector<vector<int>> pos(n + 1);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      int z; cin >> z; --z;
      v[i] = z;
      pos[z].push_back(i);
    }

    int emp = 0;
    while (pos[emp].size()) ++emp;
    // cerr << "emp: " << emp + 1 << endl;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i <= n; ++i)
      pq.emplace(pos[i].size(), i);
    
    int sz = n;    
    vector<int> sol(n, emp);
    for (int i = 0; i < x; ++i) {
      auto top = pq.top(); pq.pop();
      assert(top.first > 0);
      int col = top.second;
      sol[pos[col].back()] = col;
      pos[col].pop_back();
      pq.emplace(pos[col].size(), col);
      sz -= 1;
    }

    int max_freq = -1, max_col = -1;
    for (int i = 0; i <= n; ++i) {
      int freq = pos[i].size();
      if (max_freq < freq) {
        max_freq = freq;
        max_col = i;
      }
    }

    // cerr << "max freq: " << max_freq << endl;
    // cerr << "max col: " << max_col + 1 << endl;
    // cerr << "sz: " << sz << endl;

    if (max_freq * 2 <= sz) {
      vector<int> p;
      for (int i = 0; i <= n; ++i) {
        for (auto x : pos[i])
          p.push_back(x);
      }

      assert(y - x <= (int)p.size());
      assert((int)p.size() == sz);
      for (int i = 0; i < y - x; ++i) {
        sol[p[i]] = v[p[(i + max_freq) % p.size()]]; 
      }
    } else if (2 * (sz - max_freq) < y - x) {
      cout << "NO\n";
      continue;
    } else {
      vector<int> p;
      for (int i = 0; i <= n; ++i) {
        if (i == max_col) continue;
        for (auto x : pos[i])
          p.push_back(x);
      }

      vector<int> q = pos[max_col];
      assert((int)q.size() == max_freq);

      // cerr << "p q sizes: " << p.size() << " " << q.size() << endl;

      for (int i = 0; i < y - x; ++i) {
        assert(i / 2 < (int)p.size());
        assert(i / 2 < (int)q.size());
        if (i % 2 == 0) sol[p[i / 2]] = v[q[i / 2]];
        else sol[q[i / 2]] = v[p[i / 2]];
      }
    }


    cout << "YES\n";
    for (auto x : sol) 
      cout << x + 1 << " ";
    cout << '\n';


    map<int, int> frq;
    for (int i = 0; i < n; ++i)
      frq[v[i]] += 1;
    int xx = 0, yy = 0;
    for (int i = 0; i < n; ++i) {
      if (sol[i] == v[i]) xx += 1;
      if (frq[sol[i]]) {
        yy += 1;
        frq[sol[i]] -= 1;
      }
    }
    assert(yy == y);
    assert(xx == x);
  }

  return 0;
}