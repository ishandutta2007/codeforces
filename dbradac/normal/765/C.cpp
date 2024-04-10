#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> P;

void no()
{
  printf("-1\n");
  exit(0);
}

void print(int x)
{
  printf("%d\n", x);
  exit(0);
}

int main()
{
  int k, a, b;
  scanf("%d%d%d", &k, &a, &b);

  if (a < b) swap(a, b);
  if (a + b < k) no();
  if (a % k == 0) print(a / k + b / k);
  if (b < k) no();
  print(a / k + b / k);

  return 0;
}