#include <cstdio>

long long Inp()
{
  int brd, baz;

  scanf("%d%d", &brd, &baz);
  long long ret=0;

  for (int i=0; i<brd; i++) {
    int tmp;
    scanf("%d", &tmp);
    ret = ret * baz + tmp;
  }

  return ret;
}

int main()
{
  long long a = Inp(), b = Inp();

  if (a < b)
    printf("<\n");
  else if (a == b)
    printf("=\n");
  else
    printf(">\n");

  return 0;
}