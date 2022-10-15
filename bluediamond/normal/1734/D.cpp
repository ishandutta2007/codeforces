#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  ll sum;
  ll mn;
};

T add(T a, ll x) {
  return {a.sum + x, min(a.mn, a.sum + x)};
}

bool is_good(vector<T> pref, vector<T> suf, ll x) {
  reverse(pref.begin(), pref.end());
  reverse(suf.begin(), suf.end());


  while (!pref.empty()) {
    if (x + pref.back().mn >= 0) {
      x += pref.back().sum;
      pref.pop_back();
      continue;
    }
    if (!suf.empty() && x + suf.back().mn >= 0) {
      x += suf.back().sum;
      suf.pop_back();
      continue;
    }
    return 0;
  }
  return 1;
}

const int N = 200000 + 7;
int n;
int k;
ll a[N];


int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ///ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    assert(1 <= k && k <= n);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<T> suf, pref;
    for (int i = k + 1; i <= n; i++) {
      if (suf.empty()) {
        suf.push_back({a[i], a[i]});
        continue;
      }
      if (suf.back().sum < 0) {
        suf.back() = add(suf.back(), a[i]);
        continue;
      }
      suf.push_back({a[i], a[i]});
    }
    for (int i = k - 1; i >= 1; i--) {
      if (pref.empty()) {
        pref.push_back({a[i], a[i]});
        continue;
      }
      if (pref.back().sum < 0) {
        pref.back() = add(pref.back(), a[i]);
        continue;
      }
      pref.push_back({a[i], a[i]});
    }
    cout << ((is_good(pref, suf, a[k]) || is_good(suf, pref, a[k])) ? ("YES") : ("NO")) << "\n";
  }

  return 0;
}