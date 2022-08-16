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
    int n; cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    vector<vector<bool>> ok(2, vector<bool>(n, false));
    ok[0][0] = (a[0][0] == '0');
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (a[j][i] == '0') {
          ok[j][i] = (ok[j][i - 1] or ok[1 - j][i - 1]);
        }
      }
    }
    if (ok[1][n - 1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}