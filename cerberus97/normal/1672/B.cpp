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
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.length();
    bool ok = (s[0] == 'A' and s[n - 1] == 'B');
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 'B') {
        ++cur;
      } else {
        cur = max(cur - 1, 0);
      }
    }
    ok &= (cur == 0);
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}