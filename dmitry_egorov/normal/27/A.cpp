#include <stdio.h>
#include <iostream>

using namespace std;

int A[4000], n;

int main()
{
  int i, b;
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &b);
    A[b]=1;
  }
  for (i=1; ;i++)
  {
    if (A[i]==0)
    {
      printf ("%d", i);
      return 0;
    }
  }
}