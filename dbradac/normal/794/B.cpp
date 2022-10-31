#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  int n, h;

  scanf("%d%d", &n, &h);

  REP(i, n-1) {
    double x = sqrt((double)(i+1) / n) * h;
    printf("%.10lf ", x);
  }
  printf("\n");
  
  return 0;
}