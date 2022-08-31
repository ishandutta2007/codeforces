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

int ask(vector<int>& a);

int main() {
  fast_cin();
  int n; cin >> n;
  int val = 1;
  for (int i = 1; i <= n; ++i) {
    vector<int> v(n - 1, i);
    v.pb(1);
    if (ask(v) != 0) {
      ++val;
    }
  }
  vector<int> p(n);
  p[n - 1] = val;
  for (int i = 1; i <= n; ++i) {
    if (i == val) {
      continue;
    }
    if (i < val) {
      int diff = val - i;
      vector<int> a(n, diff + 1);
      a[n - 1] = 1;
      p[ask(a) - 1] = i;
    } else {
      int diff = i - val;
      vector<int> a(n, 1);
      a[n - 1] = diff + 1;
      p[ask(a) - 1] = i;
    }
  }
  cout << "! ";
  for (auto& i : p) {
    cout << i << ' ';
  }
  cout << endl;
}

int ask(vector<int>& a) {
  cout << "? ";
  for (auto& i : a) {
    cout << i << ' ';
  }
  cout << endl;
  int res; cin >> res;
  return res;
}