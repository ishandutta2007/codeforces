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

const int N = 1e5 + 10, SQ = sqrt(N);

int cnt[(SQ + 2) * N + 10];

int solve(vector<int>& a);

int main() {
  fast_cin();
  int n; cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  int ans = solve(a);
  reverse(a.begin(), a.end());
  ans = min(ans, solve(a));
  cout << ans << '\n';
}

int solve(vector<int>& a) {
  int n = a.size(), ans = n - 1;
  for (int d = 0; d <= SQ; ++d) {
    int offset = N * (SQ + 1);
    for (int i = 0; i < n; ++i) {
      int base = a[i] - i * d;
      ++cnt[base + offset];
      ans = min(ans, n - cnt[base + offset]);
    }
    for (int i = 0; i < n; ++i) {
      int base = a[i] - i * d;
      --cnt[base + offset];
    }
  }
  for (int i = 0; i < n; ++i) {
    int offset = 2 * N;
    for (int j = i + 1; j <= i + SQ and j < n; ++j) {
      if ((a[j] - a[i]) % (j - i) != 0) {
        continue;
      }
      int d = (a[j] - a[i]) / (j - i);
      ++cnt[d + offset];
      ans = min(ans, n - 1 - cnt[d + offset]);
    }
    for (int j = i + 1; j <= i + SQ and j < n; ++j) {
      if ((a[j] - a[i]) % (j - i) != 0) {
        continue;
      }
      int d = (a[j] - a[i]) / (j - i);
      --cnt[d + offset];
    }
  }
  return ans;
}