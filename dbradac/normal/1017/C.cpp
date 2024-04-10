#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

int main()
{
  int n;
  scanf("%d", &n);

  int tmp = (int) (sqrt(n));

  REP(i, tmp+2) {
    int poc = i*tmp + 1;
    int kraj = poc + tmp - 1;
    for (int j=kraj; j>=poc; j--)
      if (j <= n) printf("%d ", j);
  }
  printf("\n");

  return 0;
}