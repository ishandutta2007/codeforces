#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  ll a, b;

  scanf("%lld%lld", &a, &b);
  int ret=0;

  for (int i=0; i<62; i++) {
    ll tmp = (1ll<<i) - 1;
    for (int j=0; j<i-1; j++) {
      ll nn = tmp ^ (1ll<<j);
      if (nn >= a && nn <= b)
        ret++;
    }
  }

  printf("%d\n", ret);

  return 0;
}