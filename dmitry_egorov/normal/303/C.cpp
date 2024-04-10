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

//vector <int> V[1001000];
int Cnt[1001000], S[1001000], E[1001000];
int M[5010*5010/2];
int A[6000], n, k, ans;
int P[40], PP[40], e, ee;

int main()
{
  int i, cnt, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  if (n<=k+1)
  {
    puts("1");
    return 0;
  }
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  sort(A,A+n);
  //for (i=0; i<=A[n-1]; i++)
  //  V[i].reserve((A[n-1]*2)/n);
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      Cnt[A[j]-A[i]]++;//V[A[j]-A[i]].pb(A[i]);
  for (i=0; i<=A[n-1]; i++)
    S[i+1]=S[i]+Cnt[i], E[i]=S[i];
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      M[E[A[j]-A[i]]++]=A[i];
  //cerr<<clock()<<endl;
  ans=n-k;
  while (true)
  {
   // cerr<<ans<<endl;
    for (cnt=0, i=ans; i<=A[n-1]; i+=ans)
      cnt+=Cnt[i];//(int)V[i].size(); 
    if (cnt>(k*(k+1))/2)
    {
      ans++;
      continue;
    }
    e=0;
    for (i=ans; i<=A[n-1]; i+=ans)
      for (j=0; j<Cnt[i]; j++)
        P[e++]=M[S[i]+j], P[e++]=M[S[i]+j]+i;
    sort(P,P+e), e=unique(P,P+e)-P;
    for (ee=0, i=0; i<e; i++)
      PP[ee++]=P[i]%ans;
    sort(PP,PP+ee), ee=unique(PP,PP+ee)-PP;
    if (e-ee<=k)
    {
      printf("%d\n", ans);
     // cerr<<clock()<<endl;
      return 0;
    }
  //  cerr<<"!!!!  "<<ans<<endl;
    ans++;
  }
//  cerr<<clock()<<endl;
  return 0;
}