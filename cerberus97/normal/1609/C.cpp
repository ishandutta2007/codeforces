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

const int N = 1e6 + 10;

int main() {
  fast_cin();
  vector<bool> prime(N, true);
  prime[0] = prime[1] = false;
  for (int p = 2; p < N; ++p) {
    if (prime[p]) {
      for (int j = 2 * p; j < N; j += p) {
        prime[j] = false;
      }
    }
  }
  int t; cin >> t;
  while (t--) {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    vector<int> cnt1(2 * n, 0), cntp(2 * n, 0);
    ll sum = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == 1) {
        cnt1[i] = 1 + cnt1[i + e];
        cntp[i] = cntp[i + e];
        sum += cntp[i];
      } else if (prime[a[i]]) {
        cnt1[i] = 0;
        cntp[i] = 1 + cnt1[i + e];
        sum += cntp[i] - 1;
      } else {
        cnt1[i] = 0;
        cntp[i] = 0;
      }
    }
    cout << sum << '\n';
  }
}