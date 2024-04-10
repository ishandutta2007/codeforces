/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define sz(a) (int)(a).size()

typedef long long ll;

const int N = 2e5;

int n, x, y;
vector<int> c[N];

typedef pair <int, int> pii;

pii dfs( int v, int pr ) {
  int sum = 0, k = 0;
  for (int x : c[v])
    if (x != pr) {
      pii p = dfs(x, v);
      if (p.second && k >= 2)
        p.first--;
      sum += p.first, k += p.second;
    }
  if (k <= 1 && pr != -1)
    sum++, k = 1;
  //printf("%d: sum=%d, end=%d\n", v, sum, k == 1);
  return {sum, k == 1};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> y >> x;
  forn(i, n - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    c[a].pb(b), c[b].pb(a);
  }
  if (x > y) {
    int cnt = dfs(0, -1).first;
    cout << (ll)cnt * y + (ll)(n - 1 - cnt) * x;
  } else {
    int bad = 0;
    forn(i, n)
      bad |= sz(c[i]) == n - 1;
    cout << (ll)(n - 1) * x + bad * (y - x);
  }
  return 0;
}