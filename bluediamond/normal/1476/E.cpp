/// lmao I initially solved a completely different problem and wasted 30 minutes :/ my problem was much harder than this one lol but I solved it:)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 1e5 + 7;
int n;
int m;
int k;
string p[N];
string s[N];
int mt[N];
map<string, int> id;
vector<int> g[N];
vector<int> ret;
bool vis[N];
bool act[N];

void dfs(int a) {
  if (vis[a]) {
    return;
  }
  vis[a] = act[a] = 1;
  for (auto &b : g[a]) {
    if (act[b]) {
      cout << "NO\n";
      exit(0);
    }
    dfs(b);
  }
  act[a] = 0;
  ret.push_back(a);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    id[p[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> s[i] >> mt[i];
  }
  for (int i = 1; i <= m; i++) {
    vector<int> mtch;
    for (int mask = 0; mask < (1 << k); mask++) {
      string pat;
      for (int j = 0; j < k; j++) {
        if (mask & (1 << j)) {
          pat += "_";
        } else {
          pat += s[i][j];
        }
      }
      if (id.count(pat)) {
        mtch.push_back(id[pat]);
      }
    }
    bool has = 0;
    for (auto &it : mtch) {
      if (it == mt[i]) {
        has = 1;
        break;
      }
    }
    for (auto &it : mtch) {
      if (it != mt[i]) {
        g[it].push_back(mt[i]);
      }
    }
    if (!has) {
      cout << "NO\n";
      return 0;
    }
    ///ind[mt[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  cout << "YES\n";
  for (auto &x : ret) {
    cout << x << " ";
  }
  cout << "\n";
}