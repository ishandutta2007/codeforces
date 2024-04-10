#include <bits/stdc++.h>

using namespace std;

struct IntervalContainer {
  map<int, int> s;
  using Iter = map<int, int>::iterator;
  
  Iter AddInterval(int l, int r) {
    if (l == r) return s.end();
    Iter it = s.lower_bound(l);
    while (it != s.end() && it->first <= r) {
      r = max(r, it->second);
      it = s.erase(it);
    }
    while (it != s.begin() && (--it)->second >= l) {
      l = min(l, it->first);
      r = max(r, it->second);
      it = s.erase(it);
    }
    return s.insert({l, r}).first;
  }
  
  Iter FindInterval(int x) {
    auto it = s.upper_bound(x);
    if (it == s.begin() or (--it)->second <= x)
      return s.end();
    return it;
  }
  
  void RemoveInterval(int l, int r) {
    if (l == r) return;
    auto it = AddInterval(l, r);
    int l2 = it->first, r2 = it->second;
    s.erase(it);
    if (l != l2) s.insert({l2, l});
    if (r != r2) s.insert({r, r2});
  }
};

bool Check(vector<pair<int, int>> a, vector<pair<int, int>> b) {
  int n = a.size();
  vector<int> order(n);

  IntervalContainer ic;
  
  vector<tuple<int, int, int>> evs;
  for (int i = 0; i < n; ++i) {
    evs.emplace_back(a[i].first, 0, i);
    evs.emplace_back(a[i].second, -1, i);
  }
  sort(evs.begin(), evs.end());
  for (auto itr : evs) {
    int at, tp, i; tie(at, tp, i) = itr;
    if (tp == 0) {
      auto it = ic.s.lower_bound(b[i].first);
      if (it != ic.s.begin()) --it;
      for (int z = 0; z < 3 && it != ic.s.end(); ++z, ++it) {
        auto p = *it;
        if (max(p.first, b[i].first) < min(p.second, b[i].second))
          return false;
      }
    } else {
      ic.AddInterval(b[i].first, b[i].second);
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<int, int>> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    a[i].second += 1;
    b[i].second += 1;
  }

  if (Check(a, b) && Check(b, a)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }


  return 0;
}