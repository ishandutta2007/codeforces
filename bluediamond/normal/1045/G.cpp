#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct robot {
  int x;
  int r;
  int iq;
};

bool operator < (robot a, robot b) {
  return a.x < b.x;
}

const int N = (int) 1e5 + 7;
const int INF = (int) 1e9 + 123;
int n;
int k;
int t[N];
int id[N];
int bef[N];
robot a[N];
ll sol;


struct Event {
  int type;
  int when;
  int i;
};

bool operator < (Event a, Event b) {
  if (a.when == b.when) {
    return a.type > b.type;
  } else {
    return a.when < b.when;
  }
}

void add(int i, int x) {
  while (i <= n) {
    t[i] += x;
    i += i & (-i);
  }
}
int get(int i) {
  int sol = 0;
  while (i) {
    sol += t[i];
    i -= i & (-i);
  }
  return sol;
}
int get(int l, int r) {
  return get(r) - get(l - 1);
}

map<int, vector<int>> certain;
vector<vector<int>> all;
map<int, int> inv_iq;

bool cmp(int i, int j) {
  return a[i].x < a[j].x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].r >> a[i].iq;
    certain[a[i].iq].push_back(i);
  }
  int y = 0;
  for (auto &it : certain) {
    bef[(int) all.size()] = y + 1;
    vector<int> vec = it.second;
    sort(vec.begin(), vec.end(), cmp);
    all.push_back(vec);
    for (auto &i : vec) {
      id[i] = ++y;
    }
    inv_iq[it.first] = (int) all.size() - 1;
  }
  vector<Event> events;
  for (int i = 1; i <= n; i++) {
    events.push_back({+1, a[i].x - a[i].r, i});
    events.push_back({0, a[i].x, i});
    events.push_back({-1, a[i].x + a[i].r, i});
  }
  sort(events.begin(), events.end());
  for (auto &it : events) {
    int i = it.i;
    if (it.type == +1) {
      add(id[i], +1);
    }
    if (it.type == 0) {
      int l = a[i].x - a[i].r;
      int r = a[i].x + a[i].r;
      for (int iq = a[i].iq - k; iq <= a[i].iq + k; iq++) {
        if (inv_iq.count(iq)) {
          int k = inv_iq[iq];
          int p1 = -1, p2 = -1, lo, hi;
          lo = 0;
          hi = (int) all[k].size() - 1;
          while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[all[k][mid]].x <= r) {
              p2 = mid;
              lo = mid + 1;
            } else {
              hi = mid - 1;
            }
          }
          lo = 0;
          hi = (int) all[k].size() - 1;
          while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[all[k][mid]].x >= l) {
              p1 = mid;
              hi = mid - 1;
            } else {
              lo = mid + 1;
            }
          }
          if (p1 == -1 || p2 == -1) {
            continue;
          }
          if (p1 <= p2) {
            sol += get(bef[k] + p1, bef[k] + p2);
          }
        }
      }
    }
    if (it.type == -1) {
      add(id[i], -1);
    }
  }
  sol -= n;
  sol /= 2;
  cout << sol << "\n";
}