#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
const int N = (1 << 11) + 7;
const int INF = (int) 1e18;
const int INF2 = (int) 1e9;
int bts, cb[N];
int k;
int s;
int d;
int cap[N][N];
int cost[N][N];
vector<int> g[N], ret;
int best[N];
int par[N];
bool act[N];
int iau[N];
bool deja[N];
vector<int> v;

void baga(int a, int b, int cp, int cst) {
 // cout << a << " " << b << " and " << cst << "\n";
  g[a].push_back(b);
  b[g].push_back(a);
  cap[a][b] = cp;
  cost[a][b] = cst;
  cost[b][a] = -cost[a][b];
}

void baga(int i) {
  assert(!deja[i]);
  deja[i] = 1;
  if (iau[i] == -1) {
    int need = v[i];
    for (int bit = 0; (1 << bit) <= need; bit++) {
      if (need & (1 << bit)) ret.push_back(bit);
    }
    return;
  }
  baga(iau[i]);
  int need = v[i] - v[iau[i]];
  for (int bit = 0; (1 << bit) <= need; bit++) {
    if (need & (1 << bit)) ret.push_back(bit);
  }
}

signed main() {
 /// freopen ("input", "r", stdin);
  for (int i = 0; i < N; i++) {
    for (int j = 0; (1 << j) <= i; j++) {
      if (i & (1 << j)) cb[i]++;
    }
  }
  cin >> bts >> k;
  for (int it = 1; it <= k; it++) {
    string s;
    cin >> s;
    assert((int) s.size() == bts);
    int mask = 0;
    for (int j = 0; j < bts; j++) {
      if (s[j] == '1') {
        mask += (1 << j);
      }
    }
    v.push_back(mask);
  }
  vector<pair<int, int>> lol;
  for (int i = 0; i < k; i++) {
    iau[i] = -1;
  }
  s = 2 * k;
  d = 2 * k + 1;
  for (int i = 0; i < k; i++) {
    baga(s, i, 1, 0);
    baga(i + k, d, 1, 0);
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (i != j) {
        if ((v[i] & v[j]) == v[j]) {
          /// pe j il iau pe gratis
          int red = cb[v[j]] + 1;
          baga(j, i + k, 1, -red);
          lol.push_back({j, i + k});
        }
      }
    }
  }
  int n = d + 1;

  int flow = 0, ans = 0;
  while (1) {
    for (int i = 0; i < n; i++) {
      best[i] = INF;
    }
    act[s] = 1;
    best[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      act[a] = 0;
      for (auto &b : g[a]) {
        if (cap[a][b] > 0 && best[a] + cost[a][b] < best[b]) {
          best[b] = best[a] + cost[a][b];
          par[b] = a;
          if (act[b] == 0) {
            act[b] = 1;
            q.push(b);
          }
        }
      }
    }
    if (best[d] == INF) {
      break;
    }
    int mn = INF, now = d;
    while (now != s) {
      int a = par[now];
      int b = now;
      mn = min(mn, cap[a][b]);
      now = par[now];
    }
    flow += mn;
    ans += (ll) best[d] * mn;
    now = d;
    while (now != s) {
      int a = par[now];
      int b = now;
      cap[a][b] -= mn;
      cap[b][a] += mn;
      now = par[now];
    }
  }
  ///cout << flow << "\n";
  int no_bits = 0, no_nums = k;
  for (auto &x : v) {
    no_bits += cb[x];
  }
  for (auto &it : lol) {
    int j = it.first, i = it.second - k;
    if (cap[j][i + k] == 0) {
    ///  cout << j << " bef " << i << "\n";
      iau[i] = j;
    }
  }
  //cout << no_bits << " " << no_nums << " " << ans << "\n";

 // cout << no_bits + no_nums + ans << "\n";

  vector<pair<int, int>> ord;
  for (int i = 0; i < k; i++) {
    ord.push_back({v[i], i});
  }
  sort(ord.rbegin(), ord.rend());
  for (auto &it : ord) {
    int i = it.second;
    if (deja[i]) continue;
    baga(i);
  ///  cout << " sz = " << (int) ret.size() << "\n";
    ret.push_back(-1);
  }
  assert((int) ret.size() == no_bits + no_nums + ans);
  ret.pop_back();
  cout << (int) ret.size() << "\n";
  for (auto &x : ret) {
    if (x == -1) {
      cout << "R ";
    } else {
      cout << x << " ";
    }
  }
  cout << "\n";
}