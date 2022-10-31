#include <cstdio>
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
  int n, rje=1;
  int sum=0;

  scanf("%d", &n);
  REP(i, 4) {
    int x;
    scanf("%d", &x); sum += x;
  }

  REP(i, n-1) {
    int x;
    int ts=0;
    REP(j, 4) {
      scanf("%d", &x);
      ts += x;
    }

    if (ts > sum) rje++;
  }

  printf("%d\n", rje);

  return 0;
}