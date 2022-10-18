#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

//#define M_PI 3.141592653589793238462643
//#define eps 1e-8

using namespace std;

int n, m, k, Key[1100][2], Kp[1100][2];
char s[1100][20], l[20];
int Vs[1100][2], C[1100][2];

int main()
{
  int i, j, p=-1, tmp, tmp2, t, from, to, i2;
  bool fl=1;
  //freopen(".in", "r", stdin);
  scanf("%d%d%d", &n, &m, &k);
  for (i=0; i<m; i++)
    scanf("%d%d", &Key[i][0], &Key[i][1]);
  for (i=0; i<k; i++)
  {
    //cerr<<i<<endl;
    scanf(" %s %d %d", s[i], &Vs[i][0], &tmp);
    for (j=0; j<tmp; j++)
    {
      scanf("%d", &tmp2);
      Kp[tmp2-1][0]=Vs[i][0];
    }
  }
  for (i=0; i<k; i++) 
  {
    scanf(" %s %d %d", l, &tmp2, &tmp);
    for (j=0; j<k; j++)
    {
      if (strcmp(l,s[j])==0)
      {
        p=j;
        break;
      }
      if (j==k-1)
        return 1;
    }
    Vs[p][1]=tmp2;
    for (j=0; j<tmp; j++)
    {
      scanf("%d", &tmp2);
      Kp[tmp2-1][1]=Vs[p][1];
    }
  }
  for (i=0; i<m; i++)
    if (Kp[i][0]*Kp[i][1]==0)
      return 1;
  //printf("%d %d %d %d\n", Key[0][0], Key[0][1], Kp[0][0], Kp[0][1]);
  //printf("%d %d %d %d\n", Vs[0][0], Vs[0][1], Vs[1][0], Vs[1][1]);
  for (i=0; i<2; i++)
  {
    for (j=1; j<=n; j++)
      C[j][i]=j;
    for (j=0; j<1100; j++)
    {
      for (t=0; t<m; t++)
      {
        if (C[Key[t][0]][i]!=C[Key[t][1]][i] && (C[Key[t][0]][i]==C[Kp[t][i]][i] || C[Key[t][1]][i]==C[Kp[t][i]][i]))
        {
          //cerr<<"!!!"<<endl;
          from=max(C[Key[t][0]][i],C[Key[t][1]][i]), to=min(C[Key[t][0]][i],C[Key[t][1]][i]);
          for (i2=1; i2<=n; i2++)
            if (C[i2][i]==from)
              C[i2][i]=to;
        }
      }
    }
  }
  //printf("%d %d %d %d\n", C[1][0], C[1][1], C[2][0], C[2][1]);
  //printf("%d %d %d %d\n", 
  for (i=1; i<=n; i++)
    if (C[i][0]!=C[i][1])
      fl=0;
  for (i=0; i<k; i++)
    if (C[Vs[i][0]][0]!=C[Vs[i][1]][1])
      fl=0; //cerr<<"!!!"<<endl;
  for (i=0; i<m; i++)
    if (C[Kp[i][0]][0]!=C[Kp[i][1]][1])
      fl=0;
  if (fl)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;  
}