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

int query(string s);

int main() {
  fast_cin();
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  string base(m, '0');
  for (int i = 0; i < m; ++i) {
    base[i] = '1';
    l[i] = query(base);
    base[i] = '0';
  }
  vector<int> ids(m);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int i, int j) {
    return l[i] < l[j];
  });
  int cost = 0;
  for (auto& i : ids) {
    base[i] = '1';
    if (query(base) < cost + l[i]) {
      base[i] = '0';
    } else {
      cost += l[i];
    }
  }
  cout << "! " << cost << endl;
}

int query(string s) {
  cout << "? " << s << endl;
  int ans; cin >> ans;
  return ans;
}