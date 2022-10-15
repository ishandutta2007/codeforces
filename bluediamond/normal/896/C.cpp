#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pw(ll a, ll b, ll mod) {
  ll r = 1;
  a %= mod;
  while (b) {
    if (b & 1) r = r * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return r;
}

struct Interval {
  int l;
  int r;
  ll x;
};

bool operator < (Interval a, Interval b) {
  if (a.r == b.r) {
    return a.x < b.x;
  }
  return a.r < b.r;
}

bool cmpX(Interval a, Interval b) {
  return a.x < b.x;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int n, m, seed, vmax;
  cin >> n >> m >> seed >> vmax;

  function<int()>rnd = [&]() {
    int ret = seed;
    seed = (seed * (ll)7 + 13) % 1000000007;
    return ret;
  };



  vector<vector<int>> operations;
  for (int i = 0; i < n; i++) {
    operations.push_back({ 2, i, i, rnd() % vmax + 1 });
  }

  for (int i = 0; i < m; i++) {
    int op = rnd() % 4 + 1;
    int l = rnd() % n;
    int r = rnd() % n;
    int x;
    if (l > r) swap(l, r);

    if (op == 3) {
      x = (rnd() % (r - l + 1)) + 1;
    }
    else {
      x = (rnd() % vmax) + 1;
    }

    if (op == 4) {
      int y = (rnd() % vmax) + 1;
      operations.push_back({ op, l, r, x, y });
    }
    else {
      operations.push_back({ op, l, r, x });
    }
  }
  set<Interval> s;
  s.insert({ 0, n - 1, 0 });
  for (auto& o : operations) {
    int op = o[0], l = o[1], r = o[2], x = o[3];
    auto it = s.lower_bound({ -1, l, -1 });
    vector<Interval> cur;
    while (1) {
      if (it == s.end()) break;
      if (it->l > r) break;
      cur.push_back(*it);
      it++;
    }

    if (op <= 2) {
      for (auto& x : cur) {

        s.erase(x);
      }

      if (cur[0].l < l) {
        s.insert({ cur[0].l, l - 1, cur[0].x });
      }
      if (cur.back().r > r) {
        s.insert({ r + 1, cur.back().r, cur.back().x });
      }
    }
    else {
      for (auto& it : cur) {
        it.l = max(it.l, l);
        it.r = min(it.r, r);
      }
    }

    if (op == 1) {
      if ((int)cur.size() == 1) {

        s.insert({ l, r, cur[0].x + x });
      }
      else {

        s.insert({ l, cur[0].r, cur[0].x + x });
        s.insert({ cur.back().l, r, cur.back().x + x });
        for (int j = 1; j < (int)cur.size() - 1; j++) {
          s.insert({ cur[j].l, cur[j].r, cur[j].x + x });
        }
      }
    }
    if (op == 2) {
      s.insert({ l, r, x });
    }
    if (op == 3) {
      sort(cur.begin(), cur.end(), cmpX);
      for (auto& it : cur) {
        int now = it.r - it.l + 1;
        if (x <= now) {
          cout << it.x << " ";
          break;
        }
        else {
          x -= now;
        }
      }
      cout << "\n";
    }
    if (op == 4) {
      int y = o.back();
      ll sol = 0;
      for (auto& it : cur) {
        sol = (sol + (ll)(it.r - it.l + 1) * pw(it.x, x, y)) % y;
      }
      cout << sol << "\n";
    }
  }

  return 0;
}