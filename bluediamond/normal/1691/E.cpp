#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int t[N];

int get_root(int a) {
  if (t[a] == a) return a;
  return t[a] = get_root(t[a]);
}

void join(int a, int b) {
  a = get_root(a);
  b = get_root(b);
  t[a] = b;
}

struct Segment {
  int color;
  int l;
  int r;
};

Segment v[N];

bool operator < (Segment a, Segment b) {
  return a.l < b.l;
}

struct Event {
  int type;
  int x;
  int i;
};

bool operator < (Event a, Event b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  return a.type > b.type;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    vector<Event> events;
    for (int i = 1; i <= n; i++) {
      cin >> v[i].color >> v[i].l >> v[i].r;
      t[i] = i;
      assert(0 <= v[i].color && v[i].color <= 1);
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++) {
      events.push_back({+1, v[i].l, i});
      events.push_back({-1, v[i].r, i});
    }
    sort(events.begin(), events.end());
    vector<set<int>> active(2);
    for (auto &it : events) {
      if (it.type == +1) {
        int i = it.i;
        /// open segment i

        int some = -1;

        for (auto &j : active[v[i].color ^ 1]) {
          join(i, j);
          if (some == -1) {
            some = j;
          } else {
            if (v[j].r > v[some].r) {
              some = j;
            }
          }
        }

        active[v[i].color ^ 1].clear();

        if (some != -1) {
          active[v[i].color ^ 1].insert(some);
        }

        active[v[i].color].insert(i);

      } else {
        assert(it.type == -1);
        int i = it.i;
        /// close segment i

        active[v[i].color].erase(i);
      }
    }
    int print = 0;
    for (int i = 1; i <= n; i++) {
      if (get_root(i) == i) {
        print++;
      }
    }
    cout << print << "\n";
  }
}