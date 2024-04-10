#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

char A[110][110];
int a, b, c, d, n, X[110];

int next(int cell)
{
  int y=cell/1000, x=cell%1000;
  //cerr<<x<<" "<<y<<endl;
  if (((x+1<a+c && y<d) || x+1<a) && A[y][x+1]==0)
    return cell+1;
  if (x>0 && A[y][x-1]==0)
    return cell-1;
  else
    return cell+1000;
}

int main() {
  int i, st=0, np=0, a1, b1, c1, d1, j;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d%d%d%d%d", &a1, &b1, &c1, &d1, &n);
  puts("YES");
  for (i=0; i<n; i++)
    scanf("%d", &X[i]);
  if (b1<d1)
    a=c1, b=d1, c=a1, d=b1;
  else
    a=a1, b=b1, c=c1, d=d1;
  if (d%2==1)
    st=a+c-1;
  for (i=0; i<a*b+c*d; i++)
  {
    if (X[np]==0)
      np++;
    X[np]--;
    A[st/1000][st%1000]=np+'a';
    st=next(st);
  }
  if (b==b1)
  {
    for (i=0; i<b; i++)
    {
      for (j=0; j<a+c; j++)
      {
        if (A[i][j]==0)
          printf(".");
        else
          printf("%c", A[i][j]);
      }
      printf("\n");
    }
  }
  else
  {
    for (i=0; i<b; i++)
    {
      for (j=0; j<a+c; j++)
      {
        if (A[i][a+c-1-j]==0)
          printf(".");
        else
          printf("%c", A[i][a+c-1-j]);
      }
      printf("\n");
    }
  }
  return 0;
}