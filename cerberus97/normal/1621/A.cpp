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
    int n, k;
    cin >> n >> k;
    vector<string> a(n, string(n, '.'));
    for (int i = 0; i < n and k > 0; i += 2) {
      a[i][i] = 'R';
      --k;
    }
    if (k == 0) {
      for (auto& i : a) {
        cout << i << '\n';
      }
    } else {
      cout << -1 << '\n';
    }
  }
}