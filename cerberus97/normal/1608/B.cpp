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
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) > 1 or a + b > n - 2) {
      cout << -1 << '\n';
      continue;
    }
    if (a < b) {
      a += 2;
    } else if (a > b) {
      b += 2;
    } else {
      ++a; ++b;
    }
    vector<int> v1(b), v2(a);
    iota(v1.begin(), v1.end(), 1);
    iota(v2.begin(), v2.end(), b + 1);
    if (v2.size() > v1.size()) {
      swap(v1, v2);
    }
    int i = 0, j = 0;
    vector<int> ans;
    while (i < v1.size()) {
      ans.pb(v1[i++]);
      if (j < v2.size()) {
        ans.pb(v2[j++]);
      }
    }
    for (auto& i : ans) {
      cout << i << ' ';
      if (i == a + b) {
        for (int j = a + b + 1; j <= n; ++j) {
          cout << j << ' ';
        }
      }
    }
    cout << '\n';
  }
}