#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int br2, br3;

int Moze(int x)
{
  int a = x / 2;
  int b = x / 3;
  int c = x / 6;

  return a >= br2 && b >= br3 && a + b - c >= br2 + br3;
}

int main()
{
  scanf("%d%d", &br2, &br3);

  int lo=0, hi=1e8;

  for (; lo<hi; ) {
    int mid = (lo + hi) / 2;
    if (Moze(mid))
      hi = mid;
    else
      lo = mid + 1;
  }

  printf("%d\n", lo);

  return 0;
}