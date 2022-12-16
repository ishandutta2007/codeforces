#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

// returns length of longest nondecreasing subsequence ending at (and including) i.
vector<int> lis(const vector<int>& a) {
  int n = a.size()-1;
  vector<int> f(n+1, INF); // min ending val of a sequence of length i
  f[0] = -INF;
  vector<int> ans(n+1, 0);
  for (int i=1; i<=n; ++i) {
    auto it = --upper_bound(f.begin(), f.end(), a[i]);
    int idx = it-f.begin();
    f[idx+1] = min(f[idx+1], a[i]);
    ans[i] = idx+1;
  }
  return ans;
}

struct Node {
  int va = -INF;
  int l = -1, r = -1;
};

struct PersistentSegtree {
  vector<Node> t;
  int cur = 0;
  int n, h;
  PersistentSegtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t.push_back({-INF, -1, -1});
  }
  void pull(int x) {
    t[x].va = -INF;
    if (t[x].l != -1) {
      t[x].va = max(t[x].va, t[t[x].l].va);
    }
    if (t[x].r != -1) {
      t[x].va = max(t[x].va, t[t[x].r].va);
    }
  }
  int assign(int idx, int v, int x, int lv, int rv) {
    if (idx < lv || rv <= idx) {
      return x;
    }
    int q = t.size();
    t.push_back({-INF, -1, -1});
    if (x != -1) {
      t.back() = t[x];
    }
    if (rv == lv+1) {
      t[q].va = v;
      return q;
    }
    int mv = (lv+rv)/2;
    t[q].l = assign(idx, v, t[q].l, lv, mv);
    t[q].r = assign(idx, v, t[q].r, mv, rv);
    pull(q);
    return q;
  }
  int assign(int idx, int v) {
    return (cur = assign(idx, v, cur, 0, n));
  }
  int query(int l, int r, int x, int lv, int rv) {
    if (x == -1) {
      return -INF;
    }
    if (r <= lv || rv <= l) {
      return -INF;
    }
    if (l <= lv && rv <= r) {
      return t[x].va;
    }
    int mv = (lv+rv)/2;
    int res = 0;
    res = max(res, query(l, r, t[x].l, lv, mv));
    res = max(res, query(l, r, t[x].r, mv, rv));
    return res;
  }
  int query(int l, int r, int x) {
    return query(l, r, x, 0, n);
  }
};

const int N = 200200;
int loc[N];
int spos[N];
int when[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n+1), pre(n+1), suf(n+1);
  vector<pair<int, int>> b, r;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    b.push_back({a[i]-i+1, i});
    r.push_back({a[i]-i, i});
    pre[i] = a[i] - i;
    suf[n+1-i] = -(a[i] - (i-1));
  }
  vector<int> prelis = lis(pre);
  vector<int> suflis = lis(suf);
  sort(b.begin(), b.end());
  sort(r.begin(), r.end());
  for (int i=0; i<b.size(); ++i) {
    spos[b[i].second] = i+1;
  }
  
  for (int i=0, j=0; i<r.size(); ++i) {
    while (j < b.size() && b[j].first < r[i].first) {
      ++j;
    }
    loc[r[i].second] = j+1;
  }
  PersistentSegtree st(n+10);
  for (int i=1; i<=n; ++i) {
    when[n+1-i] = st.assign(spos[n+1-i], suflis[i]);
  }
  int ans = prelis[n-1];
  a[0] = -N+10;
  for (int i=0; i<n-1; ++i) {
    int tlen = st.query(loc[i], n+10, when[i+2]);
    ans = max(ans, prelis[i] + tlen);
  }
  cout << n-1-ans << "\n";
  return 0;
}