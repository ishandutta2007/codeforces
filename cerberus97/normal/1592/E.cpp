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

const int N = 1e6 + 10, A = 1e6 + 10, B = 20;

int main() {
  fast_cin();
  int n; cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  int ans = 0;
  for (int b = B - 1; b >= 0; --b) {
    int suff_xor = 0, nzero = n;
    vector<int> where(1 << B, n + 1);
    where[suff_xor] = n;
    for (int i = n - 1; i >= 0; --i) {
      suff_xor ^= (a[i] >> b);
      if ((a[i] >> b) & 1) {
        if (where[suff_xor] <= nzero) {
          ans = max(ans, where[suff_xor] - i);
        } else {
          where[suff_xor] = i;
        }
      } else {
        nzero = i;
        where[suff_xor] = i;
      }
    }
  }
  cout << ans << '\n';
}