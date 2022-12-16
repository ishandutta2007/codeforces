#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INFLL = 0x3f3f3f3f3f3f3f3f;

struct Op {
  string s;
  int u, v;
};

int n, s;
vector<Op> ops;

int assigncnt = 0;

struct Di {
  unordered_map<int, ll> mp;
  ll off = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

  void assign(int x, ll v) {
    mp[x] = v-off;
    pq.push({v-off, x});
  }
  ll get(int x) {
    if (!mp.count(x)) {
      return INFLL;
    }
    return mp[x]+off;
  }
  void assign_min(int x, ll v) {
    if (get(x) > v) {
      assign(x, v);
    }
  }
  void incr(ll v) {
    off += v;
  }
  void erase(int x) {
    mp.erase(x);
    mp[x] = INFLL;
  }
  size_t size() const {
    return mp.size();
  }
  ll query_min() {
    while (!pq.empty()) {
      if (pq.top().first+off != get(pq.top().second)) {
        pq.pop();
        continue;
      }
      return pq.top().first+off;
    }
    return INFLL;
  }

};

int merges = 0;
Di solve(int& idx, int va) {
  Di mpp;
  mpp.assign(va, 0);
  while (idx < n) {
    //cerr << ": " << idx << endl;
    //cerr << ops[idx].s << " " << ops[idx].u << " " << ops[idx].v << endl;
    if (ops[idx].s[0] == 'e') {
      ++idx;
      return mpp;
    }
    else if (ops[idx].s[0] == 'i') {
      int u = ops[idx].u;
      ++idx;
      ll extra = mpp.get(u);
      auto res = solve(idx, u);
      if (extra < INFLL) {
        res.incr(extra);
        mpp.erase(u);
        if (res.size() > mpp.size()) {
          swap(res, mpp);
        }
        for (auto& [x, v] : res.mp) {
          mpp.assign_min(x, v+res.off);
          ++ merges;
          /*
          if (s == 1040) {
            assert(merges < 5000);
          }
          */
        }
      }
    } else {
      int u = ops[idx].u;
      int v = ops[idx].v;
      if (u == s) {
        mpp.incr(v);
      } else {
        ll qm = mpp.query_min();
        //ll qm = 1231;
        mpp.incr(v);
        mpp.assign(u, qm);
      }
      ++idx;
    }
    //cerr << " :: ";
    //for (auto& [x, v] : mpp.mp) {
      //cerr << " " << x<< " -> " << mp.off+v << "; ";
    //}
    //cerr << endl;
  }
  return mpp;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s;
  for (int i=0; i<n; ++i) {
    Op op;
    cin >> op.s;
    if (op.s[0] == 's') {
      cin >> op.u >> op.v;
    } else if (op.s[0] == 'i') {
      cin >> op.u;
    }
    ops.push_back(op);
  }
  int idx = 0;
  auto res = solve(idx, 0);
  ll ans = INFLL;
  for (auto& [x, v] : res.mp) {
    ans = min(ans, v + res.off);
  }
  cout << ans << "\n";
  return 0;
}