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

int A[260], C[260];
pair <int,int>  B[260];
char s[110000];

int main()
{
  int i, ans, k, n, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s);
  scanf("%d", &k);
  n=strlen(s);
  k=min(k,n);
  for (i=0; i<n; i++)
    A[(int)s[i]]++;
  for (i=0; i<256; i++)
    B[i]=mp(A[i],i);
  sort(B,B+256);
  k=n-k, i=255, ans=0;
  while (k>0 && ans<30)
  {
    //cerr<<k<<" "<<i<<" "<<B[i].first<<" "<<B[i].second<<endl;
    ans++;
    t=min(k,B[i].first);
    C[B[i].second]=t, k-=t, i--;
  }
  printf("%d\n", ans);
  for (i=0; i<n; i++)
    if (C[(int)s[i]]>0)
      printf("%c", s[i]);
  printf("\n");
  return 0;
}