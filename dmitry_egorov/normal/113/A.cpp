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

vector <char> tmp;
char s[110000];
int A[110000][2], e;

int main()
{
  int i, j, l;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  while (scanf(" %s", s)==1)
  {
    //puts(s);
    l=strlen(s);
    //if (l==0)
    //  break;
    reverse(s,s+l);
    //puts(s);
    if (s[0]=='s' && s[1]=='o' && s[2]=='i' && s[3]=='l')
      A[e][0]=1, A[e][1]=1;
    if (s[0]=='a' && s[1]=='l' && s[2]=='a' && s[3]=='i' && s[4]=='l')
      A[e][0]=1, A[e][1]=2;
    if (s[0]=='r' && s[1]=='t' && s[2]=='e')
    {
      //cerr<<"!!!!"<<endl;
      A[e][0]=2, A[e][1]=1;
    }
    if (s[0]=='a' && s[1]=='r' && s[2]=='t' && s[3]=='e')
      A[e][0]=2, A[e][1]=2;
    if (s[0]=='s' && s[1]=='i' && s[2]=='t' && s[3]=='i' && s[4]=='n' && s[5]=='i')
      A[e][0]=3, A[e][1]=1;
    if (s[0]=='s' && s[1]=='e' && s[2]=='t' && s[3]=='i' && s[4]=='n' && s[5]=='i')
      A[e][0]=3, A[e][1]=2;
    //cerr<<A[e][0]<<" "<<A[e][1]<<endl;
    if (A[e][0]==0)
    {
      puts("NO");
      return 0;
    }
    e++;
  }  
  if (e==1)
  {
    puts("YES");
    return 0;
  }
  for (i=0; i<e-1; i++)
    if (A[i][1]!=A[i+1][1])
    {
      puts("NO");
      return 0;
    }
  j=0;
  while (j<e && A[j][0]!=2)
    j++;
  if (j==e)
  {
    puts("NO");
    return 0;
  }
  for (i=0; i<e; i++)
    if ((i<j && A[i][0]!=1) || (i>j && A[i][0]!=3))
    {
      puts("NO");
      return 0;
    }
  puts("YES");
  return 0;
}