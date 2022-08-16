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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    if (k < n) {
      ll best = 0, sum = 0;
      for (int i = 0; i < k; ++i) {
        sum += a[i];
      }
      best = sum;
      for (int i = k; i < n; ++i) {
        sum += a[i] - a[i - k];
        best = max(best, sum);
      }
      cout << best + (k * (k - 1)) / 2 << '\n';
    } else {
      cout << accumulate(a.begin(), a.end(), 0ll) + n * (k - 1) - (n * (n - 1)) / 2 << '\n';
    }
  }
}