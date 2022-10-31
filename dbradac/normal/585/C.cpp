#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  ll x, y;

  scanf("%lld%lld", &x, &y);

  if (__gcd(x, y) > 1)
    printf("Impossible\n");
  else {
    for (int sw=0; x != y; ) {
      if (x < y) {
        sw ^= 1;
        swap(x, y);
      }

      printf("%lld%c", (x - 1) / y, 'A' + sw);
      x -= y * ((x - 1) / y);
    }
    printf("\n");
  }

  return 0;
}