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
  int a, b, c, n;
  scanf("%d%d%d%d", &b, &a, &c, &n);
  assert(b < c && b > a);

  int rje = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    if (x > a && x < c) rje++;
  }

  printf("%d\n", rje);
  
  return 0;
}