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

long long k, n, A[110000];
set <long long> S;

int main()
{
  int i, x;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>n>>k;
  if (k==1)
  {
    cout<<n<<endl;
    return 0;
  }
  for (i=0; i<n; i++)
    scanf("%d", &x), A[i]=x, S.insert(x);
  sort(A,A+n);
  for (i=0; i<n; i++)
    if (S.count(A[i])==1 && S.count(A[i]*k)==1)
      S.erase(A[i]*k);
  printf("%d\n", (int)S.size());
  return 0;
}