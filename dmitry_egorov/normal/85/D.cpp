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
#include <utility>

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

long long A[110000], e;
map <long long,int> C;
char s[110000][6];
long long X[110000];
long long tree[(1<<18)][5];
int tree2[(1<<18)];

int main() {
  int i, t, n, v;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf(" %s", s[i]);
    if (s[i][0]!='s')
    {
      scanf("%I64d", &X[i]);
      if (s[i][0]=='a')
        A[e]=X[i], e++;
    }
  }
  sort(A,A+e);
  e=unique(A,A+e)-A;
  for (i=0; i<e; i++)
    C[A[i]]=i;
  for (t=0; t<n; t++)
  {
    if (s[t][0]=='a')
    {
      v=C[X[t]]+(1<<17);
      tree2[v]++, tree[v][0]+=X[t], v/=2;
      while (v>=1)
      {
        tree2[v]++;
        for (i=0; i<5; i++)
          tree[v][i]=tree[2*v][i]+tree[2*v+1][(5+i-(tree2[2*v]%5))%5];
        v/=2;
      }
      continue;
    }
    if (s[t][0]=='s')
    {
      printf("%I64d\n", tree[1][2]);
      continue;
    }
    if (s[t][0]=='d')
    {
      v=C[X[t]]+(1<<17);
      tree2[v]--, tree[v][0]-=X[t], v/=2;
      while (v>=1)
      {
        tree2[v]--;
        for (i=0; i<5; i++)
          tree[v][i]=tree[2*v][i]+tree[2*v+1][(5+i-(tree2[2*v]%5))%5];
        v/=2;
      }
    }
  }
  return 0;
}