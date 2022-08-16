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

const int N = 1e3 + 10;

int n, m;
ll ans = 0;
bool blocked[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void flip(int x, int y);
ll count_staircases(int x, int y);
int go(int x, int y, int d1, int d2);

int main() {
  fast_cin();
  int q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ll c1 = 0, c2 = 0;
      if (i == 1) {
        c1 = go(i, j, 3, 2);
      }
      if (j == 1) {
        c2 = go(i, j, 2, 3);
      }
      ans += (c1 * (c1 - 1)) / 2;
      ans += (c2 * (c2 - 1)) / 2;
    }
  }
  ans += n * m;
  // cout << ans << endl;
  while (q--) {
    int x, y;
    cin >> x >> y;
    flip(x, y);
    cout << ans << '\n';
  }
}

void flip(int x, int y) {
  ans -= count_staircases(x, y);
  blocked[x][y] ^= 1;
  ans += count_staircases(x, y);
}

ll count_staircases(int x, int y) {
  return go(x, y, 0, 1) * go(x, y, 3, 2) + go(x, y, 1, 0) * go(x, y, 2, 3) - !blocked[x][y];
}

int go(int x, int y, int d1, int d2) {
  int cnt = 0;
  while (true) {
    if (x < 1 or x > n or y < 1 or y > m or blocked[x][y]) {
      break;
    }
    ++cnt;
    x += dx[d1]; y += dy[d1];
    swap(d1, d2);
  }
  return cnt;
}