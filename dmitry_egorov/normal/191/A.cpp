#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <ctime>
#include <stack>

#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define pb push_back
#define mp make_pair
#define zero(a) memset (a, 0, sizeof(a))



#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int inf = (int)1e9;
int n, D[26][26], res, len;
char s[12];

int main (void)
{
  int i, x, y, j;
  #ifdef LOCAL
    freopen (".in", "r", stdin);
    freopen (".out", "w", stdout);
  #endif                              
  scanf("%d ", &n);
  for (i=0; i<26; i++)
    for (j=0; j<26; j++)
      D[i][j]=-inf;
  for (i=0; i<n; i++)
  {
    gets(s), len=strlen(s), x=(int)(s[0]-'a'), y=(int)(s[len-1]-'a');
//    cerr<<len<<" "<<x<<" "<<y<<endl;
    for (j=0; j<26; j++)
      D[j][y]=max(D[j][y],D[j][x]+len);
    D[x][y]=max(D[x][y],len);
  }
  for (i=0; i<26; i++)
    res=max(res,D[i][i]);
  printf("%d\n", res);
  return 0;
}