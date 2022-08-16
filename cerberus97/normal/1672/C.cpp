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

int solve(vector<int> groups);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    vector<int> groups;
    groups.pb(1);
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) {
        ++groups.back();
      } else {
        groups.pb(1);
      }
    }
    cout << solve(groups) << '\n';
  }
}

int solve(vector<int> groups) {
  int n = groups.size();
  int l = 0, r = n - 1;
  while (l < n and groups[l] == 1) {
    ++l;
  }
  while (r >= 0 and groups[r] == 1) {
    --r;
  }
  if (l > r) {
    return 0;
  } else if (l == r) {
    if (groups[l] >= 4) {
      return groups[l] - 3;
    } else {
      return groups[l] - 2;
    }
  } else {
    return accumulate(groups.begin() + l, groups.begin() + r + 1, 0) - 3;
  }
}