#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

const int N = (int)1e5 + 7;
const ll INF = (ll)1e18 + 7;
int n;
ll t, cookies[N], teat[N], len[N], have[N], ar[N], eat[N], what[N], mulbi[N];
int sum[4 * N];
ll hv[4 * N];
ll ml[N];
ll lhv[4 * N];
ll lml[4 * N];
bool valid[N];
ll tt, cc, sl[N];
vector<int> g[N];

int l[N], r[N], top;

void build(int a) {
  l[a] = ++top;
  for (auto& b : g[a]) {
    ar[b] = ar[a] + len[b];
    build(b);
  }
  r[a] = top;
}

void dfs(int a) {
  what[a] = sl[l[a]];
  vector<ll> vals;
  for (auto& b : g[a]) {
    dfs(b);
    vals.push_back(what[b]);
  }
  sort(vals.rbegin(), vals.rend());
  vals.push_back(0);
  vals.push_back(0);
  if (a == 1) {
    what[a] = max(what[a], vals[0]);
  }
  else {
    what[a] = max(what[a], vals[1]);
  }
}



void join(int v) {
  sum[v] = sum[2 * v] + sum[2 * v + 1];
  if (sum[v] == 0) {
    return;
  }
  if (sum[2 * v] && sum[2 * v + 1]) {
    hv[v] = min(hv[2 * v], hv[2 * v + 1]);
  }
  else {
    if (sum[2 * v])hv[v] = hv[2 * v]; else hv[v] = hv[2 * v + 1];
  }
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    sum[v] = valid[tl];
    hv[v] = have[tl];

  }
  else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    join(v);
  }
}

void push(int v, int tl, int tr) {
  if (lhv[v]) {
    hv[v] += lhv[v];
    if (tl < tr) {
      lhv[2 * v] += lhv[v];
      lhv[2 * v + 1] += lhv[v];
    }
    lhv[v] = 0;
  }
  if (lml[v]) {
    if (tl == tr) {
      ml[tl] += lml[v];
    }
    else {
      int tm = (tl + tr) / 2;
      lml[2 * v] += lml[v];
      lml[2 * v + 1] += lml[v];
    }
    lml[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, ll t, ll cnt) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lhv[v] -= t * cnt;
    lml[v] += cnt;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, t, cnt);
  add(2 * v + 1, tm + 1, tr, l, r, t, cnt);
  join(v);
}



void kill(int v, int tl, int tr) {
  push(v, tl, tr);
  if (sum[v] == 0 || hv[v] >= 0)return;

  if (tl == tr) {
    sum[v] = 0;

    ll kol = hv[v] + tt * cc;
    sl[tl] = kol / tt + ml[tl] - cc;
    return;
  }
  int tm = (tl + tr) / 2;
  kill(2 * v, tl, tm);
  kill(2 * v + 1, tm + 1, tr);
  join(v);
}

void save(int v, int tl, int tr) {
  push(v, tl, tr);
  if (!sum[v])return;
  if (tl == tr) {
    sl[tl] = ml[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  save(2 * v, tl, tm);
  save(2 * v + 1, tm + 1, tr);
  join(v);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> cookies[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> teat[i];
  }
  for (int i = 2; i <= n; i++) {
    int pp;
    cin >> pp >> len[i];
    g[pp].push_back(i);
  }
  build(1);
  assert(top == n);
  for (int i = 1; i <= n; i++) {
    have[l[i]] = max(0LL, t - 2 * ar[i]);
    valid[l[i]] = (have[l[i]] > 0);
  }
  build(1, 1, n);
  vector<pair<int, int>> ofs;
  for (int i = 1; i <= n; i++) {
    ofs.push_back({ teat[i], i });
  }
  sort(ofs.begin(), ofs.end());
  for (auto& OF : ofs) {
    int i = OF.second;
    /// l[i], r[i]
    int lft = l[i], rgh = r[i];

    ll full = teat[i] * (ll)cookies[i];


    tt = teat[i];
    cc = cookies[i];
    add(1, 1, n, lft, rgh, teat[i], cookies[i]);
    kill(1, 1, n);
    push(1, 1, n);

  }
  save(1, 1, n);

  assert(!g[1].empty());
  dfs(1);
  cout << what[1] << "\n";
}