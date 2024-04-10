#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define ii pair<int, int>

#define maxn 1010
int n, m;
string grid[maxn];

bool check(int cr, int cc) {
    for (int i: {cr - 1, cr, cr + 1})
        for (int f: { cc - 1, cc, cc + 1}) {
            if (i < 0 or i >= n) return false;
            if (f < 0 or f >= m) return false;
            if (i == cr and f == cc) continue;
            if (grid[i][f] == '.') return false;
        }
    return true;
}

bool can_draw_on(int r, int c) {
    for (int i: {r - 1, r, r + 1})
        for (int f: {c - 1, c, c + 1}) {
            if (i == r and c == f) continue;
            if (check(i, f)) return true;
        }
    return false;
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) cin >> grid[i];
  rep(i, n) rep(f, m)
      if (grid[i][f] == '#' and !can_draw_on(i, f)) {
          cout << "NO";
          return 0;
      }
  cout << "YES";

  return 0;
}