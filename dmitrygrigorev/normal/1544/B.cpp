#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

bool ans[20][20];
bool now[20][20];
int res = 0;

void solve() {
  
  int n, m;
  cin >> n >> m;

  vector<pair<int, int> > cells;
  int x = 0, y = 0;
  int regime = 0;

  while (true) {
    if (cells.size() == 0 || cells.back() != mp(x, y)) {
      cells.pb(mp(x, y));
    }
    if (regime == 0 && y + 1 < m) y++;
    else if (regime == 1 && x + 1 < n) x++;
    else if (regime == 2 && y - 1 >= 0) y--;
    else if (regime == 3 && x - 1 >= 0) x--;
    else regime++;
    if (x == 0 && y == 0) break;
  }

  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] = false;
  res = 0;

  for (int start = 0; start < cells.size(); ++start) {

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) now[i][j] = false;
    int tut = 0;

    for (int i = 0; i < cells.size(); ++i) {
      auto cur = cells[(start + i) % cells.size()];

      bool can = true;
      for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
        int a = cur.x + dx, b = cur.y + dy;
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (now[a][b]) can = false;
      }

      if (can) {
        tut++;
        now[cur.x][cur.y] = true;
      }

    }

    if (tut > res) {
      res = tut;
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] = now[i][j];
    }

  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << ans[i][j];
    cout << '\n';
  }
  //cout << '\n';

  

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}