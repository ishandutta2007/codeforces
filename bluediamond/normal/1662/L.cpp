#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;

#define int long long

void normalize(ll a[], int n) {

  vector<ll> S;
  for (int i = 0; i <= n; i++) {
    S.push_back(a[i]);
  }
  sort(S.begin(), S.end());

  S.resize(unique(S.begin(), S.end()) - S.begin());

  for (int i = 0; i <= n; i++) {
    a[i] = lower_bound(S.begin(), S.end(), a[i]) - S.begin() + 1;
  }
}


const int N = (int) 2e5 + 7;
const int INF = (int) 1e9 + 7;
int n;
ll maximum_speed;
ll t[N];
ll x[N];
int dp[N];
vector<int> values[N], aib[N];

void update(int X, int T, int value) {
  for (int i = X; i <= n + 1; i += i & (-i)) {
    int from = lower_bound(values[i].begin(), values[i].end(), T) - values[i].begin() + 1;
    assert(1 <= from && from <= (int) values[i].size());
    assert(values[i][from - 1] == T);
    for (int j = from; j <= (int) values[i].size(); j += j & (-j)) {
      aib[i][j] = max(aib[i][j], value);
    }
  }
}

int get(int X, int T) {
  int sol = -INF;
  for (int i = X; i >= 1; i -= i & (-i)) {
    int low = 0, high = (int) values[i].size() - 1, cnt_smaller = 0;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (values[i][mid] <= T) {
        cnt_smaller = mid + 1;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    int from = cnt_smaller;

    for (int j = from; j; j -= j & (-j)) {
      assert(0 <= j);
      assert(j <= (int) values[i].size());
      assert((int) aib[i].size() == (int) values[i].size() + 1);
      assert(j < (int) aib[i].size());
      sol = max(sol, aib[i][j]);
    }
  }
  return sol;
}

int deg[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n >> maximum_speed;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    t[i] *= maximum_speed;
  }


  for (int i = 1; i <= n; i++) cin >> x[i];

  for (int i = 1; i <= n; i++) {
    int S = t[i] + x[i];
    int D = t[i] - x[i];
    t[i] = S;
    x[i] = D;
  }

  t[0] = 0;
  x[0] = 0;
  dp[0] = 0;


  normalize(t, n);
  normalize(x, n);

  for (int i = 1; i <= n; i++) {
    assert(1 <= x[i] && x[i] <= n + 1);
    assert(1 <= t[i] && t[i] <= n + 1);
  }

  for (int i = 1; i <= n; i++) dp[i] = -INF;

  vector<int> indsByT(n + 1);
  iota(indsByT.begin(), indsByT.end(), 0);
  sort(indsByT.begin(), indsByT.end(), [&] (int i, int j) {return t[i] < t[j];});


  for (auto &i : indsByT) {
    int X = x[i], T = t[i];
    while (X <= n + 1) {
      deg[X]++;
      X += X & (-X);
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    values[i].reserve(deg[i]);
  }
  for (auto &i : indsByT) {
    int X = x[i], T = t[i];
    while (X <= n + 1) {

      if (values[X].empty() || values[X].back() != T) {
        values[X].push_back(T);
      }
      X += X & (-X);
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    aib[i].resize((int) values[i].size() + 1, -INF);
    for (int j = 1; j < (int) values[i].size(); j++) {
      assert(values[i][j - 1] < values[i][j]);
    }
  }

  update(x[0], t[0], dp[0]);


  for (int i = 1; i <= n; i++) {
    dp[i] = get(x[i], t[i]) + 1;
    update(x[i], t[i], dp[i]);
  }
  cout << *max_element(dp, dp + n + 1) << "\n";
}