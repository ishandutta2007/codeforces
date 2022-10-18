#include <stdio.h>
#include <iostream>

using namespace std;

int n, A[100100], l;
 
int main()
{
  int i, last;                         
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  l=0;
  for (i=0; i<n-1; i++)
  {
    if (l==0 && A[i]>A[i+1])
    {
      l=-1;
      last=i+1;
    }
    if (l==0 && A[i]<A[i+1])
    {
      l=1;
      last=i+1;
    }
    if (l==1 && A[i]>A[i+1])
    {
      printf("3\n%d %d %d", last, i+1, i+2);
      return 0;
    }
    if (l==-1 && A[i]<A[i+1])
    {
      printf("3\n%d %d %d", last, i+1, i+2);
      return 0;
    }
  }
  printf ("0");
  return 0;
}