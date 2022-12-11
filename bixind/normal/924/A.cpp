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

int p[111];

int fs(int a) {
  return p[a] == a ? a : (p[a] = fs(p[a]));
}

void us(int a, int b) {
  a = fs(a);
  b = fs(b);
  p[a] = b;
}

string t[55];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  for (int i = 0; i < n + m; ++i)
    p[i] = i;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (t[i][j] == '#')
        us(i, n + j);
    }
  }
  vector<vector<int>> vs(n + m);
  for (int i = 0; i < n + m; ++i) {
    vs[fs(i)].push_back(i);
  }
  for (auto& v: vs) {
    for (int i: v) {
      for (int j: v) {
        if (i < n && j >= n && t[i][j - n] != '#') {
          cout << "No" << endl;
          return;
        }
      }
    }
  }
  cout << "Yes" << endl;
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