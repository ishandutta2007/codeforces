#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

unordered_map<int, int> p, delta;
int ret;

pair<int, int> info(int x) {
  if (!p.count(x)) {
    return make_pair(x, 0);
  } else {
    auto it = info(p[x]);
    it.second ^= delta[x];
    p[x] = it.first;
    delta[x] = it.second;
    return it;
  }
}

void unite(int l, int r, int x) {
  auto it1 = info(l), it2 = info(r);
  if (it1.first == it2.first) return;
  x ^= it1.second;
  x ^= it2.second;
  p[it2.first] = it1.first;
  delta[it2.first] = x;
}

int get(int l, int r) {
  auto it1 = info(l), it2 = info(r);
  if (it1.first == it2.first) {
    return it1.second ^ it2.second;
  } else {
    return -1;
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    l ^= abs(ret);
    r ^= abs(ret);
    if (l > r) swap(l, r);
    l--;
    if (t == 1) {
      int x;
      cin >> x;
      x ^= abs(ret);
      unite(l, r, x);
    } else {
      ret = get(l, r);
      cout << ret << "\n";
    }
  }
}