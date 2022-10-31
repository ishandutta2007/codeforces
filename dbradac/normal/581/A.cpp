#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int r, b;
  
  scanf("%d%d", &r, &b);
  printf("%d %d\n", min(r, b), (r + b) / 2 - min(r, b));

  return 0;
}