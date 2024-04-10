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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int rje(int x)
{
  printf("%d\n", x);
  exit(0);
}

int pr(int x)
{
  for (int i=2; i*i<=x; i++)
    if (!(x % i)) return 0;
  return 1;
}

int main()
{
  int n;
  scanf("%d", &n);

  if (n == 2)
    rje(1);
  else if (n == 3)
    rje(1);
  else if (n == 4)
    rje(2);
  else if (n == 5)
    rje(1);

  if (pr(n))
    rje(1);

  if (n % 2) {
    if (pr(n-2))
      rje(2);
    rje(3);
  }
  rje(2);

  return 0;
}