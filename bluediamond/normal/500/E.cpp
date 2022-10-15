#include<bits/stdc++.h>
using namespace std;

int n, q, x, y, aib[200002], p[200002], l[200002];
int dr[200002];
int nxt[18][200002];
int sum[18][200002];

int query (int x) {
  int sol = 0;
  for (int i = x; i > 0; i -= (i & -i))
    sol = max(sol, aib[i]);
  return sol;
}

int update (int x, int val) {
  for (int i = x; i <= n; i += (i & -i))
    aib[i] = max(aib[i], val);
}


int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> l[i];
  }
  for (int i = n; i > 0; i--) {
    dr[i] = max(p[i] + l[i], query(upper_bound(p + 1, p + n + 1, p[i] + l[i]) - p - 1));
    nxt[0][i] = upper_bound(p + 1, p + n + 1, dr[i]) - p;
    sum[0][i] = max(p[nxt[0][i]] - dr[i], 0);
    update(i, dr[i]);
  }
  nxt[0][n + 1] = n + 1;
  for (int lg = 1; lg <= 17; lg++) {
    nxt[lg][n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
      nxt[lg][i] = nxt[lg - 1][nxt[lg - 1][i]];
      sum[lg][i] = sum[lg - 1][i] + sum[lg - 1][nxt[lg - 1][i]];
    }
  }
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = 17; i >= 0; i--) {
      if (nxt[i][x] <= y) {
        ans += sum[i][x];
        x = nxt[i][x];
      }
    }
    cout << ans << "\n";
  }
	return 0;
}