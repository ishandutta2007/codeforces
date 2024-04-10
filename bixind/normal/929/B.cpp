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

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const long long INF = 1000000000;
const double PI = 3.141592653589793;

int t[111][12];

string rows[111];

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > empty;

  for (int i = 0; i < n; ++i) {
    cin >> rows[i];
    string& s(rows[i]);
    for (int j = 0; j < 12; ++j) {
      if (s[j] == '.') {
        empty.emplace_back(i, j);
      } else if (s[j] == 'S') {
        if (j > 0)
          t[i][j - 1]++;
        if (j < 11)
          t[i][j + 1]++;
      }
    }
  }
  sort(empty.begin(), empty.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
    return t[p1.first][p1.second] < t[p2.first][p2.second];
  });
  for (int i = 0; i < k; ++i) {
    rows[empty[i].first][empty[i].second] = 'x';
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 12; ++j) {
      if (rows[i][j] == 'S') {
        if (j > 0) {
          ans += (rows[i][j - 1] != '.' && rows[i][j - 1] != '-');
        }
        if (j < 11) {
          ans += (rows[i][j + 1] != '.' && rows[i][j + 1] != '-');
        }
      }
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    cout << rows[i] << endl;
  }
}


int main() {
  solve();
  return 0;
}