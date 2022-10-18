#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m, A[120], B[120], C[120][120], Res[120];

int ise (int i, int j)
{
  int x1, y1, x2, y2, ans;
  x1=A[i];
  y1=B[i];
  x2=A[j];
  y2=B[j];
  y1=(y1-x1+n)%n;
  x2=(x2-x1+n)%n;
  y2=(y2-x1+n)%n;
  if ((x2-y1)*(y2-y1)<0 && x2!=0 && y2!=0)
    ans=1;
  else
    ans=0;
  return ans;
}

int main()
{
  int i, j, k, new1;
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
   scanf ("%d%d", &A[i], &B[i]);
  for (i=0; i<m; i++)
  {
    for (j=i+1; j<m; j++)
    {
      C[i][j]=ise(i,j);
      C[j][i]=ise(j,i);
    }
  }
  Res[0]=1;
  for (i=0; i<m; i++)
  {
    new1=0;
    for (j=0; j<m; j++)
    {
      for (k=0; k<m; k++)
      {
        if (Res[j]>0 && C[j][k]==1)
        {
          if (Res[k]>0 && Res[k]+Res[j]!=3)
          {
            printf("Impossible");
            return 0;
          }
          if (Res[k]==0)
          {
            Res[k]=3-Res[j];
            new1=1;
          }
        }
      }
    }
    if (new1==0)
    {
      for (i=0; i<m; i++)
      {
        if (Res[i]==0)
        {
          Res[i]=1;
          new1=1;
          break;
        }
      }
    }
    if (new1==0)
      break;
  }
  for (i=0; i<m; i++)
  {
    if (Res[i]==1)
      printf("i");
    else
      printf("o");
  }
  return 0;
}