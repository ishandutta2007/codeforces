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
    vector<vector<int>> days(n, vector<int>(5));
    for (auto& i : days) {
      for (auto& j : i) {
        cin >> j;
      }
    }
    bool ok = false;
    for (int d1 = 0; d1 < 5; ++d1) {
      for (int d2 = 0; d2 < d1; ++d2) {
        int c1 = 0, c2 = 0, c12 = 0;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
          if (days[i][d1] and days[i][d2]) {
            ++c12;
          } else if (days[i][d1]) {
            ++c1;
          } else if (days[i][d2]) {
            ++c2;
          } else {
            valid = false;
          }
        }
        if (valid and max(c1, c2) <= n / 2) {
          ok = true;
        } 
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}