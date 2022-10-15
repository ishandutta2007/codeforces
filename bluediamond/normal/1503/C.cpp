#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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
}
**/
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

struct T {
  int p, c;
};

bool operator < (T a, T b) {
  return a.p < b.p;
}

const int N = (int) 4e5 + 7;
const int INF = (int) 1e18;

void upd(int aib[], int pos, int val) {
  while (pos < N) aib[pos] = min(aib[pos], val), pos += pos & (-pos);
}

int get(int aib[], int pos) {
  int ret = INF;
  while (pos) ret = min(ret, aib[pos]), pos -= pos & (-pos);
  return ret;
}

int n, dp[N], gamma[N], omega[N], tg[N], to[N], aib1[N], aib2[N], tg2[N], to2[N];
T a[N];

signed realMain() {
  cin >> n;
  for (int i = 0; i < N; i++) aib1[i] = aib2[i] = INF;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].p >> a[i].c;
  }
  sort(a + 1, a + n + 1);
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    ret += a[i].c;
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = INF;
  }
  map<int, int> trap;
  for (int i = 1; i <= n; i++) {
    gamma[i] = a[i].p;
    omega[i] = a[i].p + a[i].c;
    trap[gamma[i]] = 0;
    trap[omega[i]] = 0;
  }
  int id = 0;
  for (auto &it : trap) {
    it.second = ++id;
  }
  for (int i = 1; i <= n; i++) {
    tg[i] = trap[gamma[i]];
    to[i] = trap[omega[i]];
    tg2[i] = id + 1 - tg[i];
    to2[i] = id + 1 - to[i];
  }
  dp[1] = 0;
  
  upd(aib1, to[1], dp[1] - omega[1]);
  upd(aib2, to2[1], dp[1]);
  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i], get(aib2, tg2[i]));
    dp[i] = min(dp[i], get(aib1, tg[i]) + gamma[i]);
    upd(aib1, to[i], dp[i] - omega[i]);
    upd(aib2, to2[i], dp[i]);
  }
  cout << ret + dp[n] << "\n";
  return 0;
}