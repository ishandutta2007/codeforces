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

const int A = 2e4 + 10;

int main() {
  fast_cin();
  int t; cin >> t;
  vector<int> is_prime(A, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p < A; ++p) {
    if (is_prime[p]) {
      for (int i = 2 * p; i < A; i += p) {
        is_prime[i] = false;
      }
    }
  }
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    int sum = 0, del = -1;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
    }
    if (is_prime[sum]) {
      for (int i = 0; i < n; ++i) {
        if (!is_prime[sum - a[i]]) {
          del = i;
          break;
        }
      }
    }
    cout << n - (del != -1) << '\n';
    for (int i = 0; i < n; ++i) {
      if (i != del) {
        cout << (i + 1) << ' ';
      }
    }
    cout << '\n';
  }
}