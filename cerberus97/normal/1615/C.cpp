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

int main() {
  fast_cin();
  int tc; cin >> tc;
  while (tc--) {
    int n; string s, t;
    cin >> n >> s >> t;
    int ans = n + 1;
    if (count(s.begin(), s.end(), '0') == count(t.begin(), t.end(), '0')) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        cnt += (s[i] != t[i]);
      }
      ans = min(ans, cnt);
    }
    for (auto& i : s) {
      i ^= '0' ^ '1';
    }
    if (count(s.begin(), s.end(), '0') != 0 and count(s.begin(), s.end(), '0') == count(t.begin(), t.end(), '0') + 1) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        cnt += (s[i] != t[i]);
      }
      ans = min(ans, cnt);
    }
    if (ans == n + 1) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}