#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

ll funky(ll x) {
  return x * (x - 1) / 2;
}

const int N = (int) 1e5 + 7;
int n, m, p2[100], total;
ll num[100];
bool seen[N];
vector<pair<int, ll>> ginit[N];
vector<int> g[N];

ll pref[N];
int on[100], off[100];

void dfs(int a) {
  seen[a] = 1;
  total++;
  for (auto &it : ginit[a]) {
    int b = it.first;
    if (!seen[b]) {
      pref[b] = pref[a] ^ it.second;
      dfs(b);
    } else {
      ll val = pref[b] ^ pref[a] ^ it.second;
      if (val) {
        for (int bit = 60 - 1; bit >= 0; bit--) {
          if (val & (1LL << bit)) val ^= num[bit];
        }
        if (val) {
          int k = 0;
          while ((1LL << (k + 1)) <= val) k++;
          assert(!num[k]);
          num[k] = val;
        }
      }
    }
  }
  for (int bit = 0; bit < 60; bit++) if (pref[a] & (1LL << bit)) on[bit]++; else off[bit]++;
}

bool este[100];

signed realMain() {
  p2[0] = 1;
  for (int i = 1; i < 100; i++) p2[i] = mul(2, p2[i - 1]);
  cin >> n >> m;
  while (m--) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    ginit[a].push_back({b, c});
    ginit[b].push_back({a, c});
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (seen[i]) continue;
    total = 0;
    for (int bit = 0; bit < 60; bit++) num[bit] = on[bit] = off[bit] = este[bit] = 0;
    dfs(i);
    int bsize = 0;
    for (int bit = 0; bit < 60; bit++) if (num[bit]) {
      bsize++;
      for (int j = 0; j < 60; j++) {
        if (num[bit] & (1LL << j)) este[j] = 1;
      }
    }
    int jumate = (1LL << bsize) / 2 % M;
    int cate = (1LL << bsize) % M;

    for (int bit = 0; bit < 60; bit++) {
      ll t[2];
      t[1] = on[bit] * (ll) off[bit];
      t[0] = funky(total) - t[1];
      t[0] %= M;
      t[1] %= M;
      for (int is = 0; is < 2; is++) {
        int cnt;
        if (este[bit]) {
          /// jumatate din ori o sa fie activ, jumatate nu
          cnt = mul(jumate, t[is]);
        } else {
          /// mereu o sa fie asa cum este
          cnt = is * mul(cate, t[is]);
        }
        ret = add(ret, mul(cnt, p2[bit]));
      }
    }
  }
  cout << ret << "\n";
  return 0;
}