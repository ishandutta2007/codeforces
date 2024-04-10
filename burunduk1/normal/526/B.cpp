/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.04
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair <int, int> pii;

int main() {
  int n;
  cin >> n, n++;
  int a[(1 << n) + 1] = {0};
  forn(i, (1 << n) - 2)
    cin >> a[i + 2];
  function<pii(int)> dfs = [&]( int v ) {
    if (v >= (1 << (n - 1)))
      return pii(a[v], 0);
    pii l = dfs(2 * v);
    pii r = dfs(2 * v + 1);
    int ma = max(l.first, r.first);
    return pii(ma + a[v], l.second + r.second + (ma - l.first) + (ma - r.first));
    //printf("%d : %d, %d\n", v, res.first, res.second);
    //return res;
  };
  cout << dfs(1).second << endl;
  return 0;
}