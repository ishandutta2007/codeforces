#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int M = 333;
int n;
int q;
int y = 1;
int kids[N][26];
int fl[N];
int aib[N];
vector<int> indi[N];
ll sol[2 * N];
int lim[2 * N];
int ind[2 * N];
vector<int> path[N];
vector<int> whoq[N];

int getAib(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}
void addAib(int i, int x) {
  while (i <= y) {
    aib[i] += x;
    i += i & (-i);
  }
}

int l[N];
int r[N];
int temp;
vector<int> g[N];

void dfs(int a, int p = -1) {
  l[a] = ++temp;
  for (auto &b : g[a]) {
    if (b != p) {
      dfs(b);
    }
  }
  r[a] = temp;
}

int cn[N], dep[N];
ll kek[N];
bool ee[N];

int cox(int i, int limit) {
  int sol = 0, l = 0, r = (int) path[i].size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (path[i][m] <= limit) {
      sol = m + 1;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int cur = 1;
    path[i] = {1};
    for (auto &ch : s) {
      int x = ch - 'a';
      if (!kids[cur][x]) {
        kids[cur][x] = ++y;
      }
      cur = kids[cur][x];
      path[i].push_back(cur);
    }
    cn[i] = cur;
    indi[cur].push_back(i);
    assert(y + 1 < N);
  }

  queue<int> qq;
  qq.push(1);
  fl[1] = 1;
  vector<int> ord;
  while (!qq.empty()) {
    int a = qq.front();
    ord.push_back(a);
    qq.pop();
    for (int i = 0; i < 26; i++) {
      if (kids[a][i]) {
        int acum = fl[a];
        while (acum > 1 && !kids[acum][i]) {
          acum = fl[acum];
        }
        if (kids[acum][i] && a != 1) {
          acum = kids[acum][i];
        }
        fl[kids[a][i]] = acum;
        qq.push(kids[a][i]);
      }
    }
  }


  for (int i = 2; i <= y; i++) {
    g[fl[i]].push_back(i);
    dep[i] = 1 + dep[fl[i]];
  }
  dfs(1);

  for (int i = 1; i <= n; i++) {
    for (auto &j : path[i]) {
      j = l[j];
    }
  }
  reverse(ord.begin(), ord.end());

  set<int> sbig;
  for (int i = 1; i <= q; i++) {
    int ll, rr, iind;
    cin >> ll >> rr >> iind;
    lim[i] = rr, ind[i] = iind;
    lim[i + q] = ll - 1, ind[i + q] = iind;
    whoq[lim[i]].push_back(i);
    whoq[lim[i + q]].push_back(i + q);
    if ((int) path[iind].size() >= M) {
      sbig.insert(iind);
    }
  }
  vector<int> big;
  for (auto &i : sbig) {
    big.push_back(i);
    ee[i] = 1;
  }
  q *= 2;
  for (int i = 1; i <= n; i++) {
    sort(path[i].begin(), path[i].end());
  }
  for (int x = 1; x <= n; x++) {
    addAib(l[cn[x]], +1);
    addAib(r[cn[x]] + 1, -1);
    for (auto &i : big) {
      int addToI = cox(i, r[cn[x]]) - cox(i, l[cn[x]] - 1);

      kek[i] += addToI;
    }
    for (auto &i : whoq[x]) {
      /// o(n)
      if (ee[ind[i]]) {
        sol[i] = kek[ind[i]];
        continue;
      }
      for (auto &v : path[ind[i]]) {
        sol[i] += getAib(v);
      }
    }
  }

  q /= 2;
  for (int i = 1; i <= q; i++) {
    cout << sol[i] - sol[q + i] << "\n";
  }
  return 0;
}