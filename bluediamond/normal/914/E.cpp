#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 2e5 + 7;
const int A = 1 << 20;
int n, sg[N];
int sol[N];
vector<int> gr[N];
bool vis[N];
int sub[N], up[N];
int total;
vector<int> nodes;
vector<int> kids[N];

void build(int a, int p = -1) {
  sub[a] = 1;
  nodes.push_back(a);
  for (auto &b : gr[a]) {
    if (!vis[b] && b != p) {
      build(b, a);
      sub[a] += sub[b];
    }
  }
}

int fcen(int a, int p = -1) {
  int mx = total - sub[a];
  for (auto &b : gr[a]) {
    if (!vis[b] && b != p) {
      mx = max(mx, sub[b]);
    }
  }
  if (mx <= total / 2) {
    return a;
  }
  for (auto &b : gr[a]) {
    if (!vis[b] && b != p && mx == sub[b]) {
      return fcen(b, a);
    }
  }
  assert(0);
}

void dfs(int a, int p = -1) {
  kids[a] = {};
  for (auto &b : gr[a]) {
    if (!vis[b] && b != p) {
      up[b] = up[a] ^ sg[b];
      dfs(b, a);
      kids[a].push_back(b);
    }
  }
}

int f1[A];

vector<int> vals;
vector<int> lmao;

void place(int a) {
  vals.push_back(up[a]);
  for (auto &b : kids[a]) {
    place(b);
  }
}

void addup(int a, int x) {
  f1[up[a]] += x;
  for (auto &b : kids[a]) {
    addup(b, x);
  }
}

int gather[N];

void rek(int a) {
  gather[a] = 0;
  for (auto &zo : lmao) {
    gather[a] += f1[up[a] ^ zo];
  }
  for (auto &b : kids[a]) {
    rek(b);
    gather[a] += gather[b];
  }
  sol[a] += gather[a];
}


void solve(int a) {
  nodes.clear();
  build(a);
  if (sub[a] == 1) {
  ///  cout << "regeton " << a << "\n";
    sol[a]++;
    return;
  }
  total = sub[a];
  a = fcen(a);
  up[a] = sg[a];
  dfs(a);
  lmao = {0};
  for (int bit = 0; (1 << bit) < A; bit++) {
    lmao.push_back(1 << bit);
  }
  for (auto &x : lmao) {
    x ^= sg[a];
  }

  f1[up[a]]++;
  sol[a]++;
  for (auto &b : kids[a]) {
    vals.clear();

    place(b);
    for (auto &it : vals) {
      for (auto &zo : lmao) {
        sol[a] += f1[it ^ zo];
      }
    }
    addup(b, +1);

  }
  for (auto &b : kids[a]) {
    addup(b, -1);
    rek(b);
    addup(b, +1);
  }
  for (auto &b : kids[a]) {
    addup(b, -1);
  }
  f1[up[a]]--;
  vis[a] = 1;
 /// cout << " = " << a << "\n";
  for (auto &b : gr[a]) {
    if (!vis[b]) {
      solve(b);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  {
    string str;
    cin >> str;
    for (int i = 1; i <= n; i++) {
      sg[i] = (1 << (str[i - 1] - 'a'));
      assert(sg[i] < A);
    }
  }

  solve(1);
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
  return 0;
}