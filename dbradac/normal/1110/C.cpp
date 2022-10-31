#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int a[40];
int main()
{
  a[0] = 0;
  a[1] = 0;
  a[2] = 1;
  a[3] = 1;
  a[4] = 5;
  a[5] = 1;
  a[6] = 21;
  a[7] = 1;
  a[8] = 85;
  a[9] = 73;
  a[10] = 341;
  a[11] = 89;
  a[12] = 1365;
  a[13] = 1;
  a[14] = 5461;
  a[15] = 4681;
  a[16] = 21845;
  a[17] = 1;
  a[18] = 87381;
  a[19] = 1;
  a[20] = 349525;
  a[21] = 299593;
  a[22] = 1398101;
  a[23] = 178481;
  a[24] = 5592405;
  a[25] = 1082401;
  
  int q;
  scanf("%d", &q);  

  REP(i, q) {
    int n;
    scanf("%d", &n);
    int t = 32 - __builtin_clz(n);
    if (n == (1<<t) - 1)
      printf("%d\n", a[t]);
    else
      printf("%d\n", (1<<t) - 1);
  }

  return 0;
}