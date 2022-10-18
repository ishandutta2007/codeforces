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

map <pair<string,int>, pair<string,int> > Prev;
map <pair<string,int>, vector <pair<string,int> > > G;
string cur="";
char s[300];
int e=1, id, len;
vector <pair<string,int> > V;

void write (pair <string,int> str)                                                   
{
  if (str.first!="")
    write(Prev[str]), cout<<str.first;
  printf("/");
}

int main()
{
  int n, i, j;
  bool fl;
  string str;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  G[mp("",0)]=V;
  scanf("%d", &n);
  while (n>0)
  {
    //printf("%d\n", n);
    scanf(" %s", s), n--;
    if (s[0]=='p')
    {
      write(mp(cur,id)), printf("\n");
      continue;
    }
    scanf(" %s", s);
    len=strlen(s), i=0;
    if (s[i]=='/')
      cur="", i++;
    while (i<len)
    {
      if (s[i]=='/')
        i++;
      if (i==len)
        break;
      str="";
      while (s[i]!='/' && i<len)
        str.pb(s[i]), i++;
      //cout<<"!!!!      "<<str<<"   "<<id<<" "<<cur<<endl;
      if (str[0]=='.')
      {
        int tmp=id;
        id=Prev[mp(cur,id)].second, cur=Prev[mp(cur,tmp)].first;
        continue;
      }
      V=G[mp(cur,id)];
      for (fl=0, j=0; j<(int)V.size(); j++)
        if (V[j].first==str)
        {
          cur=str, id=V[j].second, fl=1;
          break;
        }
      if (!fl)
        Prev[mp(str,e)]=mp(cur,id), G[mp(cur,id)].pb(mp(str,e)), cur=str, id=e++, V.clear(), G[mp(cur,id)]=V;
    }
  }
  return 0;
}