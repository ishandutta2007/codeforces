#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;

int n;

int get(int r1, int c1, int r2, int c2)
{
  cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  int res;
  cin >> res;
  res %= 2;
  return res;
  /// daca res = 0 => ambele sunt inauntru sau ambele sunt afara
  /// daca res = 1 => unul este inauntru iar celalalt este afara
}

int cols[N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i = 1; i < n; i++)
  {
    cols[i] = get(1, 1, n, i);
  }
  int l = 0, r = 0;
  bool g = 0;
  for(int i = 1; i < n; i++)
  {
    if(cols[i])
    {
      if(g == 0)
      {
        g = 1;
        l = i;
      }
      r = i;
    }
  }
  if(g)
  {
    int col1 = l;
    int col2 = r + 1;
    int lo = 1;
    int hi = n;
    int ans1 = 0;
    int ans2 = 0;
    while(lo <= hi)
    {
      int mid = (lo + hi) / 2;
      if(get(1, col1, mid, col1) == 1)
      {
        ans1 = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    lo = 1;
    hi = n;
    while(lo <= hi)
    {
      int mid = (lo + hi) / 2;
      if(get(1, col2, mid, col2) == 1)
      {
        ans2 = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    cout << "! " << ans1 << " " << col1 << " " << ans2 << " " << col2 << "\n";
    return 0;
  }
  for(int i = 1; i < n; i++)
  {
    cols[i] = get(1, 1, i, n);
  }
  l = 0, r = 0;
  g = 0;
  for(int i = 1; i < n; i++)
  {
    if(cols[i])
    {
      if(g == 0)
      {
        g = 1;
        l = i;
      }
      r = i;
    }
  }
  if(g)
  {
    int col1 = l;
    int col2 = r + 1;
    int lo = 1;
    int hi = n;
    int ans1 = 0;
    int ans2 = 0;
    while(lo <= hi)
    {
      int mid = (lo + hi) / 2;
      if(get(col1, 1, col1, mid) == 1)
      {
        ans1 = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    lo = 1;
    hi = n;
    while(lo <= hi)
    {
      int mid = (lo + hi) / 2;
      if(get(col2, 1, col2, mid) == 1)
      {
        ans2 = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    cout << "! " << col1 << " " << ans1 << " " << col2 << " " << ans2 << "\n";
    return 0;
  }
}