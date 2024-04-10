#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set <int> Sx, Sy;

int main()
{
  int n;
  
  scanf("%d", &n);

  for (; n; n--) {
    int x, y;
    scanf("%d%d", &x, &y);
    Sx.insert(x);
    Sy.insert(y);
  }

  if (Sx.size() < 2 || Sy.size() < 2)
    printf("-1\n");
  else
    printf("%d\n", (*(++Sx.begin()) - *Sx.begin()) * (*(++Sy.begin()) - *Sy.begin()));

  return 0;
}