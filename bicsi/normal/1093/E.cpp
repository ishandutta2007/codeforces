#include <bits/stdc++.h>
 
using namespace std;
 
struct SegTree {
  int n;
  vector<vector<int>> data, all;
 
  SegTree(int n) : n(n), data(n + 1), all(n + 1) {}
 
  void FakeUpdate(int x, int y) {
    for (++x; x < (int)all.size(); x += x & -x) {
      all[x].push_back(y);
    }
  }
 
  void Init() {
    for (int i = 0; i < (int)all.size(); ++i) {
      sort(all[i].begin(), all[i].end());
      all[i].erase(unique(all[i].begin(), all[i].end()), all[i].end());
      data[i].resize(all[i].size() + 1, 0);
    }
  }
 
  void Update(int x, int y, int d) {
    for (++x; x < (int)all.size(); x += x & -x) {
      int pos = lower_bound(all[x].begin(), all[x].end(), y)
       - all[x].begin();
      assert(all[x][pos] == y);
      for (++pos; pos < (int)data[x].size(); pos += (pos & -pos))
        data[x][pos] += d;
    }
  }
 
  int Query(int y, int x) {
    int ans = 0;
    for (++x; x > 0; x -= (x & -x)) {
      int pos = upper_bound(all[x].begin(), all[x].end(), y)
        - all[x].begin() - 1;
      for (++pos; pos > 0; pos -= (pos & -pos))
        ans += data[x][pos];
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
 
  vector<int> a(n), remap(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i]; --a[i];
    remap[a[i]] = i;
  }
 
  SegTree st(n);
 
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i]; --v[i];
    v[i] = remap[v[i]];
    st.FakeUpdate(i, v[i]);
  }
  
  vector<int> _v = v;
  
  vector<tuple<int, int, int, int, int>> qrs;
  for (int i = 0; i < m; ++i) {
    int t; cin >> t;
    if (t == 1) {
      int l, r, lp, rp; cin >> l >> r >> lp >> rp;
      --l; --r; --lp; --rp;
      qrs.emplace_back(1, l, r, lp, rp);
    } else {
      assert(t == 2);
      int x, y; cin >> x >> y; --x; --y;
      st.FakeUpdate(x, v[y]);
      st.FakeUpdate(y, v[x]);
      qrs.emplace_back(2, x, y, -1, -1);
      swap(v[x], v[y]);
    }
  }
 
  v = _v;
 
  st.Init();
  for (int i = 0; i < n; ++i) {
    st.Update(i, v[i], 1);
  }
 
  for (int i = 0; i < m; ++i) {
    int t, l, r, lp, rp; tie(t, l, r, lp, rp) = qrs[i];
 
    if (t == 1) {
      int ans = st.Query(r, rp) - st.Query(l - 1, rp)
        - st.Query(r, lp - 1) + st.Query(l - 1, lp - 1);
      cout << ans << '\n';
    } else {
      int x = l, y = r;
      st.Update(x, v[x], -1);
      st.Update(y, v[y], -1);
      swap(v[x], v[y]);
      st.Update(x, v[x], 1);
      st.Update(y, v[y], 1);
    }
  }
 
  return 0;
}