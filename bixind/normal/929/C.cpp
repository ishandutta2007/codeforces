#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 998244353;

ll C[1010][1010];

void solve() {
  C[0][0] = 1;
  for (int i = 0; i < 1010; ++i)
    C[i][0] = C[i][i] = 1;
  for (int i = 1; i < 1010; ++i) {
    for (int j = 1; j < 1010; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  int g, d, f;
  cin >> g >> d >> f;
  vector<pair<int, int> > v;
  for (int i = 0; i < g; ++i) {
    int a;
    cin >> a;
    v.push_back({a, 0});
  }
  for (int i = 0; i < d; ++i) {
    int a;
    cin >> a;
    v.push_back({a, 1});
  }
  for (int i = 0; i < f; ++i) {
    int a;
    cin >> a;
    v.push_back({a, 2});
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  int j = 0;
  int cnt[3];
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (int i = 0; i < v.size(); ++i) {
    while (j < v.size() && v[i].first * 2 >= v[j].first) {
      ++cnt[v[j].second];
      ++j;
    }
    int need[3];
    need[0] = 1;
    need[1] = 2;
    need[2] = 3;
    --need[v[i].second];
    --cnt[v[i].second];
    ll res = 1;
    res *= C[cnt[0]][need[0]];
    res *= C[cnt[1]][need[1]];
    res *= C[cnt[2]][need[2]];
    ans += res;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();

  return 0;
}