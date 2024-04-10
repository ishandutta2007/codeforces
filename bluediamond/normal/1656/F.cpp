#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 

bool home = true;

using namespace std;
typedef long long ll;

const int N = (int)2e5 + 7;
int n;
ll v[N];
ll pref[N];
ll suf[N];



signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tests;
  cin >> tests;
  while (tests--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int foo;
      cin >> foo;
      v[i] = foo;
    }
    sort(v + 1, v + n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + v[i];
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      suf[i] = suf[i + 1] + v[i];
    }
    // tinede la infinit cand t merge la infinit?
    if (v[1] * (n - 1) + suf[2] > 0) {
      cout << "INF\n";
      continue;
    }
    // tinde la infinit cand t merge la -infinit?
    if (v[n] * (n - 1) + pref[n - 1] < 0) {
      cout << "INF\n";
      continue;
    }
    ll best = max(-v[1] * (v[1] * (n - 1) + suf[2]) + (v[1] * suf[2]), -v[n] * (v[n] * (n - 1) + pref[n - 1]) + (v[n] * pref[n - 1]));

    for (int i = 1; i < n; i++) {
      ll low = -v[i + 1] + 1, high = -v[i];
      if (low <= high) {
        ll a = (pref[i] + i * v[n] + suf[i + 1] + v[1] * (n - i) - v[1] - v[n]);
        ll b = (pref[i] * v[n] + suf[i + 1] * v[1] - v[1] * v[n]);
        best = max(best, low * a + b);
        best = max(best, high * a + b);
        if (low <= 0 && high >= 0) {
          best = max(best, b);
        }
      }
    }

    cout << best << "\n";
  }

}