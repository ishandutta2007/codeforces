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

using namespace std;

char s[11000], l[1100000];
int A[11000], B[1100000];
int ls, ll; 
int N[11000][26];

int main()
{
  int res=0, p, i, j, c, fl;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s);
  gets(l);
  ls=strlen(s), ll=strlen(l);
  for (i=0; i<ls; i++)
    A[i]=(int)(s[i]-'a');
  for (i=0; i<ll; i++)
    B[i]=(int)(l[i]-'a');
  for (i=0; i<26; i++)
    for (j=ls-1, p=-1; j>=0; j--)
    {
      if (A[j]==i)
        p=j;
      N[j][i]=p;
    }
  for (c=0, fl=0, i=0; i<ll; i++)
  {
    if (c>=ls || N[c][B[i]]==-1)
      c=0, res++, fl=0;
    if (N[c][B[i]]==-1 && c==0)
    {
      printf("-1\n");
      return 0;
    }
    //cerr<<c<<" "<<B[i]<<"  "<<N[c][B[i]]<<endl;
    c=N[c][B[i]]+1, fl=1;
  }
  printf("%d\n", res+fl);
  return 0;
}