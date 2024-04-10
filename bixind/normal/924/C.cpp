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

const long long mod = 1000000007;
typedef complex<double> cd;

const long long INF = 1000000000;
const ll LONGINF = 4e18;
const double PI = 3.141592653589793;



int m[100100], t[100100];


void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    t[i] = m[i] + 1;
  }

  int diff = n;
  for (int i = n - 1; i >= 0; --i) {
    if (i - t[i] > diff) {
      t[i] = i - diff;
    }
    if (i - t[i] < diff) {
      diff = i - t[i];
    }
  }
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    t[i] = max(cur, t[i]);
    cur = max(cur, t[i]);
  }
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    s += t[i] - m[i] - 1;
  }
  cout << s << endl;
}



void init() {

}

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  init();
//  int t;
//  cin >> t;
//  while (t--)
    solve();
  return 0;
}