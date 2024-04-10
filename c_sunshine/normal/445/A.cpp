#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
char Read()
{
  while(1)
  {
    char cc=getchar();
    if(cc=='.'||cc=='-')return cc;
  }
}
int main()
{
  int r,c;
  char cc;
  scanf("%d%d",&r,&c);
  for(int i=1;i<=r;i++)
  {
    for(int j=1;j<=c;j++)
    {
      cc=Read();
      if(cc=='.')
        printf("%c",((i^j)&1)?'W':'B');
      else printf("-");
    }
    printf("\n");
  }
  return 0;
}