#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
 
struct SegTree {
  int n;
  vector<int> T, L;
  SegTree(int n) : n(n), T(4 * n), L(4 * n, 0) {
    init(1, 0, n);
  }
 
  void init(int node, int b, int e) {
    if (b + 1 == e) {
      T[node] = -b;
    } else {
      int m = (b + e) / 2;
      init(node * 2, b, m);
      init(node * 2 + 1, m, e);
      T[node] = T[node * 2];
    }
  }
 
  void update(int node, int b, int e, int pos, int val) {
    if (b == pos) {
      L[node] += val;
    } else {
      int m = (b + e) / 2;
      if (pos < m) {
        update(node * 2, b, m, pos, val);
        L[node * 2 + 1] += val;
      } else {
        update(node * 2 + 1, m, e, pos, val);
      }
      T[node] = max(T[node * 2] + L[node * 2], T[node * 2 + 1] + L[node * 2 + 1]);
    }
  }
 
  void Update(int pos, int val) { 
    // cerr << "   Update: " << pos << " " << val << endl;
    assert(0 <= pos && pos < n); 
    update(1, 0, n, pos, val); 
  }
 
  int Max() { 
    // cerr << "   Max: " << T[1] + L[1] << endl;
    return T[1] + L[1]; 
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> posz;
    posz.reserve(n);
    vector<int> norm(n + 1, 0);
    int dist = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == 0)
        posz.push_back(a[i]);
      else {
        if (!norm[a[i]]) 
          norm[a[i]] = ++dist;
        a[i] = norm[a[i]];
      }
    }
 
    // cerr << "dist: " << dist << endl;
 
    vector<tuple<int, int, int>> evs;
    vector<int> b(dist + 1), e(dist + 1);
 
    auto check = [&](int nz) {
      // cerr << endl;
      // for (int i = 0; i < n; ++i) cerr << a[i] << " "; cerr << endl;
      // cerr << "check: " << nz << endl;
      fill(b.begin(), b.end(), 0);
      fill(e.begin(), e.end(), nz);
 
      int czl = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == 0) { czl += 1; continue; }
        if (czl == 0 || czl == (int)posz.size()) continue;
        if (czl < nz) {
          // cerr << "left: " << i << endl;
          b[a[i]] = max(b[a[i]], czl);
        }
        else if (czl > (int)posz.size() - nz) {
          // cerr << "right: " << i << endl;
          e[a[i]] = min(e[a[i]], czl - (int)posz.size() + nz);
        }
        else {
          // cerr << "middle: " << i << endl;
          b[a[i]] = nz, e[a[i]] = 0;
        }
      }
 
      evs.clear();
      for (int i = 1; i <= dist; ++i) {
        if (b[i] >= e[i]) continue;
        // cerr << i << ": " << b[i] << " " << e[i] << endl;
        evs.emplace_back(b[i], 0, b[i]);
        evs.emplace_back(e[i], 2, b[i]);
      }
      for (int i = 1; i <= nz; ++i)
        evs.emplace_back(i, 1, -1);
 
      sort(evs.begin(), evs.end());
 
      SegTree st(nz + 1);
      for (auto [at, typ, pos]: evs) {
        if (typ == 0) st.Update(pos, 1);
        if (typ == 2) st.Update(pos, -1);
        if (typ == 1) {
          int best = st.Max();
          if (best > dist - at)
            return false;
        }
      }
      return true;
    };
    
    int ans = 0;
    for (int step = (1 << 20); step; step /= 2) {
      if (ans + step <= (int)posz.size() / 2 
          && ans + step <= n - (int)posz.size() 
          && check(ans + step))
        ans += step;
    }
    cout << ans << '\n';
  }
 
  return 0;
}