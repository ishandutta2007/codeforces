#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
int n;
int sum[N];
bool vis[N];
vector<int> g[2 * N];
vector<vector<int>> paths;
vector<int> stk;

/**
void dfs(int a) {
  paths.back().push_back(a);
  for (auto &i : g[a]) {
    if (vis[i] == 0) {
      vis[i] = 1;
      dfs(sum[i] - a);
      paths.back().push_back(a);
    }
  }
}
**/

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    sum[i] = a + b;
    g[a].push_back(i);
    g[b].push_back(i);
  }


  for (int v = 1; v <= 2 * n; v++) {
    paths.push_back({});
    stk.push_back(v);
    while (!stk.empty()) {
      int a = stk.back();
      paths.back().push_back(a);
      bool go = 0;
      while (!g[a].empty()) {
        int i = g[a].back();
        g[a].pop_back();
        if (vis[i] == 0) {
          vis[i] = 1;
          go = 1;
          stk.push_back(sum[i] - a);
          break;
        }
      }
      if (go) {
        continue;
      } else {
        stk.pop_back();
      }
    }
    assert(!paths.empty());
    if ((int) paths.back().size() == 1) {
      paths.pop_back();
      continue;
    }
    assert(!paths.empty());
    if ((int) paths.back().size() == 3) {
      cout << "-1\n";
      return 0;
    }
    assert(!paths.empty());
    paths.back().pop_back();
    assert((int) paths.back().size() % 2 == 0);
  }

  vector<pair<int, int>> sol;
  vector<string> fs, sc;

  for (auto &path : paths) {
    for (int i = 0; i < (int) path.size() / 2; i++) {
      sol.push_back({path[i], path[(int) path.size() - 1 - i]});
    }
    if (((int) path.size() / 2) % 2 == 0) {
      for (int i = 0; i < (int) path.size() / 2; i++) {
        if (i % 2 == 0) {
          fs.push_back("UU");
        } else {
          fs.push_back("DD");
        }
      }
      sc.push_back("LR");
      for (int i = 0; i < (int) path.size() / 2 - 2; i++) {
        if (i % 2 == 0) {
          sc.push_back("UU");
        } else {
          sc.push_back("DD");
        }
      }
      sc.push_back("LR");
    } else {
      for (int i = 0; i < (int) path.size() / 2 - 1; i++) {
        if (i % 2 == 0) {
          fs.push_back("UU");
        } else {
          fs.push_back("DD");
        }
      }
      fs.push_back("LR");
      sc.push_back("LR");
      for (int i = 0; i < (int) path.size() / 2 - 1; i++) {
        if (i % 2 == 0) {
          sc.push_back("UU");
        } else {
          sc.push_back("DD");
        }
      }
    }
  }

  cout << (int) sol.size() << " " << 2 << "\n\n";

  for (auto &it : sol) {
    cout << it.first << " " << it.second << "\n";
  }
  cout << "\n";

  for (auto &s : fs) {
    cout << s << "\n";
  }
  cout << "\n";

  for (auto &s : sc) {
    cout << s << "\n";
  }

  return 0;

  for (auto &path : paths) {
    cout << " ---> " << (int) path.size() << "\n";
  }

}


/**

**/