#include <bits/stdc++.h>

using namespace std;


int n, m, v[1002], st[1002], w[1002], ans, f[1002], nr;


int main()
{
  cin >> n >> m;
  for (int  i = 1; i <= n; i++)
    cin >> w[i];
  for (int j = 1; j <= m; j++) {
    cin >> v[j];
    if (f[v[j]] == 0) {
      st[++nr] = v[j];
      f[v[j]] = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    int poz = 0;
    for (int j = 1; j <= nr; j++)
      if (st[j] == v[i]) {
        poz = j;
        break;
      }
    for (int j = poz - 1; j >= 1; j--) {
      ans += w[st[j]];
      swap(st[j], st[j + 1]);
    }
  }
  cout << ans;
  return 0;
}