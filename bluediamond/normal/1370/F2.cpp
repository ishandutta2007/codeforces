#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
int n, dep[N], dist[N];
bool anc[N][N];
vector<int> g[N], path;

void dfs(int a) {
  path.push_back(a);
  for (auto &b : path) {
    anc[b][a] = 1;
  }
  for (auto &b : g[a]) {
    if (dep[b] == -1) {
      dep[b] = 1 + dep[a];
      dfs(b);
    }
  }
  path.pop_back();
}

pair<int, int> get(vector<int> x) {
  cout << "? " << (int) x.size() << " ";
  for (auto &it : x) {
    cout << it << " ";
  }
  cout << endl;
  int a, b;
  cin >> a >> b;
  return {a, b};
}

void fdist(int a) {
  for (auto &b : g[a]) {
    if (dist[b] == -1) {
      dist[b] = 1 + dist[a];
      fdist(b);
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      dep[i] = -1;
      dist[i] = -1;
      for (int j = 1; j <= n; j++) {
        anc[i][j] = 0;
      }
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> all;
    for (int i = 1; i <= n; i++) {
      all.push_back(i);
    }
    pair<int, int> luv = get(all);
    int root = luv.first, di = luv.second;
    dep[root] = 0;
    dfs(root);
    int l = di / 2, r = di, a;
    while (l <= r) {
      int mid = (l + r) / 2;
      vector<int> nos;
      for (int j = 1; j <= n; j++) {
        if (dep[j] >= mid) {
          nos.push_back(j);
        }
      }
      if (nos.empty()) {
        r = mid - 1;
        continue;
      }
      pair<int, int> it = get(nos);
      if (it.second == di) {
        a = it.first;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    dist[a] = 0;
    fdist(a);
    vector<int> atdi;
    for (int j = 1; j <= n; j++) {
      if (dist[j] == di) {
        atdi.push_back(j);
      }
    }
    int b = get(atdi).first;
    cout << "! " << a << " " << b << endl;
    string oio;
    cin >> oio;
  }
  return 0;
}