/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

bool solve(vector<int> a, vector<pii> ivl);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (auto& i : a) {
      cin >> i;
    }
    for (auto& i : b) {
      cin >> i;
    }
    vector<pii> ivl(m);
    for (auto& [l, r] : ivl) {
      cin >> l >> r;
    }
    vector<int> c(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      c[i] = (b[i] - a[i]);
    }
    if (solve(c, ivl)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

bool solve(vector<int> a, vector<pii> ivl) {
  if (accumulate(a.begin(), a.end(), 0ll) != 0) {
    return false;
  }
  int n = a.size();
  vector<int> pref(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i - 1];
  }
  set<int> remaining;
  for (int i = 0; i <= n; ++i) {
    remaining.insert(i);
  }
  queue<int> q;
  for (int i = 0; i <= n; ++i) {
    if (pref[i] == 0) {
      q.push(i);
      remaining.erase(i);
    }
  }
  vector<vector<pii>> at(n + 1);
  for (auto& [l, r] : ivl) {
    at[l - 1].pb({l - 1, r});
    at[r].pb({l - 1, r});
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto& [l, r] : at[u]) {
      if (pref[l] == 0 and pref[r] == 0) {
        while (true) {
          auto it = remaining.lower_bound(l);
          if (it != remaining.end() and *it <= r) {
            pref[*it] = 0;
            q.push(*it);
            remaining.erase(it);
          } else {
            break;
          }
        }
      }
    }
  }
  return remaining.empty();
}