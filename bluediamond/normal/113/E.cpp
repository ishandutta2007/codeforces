#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get_dim(int x) {
  if (x <= 9) return 1;
  return 1 + get_dim(x / 10);
}

int get_cnt_different(int x, int y, int dim) {
  int sol = 0;
  for (int i = 0; i < dim; i++) {
    sol += (x % 10 != y % 10);
    x /= 10;
    y /= 10;
  }
  return sol;
}

int h, m;
int dim_h, dim_m;
int k;

ll compute_dumb(int hx, int mx) {
  pair<int, int> last;
  ll sol = 0;

  for (int i = 0; i <= hx; i++) {
    int stop = ((i == hx) ? mx : (m - 1));
    for (int j = 0; j <= stop; j++) {
      if (i == 0 && j == 0) continue;
      bool is_good = (get_cnt_different(last.first, i, dim_h) + get_cnt_different(last.second, j, dim_m) >= k);
      sol += is_good;
      last = make_pair(i, j);
    }
  }

  return sol;
}

int compute(int lim, int dim, int k) {
  ll p10 = 1;
  for (int it = 1; it < k; it++) {
    p10 *= 10;
  }
  return lim / p10;
}

ll compute_smart(int hx, int mx) {
  int fx_dif = get_cnt_different(m - 1, 0, dim_m);
  int sum_full_m = compute(m - 1, dim_m, k);
  ll sol = compute(hx, dim_h, k - fx_dif) + compute(mx, dim_m, k);
  sol += hx * (ll) sum_full_m;
  return sol;
}

int h1, m1;
int h2, m2;

mt19937 rng(0);

int getrng(int l, int r) {
  assert(l <= r);
  int x = rng() % (r - l + 1);
  x += l;
  assert(l <= x && x <= r);
  return x;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  for (int tc = 1; 0; tc++) {
    h = getrng(1, 100), m = getrng(1, 100), k = getrng(1, 6);
    h1 = getrng(0, h - 1), m1 = getrng(0, m - 1);
    dim_h = get_dim(h - 1);
    dim_m = get_dim(m - 1);

    if (tc % 10000 == 0) {
      cout << "done " << tc << "\n";
    }

    assert(compute_dumb(h1, m1) == compute_smart(h1, m1));
  }
#endif // ONLINE_JUDGE

  cin >> h >> m >> k;
  dim_h = get_dim(h - 1);
  dim_m = get_dim(m - 1);
  cin >> h1 >> m1 >> h2 >> m2;

  if (make_pair(h1, m1) <= make_pair(h2, m2)) {
    cout << compute_smart(h2, m2) - compute_smart(h1, m1) << "\n";
  } else {
    cout << (compute_smart(h - 1, m - 1) - compute_smart(h1, m1)) + compute_smart(h2, m2) + (get_cnt_different(m - 1, 0, dim_m) + get_cnt_different(h - 1, 0, dim_h) >= k) << "\n";
  }


}