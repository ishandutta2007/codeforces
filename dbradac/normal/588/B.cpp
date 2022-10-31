#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  ll n, r=1;

  scanf("%lld", &n);

  for (int i=2; i<=1000000; i++) {
    if (!(n % i)) {
      r *= i;
      for (; !(n % i); n /= i);
    }
  }

  r *= n;

  printf("%lld\n", r);

  return 0;
}