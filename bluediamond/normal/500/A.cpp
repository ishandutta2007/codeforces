#include <bits/stdc++.h>

using namespace std;

int t, n, a[30002], sum, poz;

int main()
{
  cin >> n >> t;
  for (int i = 1; i < n; i++)
    cin >> a[i];
  poz = 1;
  while (poz < t)
    poz += a[poz];
  if (poz == t)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}