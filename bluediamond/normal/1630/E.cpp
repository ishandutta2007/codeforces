#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = (ll) r * a % M;
    a = (ll) a * a % M;
    b /= 2;
  }
  return r;
}

int inv(int x) {
  return pw(x, M - 2);
}


struct T {
  int sum;
  int cnt;
  T() {
    sum = cnt = 0;
  }
};


const int N = (int)1e6 + 7;
int fact[N];
int ifact[N];
int pref[N];
int suf[N];

int solve(vector<int> v) {
  int n = (int)v.size();
  vector<int> frq(n, 0);
  for (auto& x : v) {
    x--;
    frq[x]++;
  }
  int gcdfrq = 0;
  for (auto& f : frq) {
    gcdfrq = __gcd(gcdfrq, f);
  }
  if (gcdfrq == n) {
    return 1;
  }

  sort(frq.rbegin(), frq.rend());

  while (!frq.empty() && frq.back() == 0) {
    frq.pop_back();
  }

  assert(!frq.empty());

  vector<int> initfrq = frq;


  function<T(int)> compute = [&](int len) {
    n = (int) frq.size();
    frq = initfrq;
    int cnt = (int) v.size() / len;
    for (auto& f : frq) {
      f /= cnt;
    }
    T sol;
    sol.cnt = fact[len];

    for (auto& x : frq) {
      sol.cnt = (ll) sol.cnt * ifact[x] % M;
    }

    pref[0] = ifact[frq[0]];
    for (int i = 1; i < n; i++) pref[i] = (ll) pref[i - 1] * ifact[frq[i]] % M;

    suf[n - 1] = ifact[frq[n - 1]];
    for (int i = n - 2; i >= 0; i--) suf[i] = (ll) suf[i + 1] * ifact[frq[i]] % M;

    for (int i = 0; i < n; i++) {
      if (frq[i] >= 2) {
        int current = fact[len - 2];
        frq[i] -= 2;
        if (i > 0) {
          current = (ll) current * pref[i - 1] % M;
        }
        if (i < n - 1) {
          current = (ll) current * suf[i + 1] % M;
        }
        current = (ll) current * ifact[frq[i]] % M * (int) v.size() % M;
        sol.sum += current;
        if (sol.sum >= M) sol.sum -= M;
        frq[i] += 2;
      }
    }
    n = (int)v.size();
    return sol;
  };
  vector<T> sol(n + 1);
  for (int cnt = 1; cnt <= gcdfrq; cnt++) {
    if (gcdfrq % cnt == 0) {
      int len = n / cnt;
      assert(n % len == 0);
      sol[len] = compute(len);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (sol[i].cnt == 0 && sol[i].sum == 0) {
      continue;
    }
    for (int j = 2 * i; j <= n; j += i) {
      sol[j].sum -= sol[i].sum;
      sol[j].cnt -= sol[i].cnt;
      if (sol[j].sum < 0) sol[j].sum += M;
      if (sol[j].cnt < 0) sol[j].cnt += M;
    }
  }
  T ret;
  for (int cnt = 1; cnt <= gcdfrq; cnt++) {
    if (gcdfrq % cnt == 0) {
      int len = n / cnt;
      sol[len].sum = (ll) sol[len].sum * inv(len) %  M;
      sol[len].cnt = (ll) sol[len].cnt * inv(len) %  M;
      ret.sum += sol[len].sum;
      ret.cnt += sol[len].cnt;
      if (ret.sum >= M) ret.sum -= M;
      if (ret.cnt >= M) ret.cnt -= M;
    }
  }
  ret.sum = (ll) ret.sum * inv(ret.cnt) % M;
  n -= ret.sum;
  if (n < 0) n += M;
  return n;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
///  freopen ("iron_man.txt", "r", stdin);
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = (ll) fact[i - 1] * i % M;
  ifact[N - 1] = inv(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = (ll) ifact[i + 1] * (i + 1) % M;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    cout << solve(a) << "\n";
  }

}