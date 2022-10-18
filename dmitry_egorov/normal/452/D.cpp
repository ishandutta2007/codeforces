#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;
                         
multiset<int> S1, S2, S3;

int main()
{
  int n, res=0, n1, n2, n3, t1, t2, t3;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d%d%d%d%d", &n, &n1, &n2, &n3, &t1, &t2, &t3);
  for (int i=0; i<n1; i++)
    S1.insert(0);
  for (int i=0; i<n2; i++)
    S2.insert(0);
  for (int i=0; i<n3; i++)
    S3.insert(0);
  while (n)
  {
    res=max(max(res,*S1.begin()),max(*S2.begin()-t1,*S3.begin()-t1-t2));
    n--;
    S1.erase(S1.begin()), S1.insert(res+t1);
    S2.erase(S2.begin()), S2.insert(res+t1+t2);
    S3.erase(S3.begin()), S3.insert(res+t1+t2+t3);
  }
  printf("%d\n", res+t1+t2+t3); 
  TIMESTAMP(end);
  return 0;
}