#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
int m;
ll a[N];
ll ps[N];
ll ks[N];
int print[N];

ll compute_change(int st, int dr) {
  return (ps[dr] - ps[st - 1] - 1) / (dr - st + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE

  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = ps[i - 1] + a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> ks[i];
  }
  set<pair<int, int>> segs;
  set<pair<ll, pair<int, int>>> when_change;
  for (int i = 1; i <= n; i++) {
    segs.insert({i, i});
    if (i < n) {
      when_change.insert({compute_change(i, i), {i, i}});
    }
  }
  int sol = 0;
  for (int i = m; i >= 1; i--) {
    ll k = ks[i];
    while (!when_change.empty()) {
      pair<int, int> seg;
      {
        auto itr = when_change.end();
        itr--;
        auto it = *itr;
        if (it.first < k) {
          break;
        }
        seg = it.second;
        when_change.erase(it);
      }
      auto it = segs.find(seg);
      auto nxt = it;
      nxt++;
      pair<ll, pair<int, int>> kek = {compute_change(nxt->first, nxt->second), {*nxt}};
      bool F = when_change.count(kek);
      sol = max(sol, nxt->second - it->first);
      segs.insert({it->first, nxt->second});
      if (F) {
        when_change.erase(kek);
        kek = {compute_change(it->first, nxt->second), {it->first, nxt->second}};
        when_change.insert(kek);
      }
      segs.erase(it);
      segs.erase(nxt);
    }
    print[i] = sol;
  }
  for (int i = 1; i <= m; i++) {
    cout << print[i] << " ";
  }
  cout << "\n";
  return 0;
}
/**

**/