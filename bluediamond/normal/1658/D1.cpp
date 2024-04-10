#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int l, r;
    cin >> l >> r;
    assert(l == 0);
    vector<int> a(r - l + 1);
    vector<int> have_a(17, 0), have_not_a(17, 0);
    vector<int> have_i(17, 0), have_not_i(17, 0);
    for (int i = l; i <= r; i++) {
      cin >> a[i - l];
      for (int bit = 0; bit < 17; bit++) {
        if (a[i - l] & (1 << bit)) {
          have_a[bit]++;
        } else {
          have_not_a[bit]++;
        }
        if (i & (1 << bit)) {
          have_i[bit]++;
        } else {
          have_not_i[bit]++;
        }
      }
    }
    int sol = 0;
    for (int bit = 0; bit < 17; bit++) {
      if (have_a[bit] != have_i[bit]) {
        assert(have_a[bit] == have_not_i[bit]);
        assert(have_i[bit] == have_not_a[bit]);
        sol ^= (1 << bit);
        for (int i = l; i <= r; i++) {
          a[i - l] ^= (1 << bit);
        }
        swap(have_a[bit], have_not_a[bit]);
      }
      assert(have_a[bit] == have_i[bit]);
      assert(have_not_a[bit] == have_not_i[bit]);
    }
    cout << sol << "\n";
  }


  return 0;
}