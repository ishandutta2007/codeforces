#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define llong long long 

template<typename x> ostream& operator<< (ostream& cout, const vector<x>& a) {
  cout << "[";
  len(a) && cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i] ;
  return cout;
}

template<typename u, typename v>
ostream& operator<< (ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define maxn 1010

int n;
ii a, b, c;

bool vis[maxn][maxn];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> b.xx >> b.yy >> a.xx >> a.yy >> c.xx >> c.yy;
  queue<ii> qu;
  vis[a.xx][a.yy] = 1;
  for (qu.push(a); len(qu); qu.pop()) {
    a = qu.front();
    if (a == c) {
      cout << "YES";
      return 0;
    }
    rep(i, 8) {
      int nx = a.xx + dx[i];
      int ny = a.yy + dy[i];
      if (nx == 0 or nx == n + 1 or ny == 0 or ny == n + 1) continue;
      if (vis[nx][ny]) continue;
      if (nx == b.xx || ny == b.yy) continue;
      if (nx + ny == b.xx + b.yy || nx - ny == b.xx - b.yy) continue;
      vis[nx][ny ] =1;
      qu.push({nx, ny});
    }
  }
  cout << "NO";

  return 0;
}