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
  int n; cin >> n;
  string s; cin >> s;
  vector<int> rank(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    rank[i] = (s[i] - 'a');
  }
  vector<int> ids(1 << n);
  iota(ids.begin(), ids.end(), 0);
  for (int b = 0; b < n; ++b) {
    sort(ids.begin(), ids.end(), [&](int i, int j) {
      return tie(rank[i], rank[i ^ (1 << b)]) < tie(rank[j], rank[j ^ (1 << b)]);
    });
    auto bak = rank;
    rank[ids[0]] = 0;
    for (int i = 1; i < (1 << n); ++i) {
      rank[ids[i]] = rank[ids[i - 1]];
      if (tie(bak[ids[i - 1]], bak[ids[i - 1] ^ (1 << b)]) < tie(bak[ids[i]], bak[ids[i] ^ (1 << b)])) {
        ++rank[ids[i]];
      }
    }
  }
  string t((1 << n), 'a');
  for (int i = 0; i < (1 << n); ++i) {
    t[i] = s[i ^ ids[0]];
  }
  cout << t << '\n';
}