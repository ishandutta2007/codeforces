#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 3e5 + 7;
int n, m, k, spec[N], cninit[N], wedge[N], dep[N], mn[N];
bool ispecninit[N];
vector<pair<int, int>> g1[N];
vector<pair<int, int>> nedges;
vector<int> lgs;

void g1dfs(int a) {
  mn[a] = dep[a];
  for (auto &it : g1[a]) {
    int b = it.first, w = it.second;
    if (dep[b] == -1) {
      dep[b] = 1 + dep[a];
      g1dfs(b);
      mn[a] = min(mn[a], mn[b]);
      lgs.push_back(w);
      nedges.push_back({a, b});
      continue;
    }
    if (dep[b] < dep[a] - 1) { /// back edge
      mn[a] = min(mn[a], dep[b]);
    }
  }
}

map<pair<int, int>, int> fast;
set<pair<int, int>> blocked;
bool visfg[N];
int compng[N];
int chompy;
int gain[N];
bool has[N];

void prepg2(int a) {
  gain[chompy] += cninit[a];
  has[chompy] |= ispecninit[a];
  compng[a] = chompy;
  visfg[a] = 1;
  for (auto &it : g1[a]) {
    int b = it.first;
    if (blocked.count({a, b})) {
      continue;
    }
    if (!visfg[b]) {
      prepg2(b);
    }
  }
}

struct Edgg {
  int a, b, w;
};

vector<pair<int, int>> g[N];

int dp[N], total, under[N];

void dfs(int a, int pr = -1) {
  dp[a] = gain[a];
  under[a] = has[a];
  for (auto &it : g[a]) {
    int b = it.first, w = it.second;
    if (b == pr) continue;
    dfs(b, a);
    under[a] += under[b];
    if (under[b] == 0 || under[b] == total) {
      dp[a] += dp[b];
    } else {
      dp[a] += max(0LL, dp[b] - w);
    }
  }
}

void reroot(int a, int pr) {
  int e2 = dp[a], b = pr, w = fast[{a, b}];
  if (under[b] == 0 || under[b] == total) {
    e2 -= dp[b];
  } else {
    e2 -= max(0LL, dp[b] - w);
  }
  dp[a] = e2;
  under[a] -= under[pr];

  under[pr] += under[a];

  b = a;
  if (under[b] == 0 || under[b] == total) {
    dp[pr] += dp[b];
  } else {
    dp[pr] += max(0LL, dp[b] - w);
  }

}

int ret[N];

void rec(int a, int p = -1) {
  ret[a] = dp[a];
  for (auto &it : g[a]) {
    int b = it.first;
    if (b == p) continue;
    reroot(a, b);
    rec(b, a);
    reroot(b, a);
  }
}



signed realMain() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> spec[i];
    ispecninit[spec[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> cninit[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> wedge[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g1[x].push_back({y, wedge[i]});
    g1[y].push_back({x, wedge[i]});
  }
  for (int i = 1; i <= n; i++) {
    dep[i] = -1;
  }
  dep[1] = 0;
  g1dfs(1);
  int stepx = -1;
  vector<Edgg> edgg;
  for (auto &it : nedges) {
    stepx++;
    int a = it.first, b = it.second, w = lgs[stepx];
    if (dep[a] < mn[b]) {
      /// edge from the new graph
      blocked.insert({a, b});
      blocked.insert({b, a});
      edgg.push_back({a, b, w});
     /// cout << " : " << a << " " << b << " -> " << w << "\n";
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!visfg[i]) {
      chompy++;
      prepg2(i);
    }
  }
  for (auto &it : edgg) {
    it.a = compng[it.a];
    it.b = compng[it.b];
    g[it.a].push_back({it.b, it.w});
    g[it.b].push_back({it.a, it.w});
    fast[{it.a, it.b}] = it.w;
    fast[{it.b, it.a}] = it.w;
  }
  int ninit = n;
  n = chompy;
  for (int i = 1; i <= n; i++) {
    total += has[i];
  }
  dfs(1);
  rec(1);
  for (int i = 1; i <= ninit; i++) {
    cout << ret[compng[i]] << " ";
  }
  cout << "\n";
  return 0;
}