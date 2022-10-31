#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

int Pot(int b, int eksp)
{
  int r=1;

  for (; eksp; eksp>>=1, b = (int) (((ll) b * b) % n))
    if (eksp & 1)
      r = (int) (((ll) r * b) % n);
  return r;
}

int main()
{
  scanf("%d", &n);

  if (n == 1)
    printf("YES\n1\n");
  else if (n == 4)
    printf("YES\n1\n3\n2\n4\n");
  else {
    int ne=0;
    for (int i=2; i<n; i++)
      if (!(n % i))
        ne = 1;
    if (ne)
      printf("NO\n");
    else {
      printf("YES\n1\n");
      for (int i=2; i<n; i++)
        printf("%d\n", (int) (((ll) i * Pot(i-1, n-2)) % n));
      printf("%d\n", n);
    }
  }

  return 0;
}