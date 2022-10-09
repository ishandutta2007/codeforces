#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; ) 

#define maxn 200
int n, m;
string a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) cin >> a[i];

  int minx = m + 1, maxx = -1, miny = n + 1, maxy = -1;
  rep(i, n) rep(f, m) {
    if (a[i][f] == 'W') continue;
    minx = min(minx, f);
    maxx = max(maxx, f);
    miny = min(miny, i);
    maxy = max(maxy, i);
  }

  cout << (miny + maxy) / 2 + 1 << ' ' << (minx + maxx) / 2 + 1;

  return 0;
}