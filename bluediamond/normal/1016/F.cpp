#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
int n;
int q;
int where[N];
vector<pair<int, int>> g[N];
ll d1[N];
ll d2[N];
ll dif[N];

void put(int node, ll d[]) {
  for (int i = 1; i <= n; i++) {
    d[i] = -1;
  }
  d[node] = 0;
  queue<int> q;
  q.push(node);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto &it : g[a]) {
      int b = it.first;
      ll c = d[a] + it.second;
      if (d[b] == -1) {
        d[b] = c;
        q.push(b);
      }
    }
  }
}

bool cmp(int i, int j) {
  return dif[i] < dif[j];
}

struct T {
  int i;
  ll d1;
  ll d2;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<pair<int, int>> e;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    e.insert({x, y});
    e.insert({y, x});
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  put(1, d1);
  put(n, d2);
  vector<int> o;
  for (int i = 1; i <= n; i++) {
    dif[i] = d1[i] - d2[i];
    o.push_back(i);
  }
  sort(o.begin(), o.end(), cmp);
  ll sol = 0;
  vector<T> kek;
  int y = 0;
  for (auto &i : o) {
    kek.push_back({i, d1[i], d2[i]});
    where[i] = y++;
  }
  multiset<ll> s;
  for (int i = 0; i < n; i++) {
    for (auto &j : g[kek[i].i]) {
      if (where[j.first] < i) {
        s.erase(s.find(kek[where[j.first]].d1));
      }
    }
    if (!s.empty()) {
      auto it = s.end();
      it--;
      sol = max(sol, *it + kek[i].d2);
    }
    s.insert(kek[i].d1);
    for (auto &j : g[kek[i].i]) {
      if (where[j.first] < i) {
        s.insert(kek[where[j.first]].d1);
      }
    }
  }
  while (q--) {
    ll d;
    cin >> d;
    cout << min(d1[n], sol + d) << "\n";
  }
}