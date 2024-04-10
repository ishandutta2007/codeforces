#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int w, n;
const int N = 4000 + 7;
int a[N];
string s;

map <int, int> f;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> w >> s;
  n = (int) s.size();
  for (int i = 0; i < n; i++)
    a[i] = (s[i] - '0');

  for (int l = 0; l < n; l++)
  {
    int c = 0;
    for (int r = l; r < n; r++)
    {
      c += a[r];
      f[c]++;
    }
  }

  ll res = 0;
  for (int d = 1; d * d <= w; d++)
    if (w % d == 0)
    {
      int d2 = w / d;
      ll m = 2;
      if (d == d2)
        m = 1;
      ll a = f[d];
      ll b = f[d2];
      res += m * a * b;
    }
  if (w == 0)
  {
    ll c0 = f[0];
    ll all = n * (n + 1) / 2 - f[0];
    res = c0 * (all * 2 + c0);
  }
  cout << res << "\n";
  return 0;
}