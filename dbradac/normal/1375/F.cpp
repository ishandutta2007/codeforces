#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

void print(ll x) {
  printf("%lld\n", x);
  fflush(stdout);
}

int get() {
  int x;
  scanf("%d", &x);
  if (x <= 0) exit(0);
  return x-1;
}

int main()
{
  ll p[3];
  REP(i, 3) scanf("%lld", &p[i]);

  printf("First\n");
  fflush(stdout);

  ll M = max(p[0], max(p[1], p[2])) + 1;
  print(M);

  int ind = get();
  p[ind] += M;

  ll x = 3ll*p[ind] - p[0] - p[1] - p[2];
  print(x);
  ind = get();
  p[ind] += x;

  sort(p, p+3);
  x = p[1] - p[0];
  print(x);

  return 0;
}