#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

const int N = (int) 3e5 + 7;
int n, q, k, a[N], mn[N];
vector<pair<int, int>> qs[N];
ll sol[N], br[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  cin >> n >> q >> k;
  deque<int> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    while (!d.empty() && a[i] < a[d.back()]) {
      d.pop_back();
    }
    d.push_back(i);
    if (i - d.front() > k) {
      d.pop_front();
    }
    assert(!d.empty());
    mn[i] = a[d.front()];
  }

  for (int iq = 1; iq <= q; iq++) {
    int l, r;
    cin >> l >> r;
    qs[l].push_back({r, iq});
  }

  for (int re = 0; re < k; re++) {
    vector<int> ls, kek;
    for (int c = 0; c * k + re <= n; c++) {
      ls.push_back(c * k + re);
      kek.push_back(mn[ls[c]]);
    }
    vector<int> stk;
    vector<ll> pref;
    stk.push_back((int) ls.size());
    pref.push_back(0);
    for (int i = (int) ls.size() - 1; i >= 0; i--) {
      int l = ls[i];
      for (auto &it : qs[l]) {
        int r = it.first, ind = it.second;
        sol[ind] = a[l];
        int lo = i + 1, hi = i + (r - l) / k;
        int total = 0, firstall = (int) stk.size();
        int fefe = (int) stk.size();
        int low = 1, high = (int) stk.size() - 1;
        while (low <= high) {
          int j = (low + high) / 2;
          int ff = stk[j];
          int ss = stk[j - 1] - 1;
          if (ss <= hi) {
            firstall = j;
            high = j - 1;
          } else {
            low = j + 1;
          }
        }
        sol[ind] += pref[(int) stk.size() - 1] - pref[firstall - 1];
        if (firstall - 1 >= 1) {
          int ff = stk[firstall - 1];
          int ss = stk[firstall - 2] - 1;
          if (ff <= min(hi, ss)) {
            sol[ind] += (ll) kek[ff] * (min(hi, ss) - ff + 1);
          }
        }

      }
      while ((int) stk.size() > 1 && kek[stk.back()] > kek[i]) stk.pop_back(), pref.pop_back();
      pref.push_back(pref.back() + (ll) kek[i] * (stk.back() - i));
      stk.push_back(i);
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << sol[i] << "\n";
  }

  return 0;
}