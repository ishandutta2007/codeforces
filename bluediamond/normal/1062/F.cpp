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

const int N = 300000 + 7;
int n, m, cnt[N], ex[N], ey[N], grad[N], unic[N], lac[N];
vector<int> g[N], top, intra[N];
bool vis[N];

void find_top(int a) {
  vis[a] = 1;
  for (auto &b : g[a]) {
    if (!vis[b]) {
      find_top(b);
    }
  }
  top.push_back(a);
}

int step;

void baga() {
  step++;
  for (int i = 1; i <= n; i++) g[i].clear(), vis[i] = 0, intra[i].clear(), grad[i] = 0;
  for (int i = 1; i <= m; i++) {
    intra[ey[i]].push_back(ex[i]);
    g[ex[i]].push_back(ey[i]);
  }
  if (step == 1) {
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        find_top(i);
      }
    }
  }
  reverse(top.begin(), top.end());
  set<int> faine;
  for (auto &x : top) {
    faine.insert(x);
    for (auto &nod : intra[x]) {
      if (grad[nod] == 0) {
        lac[nod] = x;
        unic[x]++;
      }
      if (grad[nod] == 1) {
        unic[lac[nod]]--;
      }
      grad[nod]++;
      faine.erase(nod);
    }
    if ((int) faine.size() == 1) {
      continue;
    }
    if ((int) faine.size() == 2) {
      int y = -x;
      for (auto &noduri_faine : faine) y += noduri_faine;
      if (unic[y] == 0) {
        cnt[x] += 1;
      } else {
        cnt[x] += 2;
      }
      continue;
    }
    cnt[x] += 2;
  }
}

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> ex[i] >> ey[i];
  }
  baga();
  for (int i = 1; i <= m; i++) {
    swap(ex[i], ey[i]);
  }
  baga();
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] <= 1) {
      if (home) {
        cout << i << " ";
      }
      ret++;
    }
  }
  if (home) {
    cout << "\n";
    cout << " : " << ret << "\n";
    return 0;
  }
  cout << ret << "\n";

  return 0;
}