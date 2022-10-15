#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


struct Interval {
  int l;
  int r;
};

const int N = (int) 2e5 + 7;
int n;
int m;
ll a[N];
Interval segs[N];
vector<int> inds[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
      inds[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      int foo;
      cin >> foo;
      a[i] = foo;
    }
    for (int i = 1; i <= n; i++) {
      int bar;
      cin >> bar;
      a[i] = a[i - 1] + a[i] - bar;
    }
    for (int i = 1; i <= m; i++) {
      cin >> segs[i].l >> segs[i].r;
      segs[i].l--;
      inds[segs[i].l].push_back(i);
      inds[segs[i].r].push_back(i);
    }
    queue<int> q0;
    set<int> rem;
    for (int i = 0; i <= n; i++) {
      if (a[i] == 0) {
        q0.push(i);
      } else {
        rem.insert(i);
      }
    }

    while (!q0.empty()) {
      int IX = q0.front();
      q0.pop();
      for (auto &i : inds[IX]) {
        int l = segs[i].l, r = segs[i].r;
        if (a[l] == 0 && a[r] == 0) {
          while (1) {
            auto it = rem.lower_bound(l);
            if (it == rem.end() || *it > r) break;
            assert(it != rem.end());
            assert(l <= *it && *it <= r);
            a[*it] = 0;
            q0.push(*it);
            rem.erase(it);
          }
        }
      }
    }

    cout << ((rem.empty()) ? "YES" : "NO") << "\n";
  }

}