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

long long res=-((long long)1e18);
int A[35][30], B[30], K[30], P[30], n, r, u;
//int cnt, cnt2;

void gen (int lv, int tp)
{
  //cnt2++;
  if (lv%2==u%2)
  {
    long long tmp=0;
    for (int i=0; i<n; i++)
      tmp+=(long long)(A[lv][i]*K[i]); 
    res=max(res,tmp);
  }
  if (lv==u)
  {
    //cnt++;
    return;
  }
  int i;
  for (i=0; i<n; i++)
    A[lv+1][i]=A[lv][P[i]]+r;
  gen(lv+1,0);
  if (tp==0)
  {
    for (i=0; i<n; i++)
      A[lv+1][i]=(A[lv][i]^B[i]);
    gen(lv+1,1);
  }
}

int main()
{
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &n, &u, &r);
  for (i=0; i<n; i++)
    scanf("%d", &A[0][i]);
  for (i=0; i<n; i++)
    scanf("%d", &B[i]);
  for (i=0; i<n; i++)
    scanf("%d", &K[i]);
  for (i=0; i<n; i++)
    scanf("%d", &P[i]), P[i]--;
  gen(0,0);
  //cerr<<cnt<<" "<<cnt2<<endl;
  printf("%I64d\n", res);
  return 0;
}