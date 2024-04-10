#include <stdio.h>
#include <iostream>

using namespace std;

int A[60][60], n, i, j, x, y, k;
 
int main()
{
  int b, l, c;
  scanf("%d", &n);
  for (i=0; i<(n*(n-1)/2)-1; i++)
  {
    scanf("%d%d", &b, &c);
    A[b][c]=b;
    A[c][b]=b;
  }
  for (i=1; i<=n; i++)
  {
    for (j=i+1; j<=n; j++)
    {
      if (A[i][j]==0)
      {
        x=i;
        y=j;
        A[x][y]=x;
        A[y][x]=x;
        j=n+1;
        i=n+1;
      }
    }
  }
  l=1;
  for (k=1; k<=n; k++)
  {
    if (k!=x && k!=y)
    {
      if (A[x][k]==k && A[y][k]==y)
        l=0;
    }
  }
  if (l==1)
    printf("%d %d", x, y);
  else
    printf("%d %d", y, x); 
}