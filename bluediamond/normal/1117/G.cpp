#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

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

const int N = (int) 1e6 + 7;
int n, q, a[N], lft[N], bong[N];
ll ret[N];
ll aib[2][N];

void clr() {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= n; j++) {
      aib[i][j] = 0;
    }
  }
}

void add(int t, int i, int x) {
  while (i <= n) {
    aib[t][i] += x;
    i += i & (-i);
  }
}

ll get(int t, int i) {
  ll ret = 0;
  while (i) {
    ret += aib[t][i];
    i -= i & (-i);
  }
  return ret;
}

struct T {
  int l, r, i;
} b[N];

bool cmp(T a, T b) {
  return a.l > b.l;
}

ll gauss(ll x) {
  return x * (x + 1) / 2;
}

ll gauss(ll l, ll r) {
  return gauss(r) - gauss(l - 1);
}

void baga() {
  clr();
  vector<int> stk;
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();
    lft[i] = stk.empty() ? 1 : (stk.back() + 1);
    stk.push_back(i);
  }
  sort(b + 1, b + q + 1, cmp);
  vector<pair<int, int>> so;
  for (int i = 1; i <= n; i++) {
    so.push_back({lft[i], i});
  }
  sort(so.rbegin(), so.rend());
  int p = 0;
  for (int i = 1; i <= q; i++) {
    while (p < n && so[p].first >= b[i].l) {
      add(0, so[p].second, 1);
      add(1, so[p].second, so[p].first);
      p++;
    }
    ll sum = 0;
    int cnt = 0;
    /**for (int j = b[i].l; j <= b[i].r; j++) {
      if (lft[j] >= b[i].l) {
        sum += lft[j];
        cnt++;
      }
    }
    assert(cnt == get(0, b[i].r) - get(0, b[i].l - 1));
    assert(sum == get(1, b[i].r) - get(1, b[i].l - 1));**/
    cnt = get(0, b[i].r) - get(0, b[i].l - 1);
    sum = get(1, b[i].r) - get(1, b[i].l - 1);
    cnt = b[i].r - b[i].l + 1 - cnt;
    sum += (ll) b[i].l * cnt;
    ret[b[i].i] += gauss(b[i].l + 1, b[i].r + 1);
    ret[b[i].i] -= sum;
  }
}

signed realMain() {

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> bong[i];
  }
  for (int i = 1; i <= q; i++) {
    int r;
    cin >> r;
    ret[i] -= (r - bong[i] + 1);
    b[i] = {bong[i], r, i};
  }
  baga();
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= q; i++) {
    swap(b[i].l, b[i].r);
    b[i].l = n + 1 - b[i].l;
    b[i].r = n + 1 - b[i].r;
  }
  baga();
  for (int i = 1; i <= q; i++) {
    cout << ret[i] << " ";
  }
  cout << "\n";
  return 0;
}