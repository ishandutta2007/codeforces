#include <iostream>

using namespace std;

int main()
{
  int n0, n, d, m, l, cnt = 0;
  long long x = 0, pos = 0;

  cin >> n >> d >> m >> l, n0 = n;
  while (1)
  {
    pos += d;
    while (n > 1 && pos > x + l)
      x += m, n--;
    if (!(x <= pos && pos <= x + l))
      break;

    if (++cnt > (int)2e6)
    {
      long long len = m;
      len *= n0 - 1, len += l;
      len /= d, len *= d;
      cout << len + d << endl;
      return 0;
    }
  }
  cout << pos << endl;
  return 0;
}