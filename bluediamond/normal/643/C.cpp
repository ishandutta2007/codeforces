#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
bool home = 1;

ld eval(vector<int> a) {
  ld sol = 0, total = 0;
  for (auto &x : a) {
    total += x;
    sol += total / x;
  }
  return sol;
}

const int N = (int) 2e5 + 7;
const ld INF = (ld) 1e18;

int n;
int k;
int t[N];
ld dp[N];
ld ndp[N];
ld sum[N];
ld dv[N];
ld inv[N];
ld coef[N];
ld add[N];

struct T {
  ld a;
  ld b;
};

T operator - (T f, T s) {
  return {f.a - s.a, f.b - s.b};
}

ld eval(T f, ld x) {
  return f.a * x + f.b;
}

ld cross(T f, T s) {
  return f.a * s.b - f.b * s.a;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    sum[i] = sum[i - 1] + t[i];
    dv[i] = dv[i - 1] + sum[i] / t[i];
    inv[i] = inv[i - 1] + (ld) 1 / t[i];
    dp[i] = INF;
    coef[i] = -sum[i - 1];
  }

  for (int iter = 1; iter <= k; iter++) {
    int l = 0;

    vector<T> stk;
    for (int r = 1; r <= n; r++) {
      add[r] = dp[r - 1] - dv[r - 1] + sum[r - 1] * inv[r - 1];
      ndp[r] = INF;

      T cur = {coef[r], add[r]};
      while ((int) stk.size() >= 2 && cross(stk[(int) stk.size() - 2] - stk[(int) stk.size() - 1], cur - stk[(int) stk.size() - 1]) < 0) {
        stk.pop_back();
      }
      stk.push_back(cur);


      while (l + 1 < (int) stk.size() && eval(stk[l + 1], inv[r]) < eval(stk[l], inv[r])) l++;
      ndp[r] = eval(stk[l], inv[r]);
      ld bef = ndp[r];
      ndp[r] += dv[r];
    }
    for (int i = 1; i <= n; i++) {
      dp[i] = ndp[i];
    }
  }

  cout << fixed << setprecision(6) << dp[n] << "\n";


  return 0;
}
/**



**/