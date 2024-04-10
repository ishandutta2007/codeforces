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

char s[2100][1100], ss[2100][1100];
int C[1100][1100];

int main()
{
  int i, j, n, m, k, bal;
  bool inv=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d ", &n, &m, &k);
  for (i=0; i<=2*n-2; i++)
    gets(s[i]);
  if (k==1)
  {
    bal=0;   
    for (i=0; i<=2*n-2; i++)
      for (j=0; j<m-1+(i&1); j++)
        (s[i][j]=='E')?(bal++):(bal-=3);// cerr<<s[i][j]<<endl;
    if (bal<0)
    {
      puts("NO");
      return 0;
    }
    puts("YES");
    for (i=0; i<n; i++, printf("\n"))
      for (j=0; j<m; j++)
        printf("1 ");
    return 0;
  }
  if (n*(m-1)<m*(n-1))
  {
    inv=1, memcpy(ss,s,sizeof(s)), memset(s,0,sizeof(s));
    for (i=0; i<=2*n-2; i++)
      for (j=0; j<m-1+(i&1); j++)
      {
        if ((i&1)==0)
        {
          s[2*j+1][i>>1]=ss[i][j];
          continue;
        }
        s[2*j][i>>1]=ss[i][j];
      }
    swap(n,m);
  }
  for (i=0; i<n; i++)
  {
    for (j=1; j<m; j++)
      (s[2*i][j-1]=='E')?(C[i][j]=C[i][j-1]):(C[i][j]=C[i][j-1]^1);
    if (i==0)
      continue;
    bal=0;
    for (j=0; j<m; j++)
    {
      if (s[2*i-1][j]=='E' && C[i][j]==C[i-1][j])
      {
        bal++;
        continue;
      }
      if (s[2*i-1][j]=='N' && C[i][j]!=C[i-1][j])
      {
        bal++;
        continue;
      }
      bal--;
    }
    if (bal<0)
      for (j=0; j<m; j++)
        C[i][j]^=1;
  }
  puts("YES");
  if (!inv)
    for (i=0; i<n; i++, printf("\n"))
      for (j=0; j<m; j++)
        printf("%d ", C[i][j]+1);
  else
    for (i=0; i<m; i++, printf("\n"))
      for (j=0; j<n; j++)
        printf("%d ", C[j][i]+1);
  return 0;
}