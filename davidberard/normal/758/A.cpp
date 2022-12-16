#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);

  int max = 0;
  long long int sum = 0;
  int wealth;
  for(int i=0;i<n;++i)
  {
    scanf("%d", &wealth);
    if(wealth > max)
      max = wealth;
    sum += wealth;
  }
  long long int amt = n;
  amt *= max;
  amt -= sum;

  printf("%I64d\n", amt);

  return 0;
}