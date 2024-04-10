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

int A[20][6], n, B[4];

bool check (int l)
{
  int a0=0, a1=0, i, j;
  for (i=0; i<4; i++)
    for (j=i+1; j<4; j++)
      if (B[i]==B[j])
        return 0;
  //cerr<<B[0]<<B[1]<<B[2]<<B[3]<<endl;
  for (i=0; i<4; i++) 
  {
    a0+=(int)(B[i]==A[l][i+2]);
    for (j=0; j<4; j++)
      a1+=(int)(B[i]==A[l][j+2]);
  }
  a1-=a0;
  //if (a1==A[l][1] && a0==A[l][0])
  //  cerr<<"!!!!"<<endl;
  return (a1==A[l][1] && a0==A[l][0]);
}

int main() {
  int res=0, ans=0, i, j, tmp;
  bool fl=1;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d%d%d", &tmp, &A[i][0], &A[i][1]);
    for (j=0; j<4; j++)
      A[i][j+2]=tmp%10, tmp/=10;
  }
  for (B[0]=0; B[0]<10; B[0]++)
    for (B[1]=0; B[1]<10; B[1]++)
      for (B[2]=0; B[2]<10; B[2]++)
        for (B[3]=0; B[3]<10; B[3]++)
        {
          //cerr<<"!!!!"<<endl;
          fl=1;
          for (i=0; i<n; i++)
          {
            //cerr<<i<<endl;
            fl=(fl && check(i));
          }
          if (fl==1)
            res++, ans=B[0]+B[1]*10+B[2]*100+B[3]*1000;
        }

  if (res==1)
  {
    if (ans>=1000)                                
      printf("%d\n", ans);
    else
      printf("0%d\n", ans);
  }
  if (res>1)
    puts("Need more data");
  if (res==0)
    puts("Incorrect data");
  return 0;
}