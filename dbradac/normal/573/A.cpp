#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int da=1, n, val;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    for (; !(tmp % 2); tmp/=2);
    for (; !(tmp % 3); tmp/=3);
    if (!i)
      val = tmp;
    else if (tmp != val)
      da = 0;
  }

  printf("%s\n", da ? "Yes" : "No");

  return 0;
}