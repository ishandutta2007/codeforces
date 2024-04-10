#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

int n, R[2], A[2][2];
char s[2][2100000];

int main()
{
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (scanf("%d ", &n), i=0; i<2; i++)
    gets(s[i]);
  for (i=0; i<2*n; i++)
    A[(int)(s[0][i]-'0')][(int)(s[1][i]-'0')]++;
  for (i=0; i<2*n; i++)
  {
    if ((i&1)==0)
    {
      if (A[1][1]>0)
      {
        A[1][1]--, R[0]++;
        continue;
      }
      if (A[1][0]>0)
      {
        A[1][0]--, R[0]++;
        continue;
      }
      if (A[0][1]>0)
      {
        A[0][1]--;
        continue;
      }
      A[0][0]--;
      continue;
    }

      if (A[1][1]>0)
      {
        A[1][1]--, R[1]++;
        continue;
      }
      if (A[0][1]>0)
      {
        A[0][1]--, R[1]++;
        continue;
      }
      if (A[1][0]>0)
      {
        A[1][0]--;
        continue;
      }
      A[0][0]--;

  }
  if (R[0]>R[1])
    puts("First");
  if (R[0]==R[1])
    puts("Draw");
  if (R[0]<R[1])
    puts("Second");
  return 0;
}