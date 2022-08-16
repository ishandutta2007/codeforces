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

const int N = 1e5 + 10, mx = 1e9;

int ask(int x, int y);

int main() {
  fast_cin();
  int q1 = ask(1, 1);
  int q2 = ask(1, mx);
  int q3 = ask(mx, 1);
  int q4 = ask(mx, mx);

  int x1 = ask(1, (q1 - q2 + mx + 1) / 2) + 1;
  int x2 = mx - ask(mx, (q3 - q4 + mx + 1) / 2);
  int y1 = ask((q1 - q3 + mx + 1) / 2, 1) + 1;
  int y2 = mx - ask((q2 - q4 + mx + 1) / 2, mx);

  cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
}

int ask(int x, int y) {
  cout << "? " << x << ' ' << y << endl;
  int d; cin >> d;
  if (d == -1) {
    exit(1);
  }
  return d;
}