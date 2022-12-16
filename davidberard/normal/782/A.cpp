#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

int main()
{
  int n;
  int pairthing[MAX];

  scanf("%d", &n);
  memset(pairthing, 0, sizeof(pairthing));

  int cmax = 0;
  int counter = 0;

  int sock;

  for(int i=0;i<2*n;++i)
  {
    scanf("%d", &sock);
    if(pairthing[sock] == 0)
    {
      ++counter;
      pairthing[sock] = 1;
    }
    else {
      --counter;
      ++pairthing[sock];
    }
    if(counter > cmax)
      cmax = counter;
  }

  printf("%d\n", cmax);


  return 0;
}