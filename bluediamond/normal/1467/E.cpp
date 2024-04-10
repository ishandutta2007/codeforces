#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
int top;
int all;
int v[N];
int l[N];
int r[N];
int aib[N];
int cnt[N];
bool bad[N];
vector<int> g[N];

void add_aib(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int get(int i) {
  int ret = 0;
  while (i) {
    ret += aib[i];
    i -= i & (-i);
  }
  return ret;
}

void add(int a) {
  add_aib(l[a], +1);
}

void del(int a) {
  add_aib(l[a], -1);
}

int cnt_under(int x) {
  return get(r[x]) - get(l[x] - 1);
}

void dfs(int a, int p = -1) {
  vector<int> kids;
  l[a] = ++top;
  for (auto &b : g[a]) {
    if (b != p) {
      dfs(b, a);
      kids.push_back(b);
    }
  }
  g[a] = kids;
  r[a] = top;
}

int ret;

void solve(int a) {
  ret += !bad[a] && (cnt[a] == all);
  for (auto &b : g[a]) {
    bad[b] |= bad[a];
    cnt[b] += cnt[a];
    solve(b);
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n;
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    mp[v[i]].push_back(i);
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  for (auto &it : mp) {
    vector<int> p = it.second;
    if ((int) p.size() == 1) {
      continue;
    }
    for (auto &a : p) {
      add(a);
    }
    for (auto &a : p) {
      int x = cnt_under(a);
      if (x >= 1 && x < (int) p.size()) {
        bad[a] = 1;
      }
      if (x >= 2 && x < (int) p.size()) {
        cout << "0\n";
        return 0;
      }
      if (x >= 2) {
        for (auto &b : g[a]) {
          int x = cnt_under(b);
          if (x >= 1) {
            all++;
            cnt[b]++;
          }
        }
      }
    }
    for (auto &a : p) {
      del(a);
    }
  }
  solve(1);
  cout << ret << "\n";
}