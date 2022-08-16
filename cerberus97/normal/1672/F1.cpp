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
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    map<int, int> cnt;
    vector<vector<int>> groups;
    for (int i = 0; i < n; ++i) {
      if (int(groups.size()) < cnt[a[i]] + 1) {
        groups.pb({});
      }
      groups[cnt[a[i]]].pb(i);
      ++cnt[a[i]];
    }
    vector<int> tmp;
    for (auto& g : groups) {
      sort(g.begin(), g.end(), [&](int i, int j) {
        return a[i] < a[j];
      });
      for (auto& i : g) {
        tmp.pb(i);
      }
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      b[tmp[i]] = a[tmp[(i + 1) % n]];
    }
    for (auto& i : b) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}