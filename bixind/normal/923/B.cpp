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

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n), t(n);
  for (int i = 0;i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0;i < n; i++) {
    cin >> t[i];
  }
  multiset<ll> cur;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cur.insert(v[i] + sum);
    ll today = 0;
    ll sumold = sum;
    sum += t[i];
    while (!cur.empty() && *(cur.begin()) <= sum) {
      today += *cur.begin() - sumold;
      cur.erase(cur.begin());
    }
//    for (auto w : cur) {
//      cout << w << ' ';
//    }
//    cout << endl;
    today += t[i] * cur.size();
    cout << today << ' ';
//    cout << endl;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();

  return 0;
}