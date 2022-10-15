#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, wanted_len, a[N], sa[N];

int get_sum(int l, int r) {
  if (l > r) {
    return 0;
  }
  assert(1 <= l && l <= r && r <= n);
  return sa[r] - sa[l - 1];
}

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
    cin >> n >> wanted_len;
    {
      string s;
      cin >> s;
      assert((int) s.size() == n);
      for (int i = 1; i <= n; i++) {
        char ch = s[i - 1];
        assert(ch == '0' || ch == '1');
        a[i] = ch - '0';
        assert(a[i] == 0 || a[i] == 1);
      }
    }
    /**
    cuteness(seq) = cz / len

    cuteness(s) = tc0 / n
    cuteness(seq) = c0 / m

    =>

    c0 / m = tc0 / n
    c0 = m * tc0 / n => a natural number

    **/

    int tc0 = 0, tc1;
    for (int i = 1; i <= n; i++) {
      tc0 += (a[i] == 0);
      sa[i] = sa[i - 1] + a[i];
    }
    tc1 = n - tc0;

    if ((wanted_len * (ll) tc0) % n != 0) {
      cout << "-1\n";
      continue;
    }

    int c0seq = (wanted_len * (ll) tc0) / n;
    int c1seq = wanted_len - c0seq;

    assert(0 <= c0seq && c0seq <= wanted_len);
    assert(0 <= c1seq && c1seq <= wanted_len);
    assert(c0seq + c1seq == wanted_len);

    assert(tc0 >= c0seq);
    assert(tc1 >= c1seq);

    bool finitos = 0;

    for (int i = 1; i + wanted_len - 1 <= n; i++) {
      if (get_sum(i, i + wanted_len - 1) == c1seq) {
        finitos = 1;
        cout << "1\n";
        cout << i << " " << i + wanted_len - 1 << "\n";
        break;
      }
    }
    if (finitos) {
      continue;
    }
    for (int pref = 1; pref < wanted_len; pref++) {
      int suf = wanted_len - pref;
      if (get_sum(1, pref) + get_sum(n - suf + 1, n) == c1seq) {
        finitos = 1;
        cout << "2\n";
        cout << 1 << " " << pref << "\n";
        cout << n - suf + 1 << " " << n << "\n";
        break;
      }
    }
    assert(finitos);
  }

  return 0;
}