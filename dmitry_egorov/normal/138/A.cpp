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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

bool C[4];
string s[4];
char ss[11000];

int main()
{
  int i, j, k, n, t, cnt, len;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &k);
  for (C[0]=1, C[1]=1, C[2]=1, C[3]=1, i=0; i<n; i++)
  {
    for (j=0; j<4; j++)
    {
      gets(ss), len=strlen(ss), s[j]="";
      for (cnt=0, t=len-1; cnt<k && t>=0; t--)
      {
        s[j].pb(ss[t]);
        if (ss[t]=='a' || ss[t]=='e' || ss[t]=='i' || ss[t]=='o' || ss[t]=='u')
          cnt++;
      }
      if (cnt!=k)
        s[j]="";
    }
    if (s[0]!=s[1] || s[0]!=s[2] || s[0]!=s[3] || s[0]=="")
      C[3]=0;
    if (s[0]!=s[1] || s[2]!=s[3] || s[0]=="" || s[2]=="")
      C[0]=0;
    if (s[0]!=s[2] || s[1]!=s[3] || s[0]=="" || s[1]=="")
      C[1]=0;
    if (s[0]!=s[3] || s[1]!=s[2] || s[0]=="" || s[1]=="")
      C[2]=0;
  }
  if (C[3])
  {
    puts("aaaa");
    return 0;
  }
  if (C[0])
  {
    puts("aabb");
    return 0;
  }
  if (C[1])
  {
    puts("abab");
    return 0;
  }
  if (C[2])
  {
    puts("abba");
    return 0;
  }
  puts("NO");
  return 0;
}