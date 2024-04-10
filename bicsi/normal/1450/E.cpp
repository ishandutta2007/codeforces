#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 
 
#include <bits/stdc++.h>
 
using namespace std;
 
// struct DSU {
//   vector<int> link;
//   DSU(int n) : link(n, -1) {}
//   int Find(int x) {
//     if (link[x] == -1) return x;
//     return link[x] = Find(link[x]);
//   }
//   void Unite(int a, int b) {
//     a = Find(a); b = Find(b);
//     if (a != b) link[a] = b;
//   }
// };
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  // DSU dsu(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    edges.emplace_back(a - 1, b - 1, +c);
    edges.emplace_back(b - 1, a - 1, -c);
    // dsu.Unite(a - 1, b - 1);
  }
  /*
  for (int i = 0; i < n; ++i) {
    cerr << dsu.Find(i) << " ";
  }
  cerr << endl;
  */
  vector<int> minn(n, 0), maxx(n, 1e6);
  vector<int> ans(n, -1), part(n, -1);
  auto solve = [&](int root, bool recon) { 
    for (int x = 0; x < n; ++x) {
      minn[x] = 0; maxx[x] = 1e6; part[x] = -1;
      ans[x] = -1;
    }
    minn[root] = maxx[root] = part[root] = 0;
    
    auto adapt = [&]() {
      int ch = 1;
      while (ch--) {
        // cerr << "iter: " << endl;
        // for (auto x : comp) {
        //   cerr << "  " << x << " -> " << minn[x] << " " << maxx[x] << " " << part[x] << endl;
        // }
        for (auto [a, b, c] : edges) {
          int ominn = minn[b], omaxx = maxx[b];
          if (part[a] != -1 && part[b] == -1) {
            part[b] = !part[a];
            ch = 1;
          }
          if (part[a] != -1 && part[b] != -1 && part[a] == part[b]) {
            // cerr << "  not bipartite" << endl;
            return false;
          }
          if (c) {
            minn[b] = max(minn[b], minn[a] + c);
            maxx[b] = min(maxx[b], maxx[a] + c);
          } else {
            minn[b] = max(minn[b], minn[a] - 1);
            maxx[b] = min(maxx[b], maxx[a] + 1);
          }
          if (part[b] != -1) {
            // cerr << "  fix: " << b + 1 << " " << part[b] << endl;
            while (abs(minn[b] % 2) != part[b]) ++minn[b];
            while (abs(maxx[b] % 2) != part[b]) --maxx[b];
          }
          if (maxx[b] < minn[b]) {
            // cerr << "  overflow" << endl;
            return false;
          }
          if (ominn != minn[b] || omaxx != maxx[b])
            ch = 1;
        }
      }
      return true;
    };
 
    if (!adapt()) return -1;
 
    // cerr << "root: " << root + 1 << endl;
    // for (int x = 0; x < n; ++x) {
    //   cerr << x + 1 << ": " << minn[x] << " " << maxx[x] << endl;
    // }
    // cerr << endl;
    
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      ret = max(ret, maxx[i]);
    }
    if (!recon) return ret;

    for (int it = 0; it < n; ++it) {
      int best = -1, choose = -1;
      for (int x = 0; x < n; ++x) {
        if (ans[x] != -1) continue;
        int val = maxx[x];
        if (best < val) {
          best = val;
          choose = x;
        }
      }
      assert(choose != -1);
      // cerr << "  setting: " << choose + 1 << " to " << minn[choose] << endl;
      minn[choose] = maxx[choose];
      ans[choose] = maxx[choose];
      assert(adapt());
    }
 
    return ret;
  };
 
  int best = -1, choose = -1;
  for (int root = 0; root < n; ++root) {
    int now = solve(root, false);
    if (best < now) {
      best = now;
      choose = root;
    }
  }
  if (choose == -1) {
    cout << "NO\n";
    return 0;
  }
 
  solve(choose, true);
 
  cout << "YES\n";
  int xxx = 0;
  for (int i = 0; i < n; ++i) 
    xxx = max(xxx, ans[i]);
  cout << xxx << '\n';
  for (int i = 0; i < n; ++i)
    cout << ans[i] << " ";
  cout << endl;
 
  return 0;
}