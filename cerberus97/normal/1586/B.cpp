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
    int n, m;
    cin >> n >> m;
    vector<int> bad(n + 1, 0);
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      bad[b] = true;
    }
    int root = 1;
    while (bad[root]) {
      ++root;
    }
    for (int i = 1; i <= n; ++i) {
      if (i != root) {
        cout << root << ' ' << i << '\n';
      }
    }
  }
}