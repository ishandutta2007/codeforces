#include <bits/stdc++.h>

using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector <string> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector <bool> care(n - 1);
  for (int i = 0; i < n - 1; i++)
  {
    care[i] = 1;
  }

  int cost = 0;
  for (int j = 0; j < m; j++)
  {
    bool good = 1;
    for (int i = 0; i + 1 < n; i++)
    {
      if (care[i] && a[i][j] > a[i + 1][j])
      {
        good = 0;
        break;
      }
    }
    if (good == 0)
    {
      cost++;
    }
    else
    {
      for (int i = 0; i + 1< n; i++)
      {
        if (a[i][j] < a[i + 1][j])
        {
          care[i] = 0;
        }
      }
    }
  }
  cout << cost << "\n";

  return 0;
}