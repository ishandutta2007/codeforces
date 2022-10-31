#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int p[55];

int main()
{
  int h;
  ll n, rje=0, sz=0;

  cin >> h >> n; n--;

  for (int i=0; i<h; i++, n /= 2)
    p[i] = n & 1;

  sz = (1ll << ((ll) h)) - 1;
  for (int i=h-1, prosli=1; i>=0; i--, sz = (sz + 1) / 2 - 1, rje++) {
    if (prosli == p[i])
      rje += sz;
    prosli = p[i];
  }

  cout << rje << endl;

  return 0;
}