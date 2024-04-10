#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
const ll INF = (ll) 1e18 + 7;

struct T {
  int a;
  int b;
  int init_index;
  int sol;
};

bool cmpT_b(T x, T y) {
  return x.b < y.b;
}

bool cmpT_i(T x, T y) {
  return x.init_index < y.init_index;
}

struct DS {
  multiset<int> small;
  int big = (int) 1e9 + 7;
  ll sol = 0;

  void add(int x) {
    if (x < big) {
      small.insert(x);
      sol += x;
    }
  }

  void del(int x) {
    if (small.count(x)) {
      small.erase(small.find(x));
      sol -= x;
      return;
    }
  }

  ll get(int cnt) {
    while ((int) small.size() > cnt) {
      auto it = small.end();
      it--;
      big = *it;
      big = min(big, *it);
      sol -= *it;
      small.erase(it);
    }
    return sol;
  }
};

int n;
int w;
int what_pos_last;
T v[N];

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].a >> v[i].b;
    v[i].init_index = i;
  }


  sort(v + 1, v + n + 1, cmpT_b);

  ll best_total = INF;
  int consumed_x = 0;
  ll cost_x = 0;

  DS ds;

  for (int i = 1; i <= n; i++) {
    ds.add(v[i].a);
  }
  for (int pos_last = 0; pos_last <= n; pos_last++) {
    if (pos_last == 1) {
      consumed_x = 2;
      cost_x = v[1].b;
      ds.del(v[1].a);
    }
    if (pos_last >= 2) {
      consumed_x++;
      cost_x -= v[pos_last - 1].b;
      cost_x += v[pos_last - 1].a;
      cost_x += v[pos_last].b;
      ds.del(v[pos_last].a);
      ds.add(v[pos_last - 1].b - v[pos_last - 1].a);
    }

    if (w - consumed_x < 0) {
      break;
    }

    int need = w - consumed_x;

    if (need > n - (pos_last != 0)) {
      continue;
    }

    ll cost = cost_x + ds.get(need);
    if (cost < best_total) {
      best_total = cost;
      what_pos_last = pos_last;
    }
  }

  int consumed = 0;
  int pos_last = what_pos_last;

  if (pos_last >= 1) {
    consumed = pos_last + 1;
    for (int i = 1; i < pos_last; i++) {
      v[i].sol++;
    }
    v[pos_last].sol += 2;
  }

  int need = max(0, w - consumed);


  vector<pair<int, int>> offers;
  for (int i = 1; i < pos_last; i++) {
    offers.push_back({v[i].b - v[i].a, i});
  }
  for (int i = pos_last + 1; i <= n; i++) {
    offers.push_back({v[i].a, i});
  }

  sort(offers.begin(), offers.end());
  for (int j = 0; j < need; j++) {
    v[offers[j].second].sol++;
  }

  cout << best_total << "\n";
  sort(v + 1, v + n + 1, cmpT_i);
  for (int i = 1; i <= n; i++) {
    cout << v[i].sol;
  }
  cout << "\n";

  exit(0);
}