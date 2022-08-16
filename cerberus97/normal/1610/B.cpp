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

bool solve(vector<int>& a, int l, int r);
bool check(vector<int>& a, int val);

int main() {
  fast_cin();
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    if (solve(a, 0, n - 1)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

bool solve(vector<int>& a, int l, int r) {
  if (r - l + 1 <= 1) {
    return true;
  } else if (a[l] == a[r]) {
    return solve(a, l + 1, r - 1);
  } else {
    return check(a, a[l]) or check(a, a[r]);
  }
}

bool check(vector<int>& a, int val) {
  vector<int> b;
  for (auto& i : a) {
    if (i != val) {
      b.pb(i);
    }
  }
  int sz = b.size();
  for (int i = 0, j = sz - 1; i < j; ++i, --j) {
    if (b[i] != b[j]) {
      return false;
    }
  }
  return true;
}