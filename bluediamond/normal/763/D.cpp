#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
**/

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

const int M = 1000073251;

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

struct T {
  int len;
  int val;
};

bool operator < (T a, T b) {
  if (a.len == b.len) {
    return a.val < b.val;
  } else {
    return a.len < b.len;
  }
}

const int N = (int) 1e5 + 7;

void compute(int value, int p[], int inv[]) {
  p[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = mul(p[i - 1], value);
  }
  inv[N - 1] = dv(1, p[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    inv[i] = mul(inv[i + 1], value);
  }
}

const int CLOSE = 324693;
const int OPEN = 5913951;
const int BASE = (int) 1e9 + 7;
int p[N], inv[N], par[N];
T open = {1, OPEN};
T close = {1, CLOSE};
T total[N];
int n;
vector<int> g[N];
T down[N];
T up[N];

T operator + (T a, T b) {
  T c;
  c.len = a.len + b.len;
  c.val = add(a.val, mul(p[a.len], b.val));
  return c;
}

void boy(int a, int p = -1) {
  par[a] = p;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b == p) {
      continue;
    }
    boy(b, a);
    kids.push_back(b);
  }
  g[a] = kids;
  vector<T> okids;
  for (auto &b : kids) {
    okids.push_back(down[b]);
  }
  sort(okids.begin(), okids.end());
  T ret = open;
  for (auto &it : okids) {
    ret = ret + it;
  }
  ret = ret + close;
  down[a] = ret;
}

vector<pair<T, int>> okintos[N];
map<int, int> where[N];
vector<T> pref[N], suf[N];

void girl(int a, int p = -1) {
  if (p != -1) {
    int unde = where[p][a];
    up[a] = pref[p][unde] + suf[p][unde + 1];
  }
  if (p != -1) {
    okintos[a].push_back({up[a], -1});
  }
  for (auto &b : g[a]) {
    okintos[a].push_back({down[b], b});
  }
  sort(okintos[a].begin(), okintos[a].end());
  pref[a].push_back(open);
  for (auto &it : okintos[a]) {
    pref[a].push_back(pref[a].back() + it.first);
  }
  suf[a].push_back(close);
  for (int p = (int) okintos[a].size() - 1; p >= 0; p--) {
    suf[a].push_back(okintos[a][p].first + suf[a].back());
  }
  reverse(suf[a].begin(), suf[a].end());
  int pos = 0;
  for (auto &it : okintos[a]) {
    where[a][it.second] = pos;
    pos++;
  }
  for (auto &b : g[a]) {
    girl(b, a);
  }
}

int cnt[N];
map<T, int> mp;
int active = 0;

void baga(T a) {
  mp[a]++;
  active += (mp[a] == 1);
}

void scoate(T a) {
  mp[a]--;
  active -= (mp[a] == 0);
}

void rec(int a) {
  cnt[a] = active;
  for (auto &b : g[a]) {
    scoate(total[a]); baga(up[b]);
    scoate(down[b]); baga(total[b]);
    rec(b);
    baga(total[a]); scoate(up[b]);
    baga(down[b]); scoate(total[b]);
  }
  assert(active == cnt[a]);
}

signed realMain() {
  {
    compute(BASE, p, inv);
  }

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  boy(1);
  girl(1);
  for (int i = 1; i <= n; i++) {
    baga(down[i]);
  }
  for (int i = 1; i <= n; i++) {
    vector<T> okids;
    if (par[i] != -1) {
      okids.push_back(up[i]);
    }
    for (auto &j : g[i]) {
      okids.push_back(down[j]);
    }
    sort(okids.begin(), okids.end());
    T ret = open;
    for (auto &it : okids) {
      ret = ret + it;
    }
    ret = ret + close;
    total[i] = ret;
  }
  rec(1);



  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, cnt[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (mx == cnt[i]) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}