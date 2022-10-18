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
#define inf ((long long)1e9)
#define pb push_back
#define maxn 210000

using namespace std;

int P[50][210000], e[50], n, k, len;
char s[maxn], l[maxn];

long long f(int j, int lt)
{
  long long ans=inf;
  int l=0, r=e[lt], m; 
  while (r-l>1)
  {
    m=(l+r)/2;
    if (P[lt][m]==j)
      return 0;
    if (P[lt][m]>j)
    {
      r=m;
      continue;
    } 
    if (P[lt][m]<j)
    {
      l=m;
      continue;
    }
  }
  if (l<e[lt])
    ans=min(ans,(long long)abs(P[lt][l]-j));
  if (l+1<e[lt])
    ans=min(ans,(long long)abs(P[lt][l+1]-j));
  if (l>0)
    ans=min(ans,(long long)abs(P[lt][l-1]-j));
  if (ans==inf)
    return len; 
  return ans;
}

int main() {
  long long ans;
  int i, j;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d%d", &n, &k);
  scanf(" %s", s);
  for (i=0; i<k; i++)
    P[(int)(s[i]-'a')][e[(int)(s[i]-'a')]]=i, e[(int)(s[i]-'a')]++;
  for (i=0; i<n; i++)
  {
    scanf(" %s", l);
    len=strlen(l);
    for (j=0, ans=0ll; j<len; j++)
      ans+=f(j,(int)(l[j]-'a'));
    printf("%I64d\n", ans);
  }
  return 0;
}