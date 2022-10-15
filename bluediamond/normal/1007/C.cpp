#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

signed main()
{
  ll n, x = 0, y = 0, jump_x = 1, jump_y = 1;
  int steps = 0;
  cin >> n;
  while (1)
  {
    steps++;
    jump_x = min(jump_x, n - x);
    jump_y = min(jump_y, n - y);
    cout << x + jump_x << " " << y + jump_y << endl;
    int sol;
    cin >> sol;
    if (!sol)
    {
      return 0;
    }
    if (sol == 1)
    {
      x += jump_x;
      jump_x *= 2;
    }
    if (sol == 2)
    {
      y += jump_y;
      jump_y *= 2;
    }
    if (sol == 3)
    {
      jump_x /= 2;
      jump_y /= 2;
      jump_x = max(jump_x, 1LL);
      jump_y = max(jump_y, 1LL);
    }
  }
  return 0;
}