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
    vector<int> a(n), pos(n + 1);
    for (auto& i : a) {
      cin >> i;
    }
    for (int i = 0; i < n; ++i) {
      pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      cout << min(pos[i] + 2, n) << ' ';
    }
    cout << '\n';
  }
}