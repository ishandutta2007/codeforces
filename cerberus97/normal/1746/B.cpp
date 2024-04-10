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
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    int cnt0 = count(a.begin(), a.end(), 0);
    int ans = cnt0;
    int cur0 = 0, cur1 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        int rem0 = cnt0 - cur0;
        int rem1 = (n - i - 1) - rem0;
        ans = max(ans, 1 + cur0 + rem1 + min(rem0, cur1));
        ++cur1;
      } else {
        ++cur0;
      }
    }
    cout << n - ans << '\n';
  }
}