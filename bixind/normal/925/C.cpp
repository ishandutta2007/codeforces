#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>


using namespace std;

typedef long long ll;
typedef long double ld;

const long long mod = 1000000009;
typedef complex<double> cd;

const long long INF = 1000000010;
const ll LONGINF = 4e18;
const double PI = 3.141592653589793;

ll a[100100];
int st[100100];


void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> cur;
  vector<int> ones;

  for (ll d = 59; d >= 0; --d) {
    vector<int> bad;
    for (int i = 0; i < n; ++i) {
      if (st[i] == 0 && (a[i] & (1ll << d))) {
        bad.push_back(i);
        st[i] = 1;
      }
    }

    if (bad.size() > ones.size() + 1) {
      cout << "No" << endl;
      return;
    }

    vector<int> ones1, cur1;

    int curi = 0;

    for (int i = 0; i < bad.size(); ++i) {
      if (d > 0 && (a[bad[i]] & (1ll << (d - 1)))) {
        ones1.push_back(cur1.size());
      }
      cur1.push_back(bad[i]);
      if (i + 1 < bad.size()) {
        while (curi <= ones[i]) {
          if (d > 0 && (a[cur[curi]] & (1ll << (d - 1))))
            ones1.push_back(cur1.size());
          cur1.push_back(cur[curi++]);
        }
      }
    }

    while (curi < cur.size()) {
      if (d > 0 && (a[cur[curi]] & (1ll << (d - 1))))
        ones1.push_back(cur1.size());
      cur1.push_back(cur[curi++]);
    }

    cur = cur1;
    ones = ones1;
  }

  cout << "Yes" << endl;


  for (int i = 0; i < n; ++i) {
    cout << a[cur[i]] << ' ';
  }

  cout << endl;
}

void init() {

}

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  init();
//  ll t;
//  cin >> t;
//  while (t--)
  solve();
  return 0;
}