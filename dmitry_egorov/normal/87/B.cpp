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

set <string> A;
map <string, pair<bool,int> > B;

int main()
{
  char s[20];
  pair<bool,int> res, tmp;
  string l, m, z;
  int t, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  A.insert("void"), A.insert("errtype");
  B["void"]=make_pair(0,0), B["errtype"]=make_pair(1,0);
  for (scanf("%d", &t); t>0; t--)
  {
    scanf(" %s", &s);
    if (s[4]=='o')
    {
      cin>>m;
      res=make_pair(0,0);
      l.clear(), i=0;
      while (m[i]=='&')
        res.second--, i++;
      while (m[i]!='*' && i<(int)m.length())
        l.pb(m[i]), i++;
      while (m[i]=='*')
        res.second++, i++;
      if (i<(int)m.length())
      {
        puts("errtype");
        continue;
      }
      if (A.count(l)==0)
      {
        puts("errtype");
        continue;
      }
      tmp=B[l];
      res.first=tmp.first;
      res.second+=tmp.second;
      if (res.second<0)
        res.first=1;
      if (res.first)
        puts("errtype");
      else
      {
        printf("void");
        for (i=0; i<res.second; i++)
          printf("*");
        printf("\n");
      }
    }
    else
    {
      cin>>l>>m;
      if (A.count(m)==0)
        A.insert(m);
      res=make_pair(0,0);
      z.clear(), i=0;
      while (l[i]=='&')
        res.second--, i++;
      while (l[i]!='*' && i<(int)l.length())
        z.pb(l[i]), i++;
      while (l[i]=='*')
        res.second++, i++;
      if (i<(int)l.length())
      {
        B[m]=make_pair(1,0);
        continue;
      }
      if (A.count(z)==1)
        tmp=B[z];
      else
        tmp=make_pair(1,0);
      if (tmp.first)
        res.first=1;
      res.second+=tmp.second;
      if (res.second<0 || res.first==1)
        res=make_pair(1,0);
      B[m]=res;
      //cerr<<m<<" "<<res.first<<" "<<res.second<<endl;
    }
  }
  return 0;
}