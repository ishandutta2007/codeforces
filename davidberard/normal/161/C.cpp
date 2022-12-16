#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct State {
  int lvl, l1, r1, l2, r2;
  bool operator== (const State& o) const {
    return lvl == o.lvl && l1 == o.l1 && l2 ==o.l2 && r1==o.r1 && r2==o.r2;
  }
};

namespace std {
  template<>
  struct hash<State> {
    size_t operator() (const State& t) const {
      hash<int> inthash;
      return inthash(t.lvl+2e9) + inthash(t.l1) + inthash(t.r1) + inthash(t.l2+1e9) + inthash(t.r2+1e9);
    }
  };
}

unordered_map<State, int> mp;

// inclusive
int solve(int lvl, int l1, int r1, int l2, int r2) {
  if (l1 > r1 || l2 > r2) {
    return 0;
  }
  State st = {lvl, l1, r1, l2, r2};
  if (mp.count(st)) {
    return mp[st];
  }

  //cerr << "  " << lvl << ": " << l1 << "," << r1 << " ; " << l2 << "," << r2 << endl;

  int res = max(min(r2, r1)-max(l2, l1)+1, 0);
  int spl = 1<<(lvl-1);

  if (lvl >= 1) {
    int a = solve(lvl-1, min(l1, spl), min(r1, spl-1), min(l2, spl), min(r2, spl-1));
    int b = solve(lvl-1, max(l1, spl+1)-spl, max(r1, spl)-spl, max(l2, spl+1)-spl, max(r2, spl)-spl);
    int c = solve(lvl-1, min(l1, spl), min(r1, spl-1), max(l2, spl+1)-spl, max(r2, spl)-spl);
    int d = solve(lvl-1, max(l1, spl+1)-spl, max(r1, spl)-spl, min(l2, spl), min(r2, spl-1));
    res = max(max(a, b), res);
    res = max(max(c, d), res);
  }

  return mp[st] = res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int l1, l2, r1, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  cout << solve(30, l1, r1, l2, r2) << "\n";
  return 0;
}