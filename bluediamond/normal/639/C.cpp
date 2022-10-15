#include <bits/stdc++.h>;

using namespace std;

#define int long long

int dv2(int a)
{
  a--;
  return -a / 2;
}

const int N = (int) 2e5 + 777;
int n, lim, a[N], init[N], aft[N];

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> lim;
  for (int i = 0; i <= n; i++)
  {
    cin >> a[i];
    init[i] = a[i];
  }
  for (int i = 0; i <= n; i++)
  {
    if (a[i] >= 0)
    {
      a[i + 1] += a[i] / 2;
      a[i] -= 2 * (a[i] / 2);
    }
    else
    {
      a[i + 1] -= dv2(a[i]);
      a[i] += 2 * dv2(a[i]);
    }
  }
  if (a[n + 1] < 0)
  {
    a[n + 1] = 0;
    for (int i = 0; i <= n; i++)
    {

      a[i] = -init[i];
      init[i] = a[i];
    }
    for (int i = 0; i <= n; i++)
    {
      if (a[i] >= 0)
      {
        a[i + 1] += a[i] / 2;
        a[i] -= 2 * (a[i] / 2);
      }
      else
      {
        a[i + 1] -= dv2(a[i]);
        a[i] += 2 * dv2(a[i]);
      }
    }
  }
  for (int i = n + 1; i >= 0; i--)
  {
    aft[i] = aft[i + 1] | (a[i] > 0);
  }
  int mx_try = 0;
  while (mx_try < n && a[mx_try] == 0)
  {
    mx_try++;
  }
  int sol = 0;
  for (int k = 0; k <= mx_try; k++)
  {
    int value = -init[k], coef = 1;
    for (int i = k; i <= n + 1; i++)
    {
      value += coef * a[i];
      if (!aft[i])
      {
        continue;
      }
      if (abs(value) > (int) 2e9 || coef > (int) 2e9)
      {
        value = (int) 1e9 + 7;
        break;
      }
      coef *= 2;
    }
    if (abs(value) <= lim)
    {
      if (value == 0 && k == n)
      {
        continue;
      }
      sol++;
    }
  }
  cout << sol << "\n";
  return 0;
}