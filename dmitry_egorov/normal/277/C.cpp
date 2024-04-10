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

set <int> S[2];
pair <int, pair <int, int> > A[2][110000];
int res, E[2];

int main()
{
  int N[2], k;
  int it, i, j, nlen, len, last, id, llast;
  int x1, y1, x2, y2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &N[0], &N[1], &k);
  res^=((N[0]-1)%2)*N[1];
  res^=((N[1]-1)%2)*N[0];
  for (i=0; i<k; i++)
  {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1==x2)
      A[0][E[0]++]=mp(x1,mp(min(y1,y2),max(y1,y2)));
    else
      A[1][E[1]++]=mp(y1,mp(min(x1,x2),max(x1,x2)));
  }
  for (it=0; it<2; it++)
  {
    sort(A[it],A[it]+E[it]);
    i=0;
    while (i<E[it])
    {
      //cerr<<it<<" "<<i<<" "<<E[it]<<endl;
      res^=N[it^1], last=0, len=0, id=A[it][i].first;
      j=i;
      while (j<E[it] && A[it][j].first==id)
      {
        if (last<A[it][j].second.first)
          len+=A[it][j].second.first-last;
        last=max(last,A[it][j].second.second), j++;
      }
      len+=N[it^1]-last, S[it].insert(id), i=j, res^=len;
    }
  }
  if (res==0)
  {
    puts("SECOND");
    return 0;
  }
  puts("FIRST");
  for (it=0; it<2; it++)
  {
    i=0;
    while (i<E[it])
    {
      //cerr<<it<<" "<<i<<" "<<E[it]<<endl;
      last=0, len=0, id=A[it][i].first;
      j=i;
      while (j<E[it] && A[it][j].first==id)
      {
        if (last<A[it][j].second.first)
          len+=A[it][j].second.first-last;
        last=max(last,A[it][j].second.second), j++;
      }
      len+=N[it^1]-last;
      if ((len^res)<len)
      {
        nlen=len-(len^res), j=i, len=0, last=0, llast=0;
        while (len<nlen && j<E[it] && A[it][j].first==id)
        {
          if (last<A[it][j].second.first)
            len+=A[it][j].second.first-last, llast=A[it][j].second.first;
          last=max(last,A[it][j].second.second), j++;
        }
        if (len<nlen)
          len+=N[it^1]-last, llast=N[it^1];
        (it==0)?(printf("%d %d %d %d\n", id, 0, id, llast-len+nlen)):(printf("%d %d %d %d\n", 0, id, llast-len+nlen, id));
        return 0;
      }
      i=j;
    }
    if ((N[it^1]^res)>=N[it^1])
      continue;
    for (i=1; i<min(k+10,N[it]); i++)
      if (!S[it].count(i))
      {
        (it==0)?(printf("%d %d %d %d\n", i, 0, i, N[it^1]-(N[it^1]^res))):(printf("%d %d %d %d\n", 0, i, N[it^1]-(N[it^1]^res), i));
        return 0;
      }
  }
  assert(0);
  return 0;
}