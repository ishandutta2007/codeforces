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

char s[110000];
int len, cnt0, cnt1, cnt, a, b, e;
string Res[10];

void add ()
{
  if (cnt0<=b)
    Res[e]="11", e++;
  if (cnt1<=a)
    Res[e]="00", e++;
  if (cnt0<=b+1 && cnt1<=a+1)
  {
    if (s[len-1]=='1')
      Res[e]="01", e++;
    else
      Res[e]="10", e++;
  }
}

int main()
{
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s);
  len=strlen(s);
  b=(len-2)/2, a=len-2-b;
  for (i=0; i<len; i++)
  {
    if (s[i]=='0')
      cnt0++;
    if (s[i]=='1')
      cnt1++;
    if (s[i]=='?')
      cnt++;
  }
  if (s[len-1]=='?')
  {
    s[len-1]='0', cnt0++, cnt--;
    add();
    s[len-1]='1', cnt1++, cnt0--;
    add();
  }
  else
    add();
  sort(Res,Res+e);
  e=unique(Res,Res+e)-Res;
  for (i=0; i<e; i++)
    cout<<Res[i]<<endl;
  return 0;
}