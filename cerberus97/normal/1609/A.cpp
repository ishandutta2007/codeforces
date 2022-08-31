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
    vector<ll> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    int cnt = 0;
    ll sum = 0, mx = 0;
    for (auto& i : a) {
      while (i % 2 == 0) {
        i /= 2;
        ++cnt;
      }
      sum += i;
      mx = max(mx, i);
    }
    sum -= mx;
    while (cnt--) {
      mx *= 2;
    }
    sum += mx;
    cout << sum << '\n';
  }
}