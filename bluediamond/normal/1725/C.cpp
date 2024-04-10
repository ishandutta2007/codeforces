#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}

const int N = (int) 3e6 + 7;
int fact[N];
int ifact[N];

int comb(int n, int k) {
  assert(0 <= k && k <= n && n < N);
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int main() {
#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif /// ONLINE_JUDGE
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif /// ONLINE_JUDGE

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

  if (0) { /// very well
    for (int i = 0; i < 10; i++) {
      cout << i << " : " << fact[i] << " " << ifact[i] << " vs " << mul(fact[i], ifact[i]) << "\n";
    }
    exit(0);
  }

  int n, cnt_colors;
  cin >> n >> cnt_colors;
  ll circle_perim = 0;
  vector<ll> dists(n);
  for (int i = 0; i < n; i++) {
    cin >> dists[i];
    dists[i] *= 2;
    circle_perim += dists[i];
  }
  assert(circle_perim % 2 == 0);
  ll half_circle_perim = circle_perim / 2;
  vector<ll> p(n);
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + dists[i - 1];
  }
  map<ll, int> who_has_this_p;
  for (int i = 0; i < n; i++) {
    who_has_this_p[p[i]] = i;
  }
  int pairs = 0, single = 0;
  for (int i = 0; i < n; i++) {
    ll search_for = (p[i] + half_circle_perim) % circle_perim;
    if (who_has_this_p.count(search_for)) {
      pairs++;
    } else {
      single++;
    }
  }
  assert(pairs % 2 == 0);
  pairs /= 2;
  assert(pairs * 2 + single == n);
  int print_ret = 0;
  for (int cnt_same = 0; cnt_same <= pairs && cnt_same <= cnt_colors; cnt_same++) {
    int ways = 1;
    mulup(ways, comb(cnt_colors, cnt_same));
    mulup(ways, comb(pairs, cnt_same));
    mulup(ways, fact[cnt_same]);
    int rem_cols = cnt_colors - cnt_same;
    mulup(ways, pw(mul(rem_cols, rem_cols - 1), pairs - cnt_same));
    mulup(ways, pw(rem_cols, single));
    ///cout << " : " << cnt_same << " ---> " << ways << "\n";
    addup(print_ret, ways);
  }
  cout << print_ret << "\n";
  return 0;
}