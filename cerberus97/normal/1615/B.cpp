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

const int N = 2e5 + 10, B = 20;

int main() {
  fast_cin();
  vector<vector<int>> cnt(N, vector<int>(B, 0));
  for (int i = 1; i < N; ++i) {
    for (int b = 0; b < B; ++b) {
      cnt[i][b] = cnt[i - 1][b] + ((i >> b) & 1);
    }
  }
  int t; cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int b = 0; b < B; ++b) {
      ans = max(ans, cnt[r][b] - cnt[l - 1][b]);
    }
    cout << (r - l + 1) - ans << '\n';
  }
}