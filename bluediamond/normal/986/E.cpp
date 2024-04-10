#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int L = (int) 1e7 + 7;
const int N = (int) 1e5 + 7;
const int K = 19;
int n;
int sz;
int top;
int v[N];
int l[N];
int r[N];
int id[N];
int who[N];
int dep[N];
int lp[L];
int lp2[L];
int lg[2 * N];
int fin[N];
int fnode[N];
int snode[N];
int lca_node[N];
int value[N];
pair<int, int> tab[K][2 * N];
vector<int> g[N];
vector<int> primes;

struct tree {
  int t[N];
  vector<int> ops;
  tree() {
    for (int i = 0; i < N; i++) {
      t[i] = 0;
    }
  }
  void add2(int i) {
    while (i <= n) {
      t[i] = 0;
      i += i & (-i);
    }
  }
  void add(int i, int x) {
    ops.push_back(i);
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
  void clr() {
    for (auto &it : ops) {
      add2(it);
    }
    ops.clear();
  }
};

tree t;

void dfs(int a, int p) {
  who[++top] = a;
  id[a] = top;
  tab[0][++sz] = {dep[a], a};
  l[a] = r[a] = sz;
  for (auto &b : g[a]) {
    if (b != p) {
      dep[b] = 1 + dep[a];
      dfs(b, a);
      tab[0][++sz] = {dep[a], a};
      r[a] = sz;
    }
  }
  fin[a] = top;
}

int lca(int a, int b) {
  if (l[a] > r[b]) {
    swap(a, b);
  }
  a = l[a];
  b = r[b];
  int k = lg[b - a + 1];
  return min(tab[k][a], tab[k][b - (1 << k) + 1]).second;
}

int coef(int num, int prime) {
  if (num % prime) {
    return 0;
  } else {
    return 1 + coef(num / prime, prime);
  }
}

vector<int> whoq[100];
int fo[N];
int ret[N];

int main() { /// bye bye MO on tree :(
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i < L; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i < L; j++) {
      lp[primes[j] * i] = primes[j];
    }
    if (lp[i / lp[i]] == lp[i]) {
      lp2[i] = lp2[i / lp[i]] * lp[i];
    } else {
      lp2[i] = lp[i];
    }
  }

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for (int i = 2; i <= sz; i++) {
    lg[i] = 1 + lg[i / 2];
  }
  for (int k = 1; (1 << k) <= sz; k++) {
    for (int i = 1; i + (1 << k) - 1 <= sz; i++) {
      tab[k][i] = min(tab[k - 1][i], tab[k - 1][i + (1 << (k - 1))]);
    }
  }
  vector<pair<int, int>> ow;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    int x = v[i];
    while (x > 1) {
      ow.push_back({lp[x], i});
      x /= lp2[x];
    }
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> fnode[i] >> snode[i] >> value[i];
    lca_node[i] = lca(fnode[i], snode[i]);
    int x = value[i];
    while (x > 1) {
      ow.push_back({lp[x], -i});
      x /= lp2[x];
    }
    ret[i] = 1;
  }
  sort(ow.begin(), ow.end());
  int l = 0;
  while (l < (int) ow.size()) {
    int r = l;
    int prime = ow[l].first;
    while (r + 1 < (int) ow.size() && ow[r].first == ow[r + 1].first) {
      r++;
    }
    vector<int> nodes;
    vector<pair<int, int>> qs;
    int mx = 0;
    for (int j = l; j <= r; j++) {
      if (ow[j].second < 0) {
        qs.push_back({-ow[j].second, coef(value[-ow[j].second], prime)});
        mx = max(mx, qs.back().second);
      } else {
        nodes.push_back(ow[j].second);
        fo[nodes.back()] = coef(v[nodes.back()], prime);
      }
    }
    if (qs.empty()) {
      l = r + 1;
      continue;
    }
    for (int i = 1; i <= mx; i++) {
      whoq[i].clear();
    }
    for (auto &it : qs) {
      whoq[it.second].push_back(it.first);
    }
    t.clr();
    for (int it = 1; it <= mx; it++) {
      for (auto &x : nodes) {
        if (it <= fo[x]) {
          t.add(id[x], +1);
          t.add(fin[x] + 1, -1);
        }
      }
      for (auto &i : whoq[it]) {
        int a = fnode[i];
        int b = snode[i];
        int c = lca_node[i];
        int value = t.get(id[a]) + t.get(id[b]) - 2 * t.get(id[c]);
        value += min(coef(v[c], prime), it);
        ret[i] = mul(ret[i], pw(prime, value));
      }
    }
    l = r + 1;
  }
  for (int i = 1; i <= q; i++) {
    cout << ret[i] << "\n";
  }
}