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

const int MAX = 1<<19;

int n;
int a[MAX];
ll rje[MAX];

int pos(int x) {
  return (x + n+n) % n;
}

int check() {
  REP(i, n) if (rje[i] <= 0) return 0;

  REP(i, n)
    if (rje[i] % rje[pos(i+1)] != a[i]) return 0;
  return 1;
}

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);

  int da=1;
  REP(i, n) if (a[i] != 0) da = 0;
  if (da) {
    printf("YES\n");
    REP(i, n) printf("1 ");
    printf("\n");
    return 0;
  }

  int poc = -1;
  REP(i, n) {
    if (a[i] > a[pos(i-1)]) {
      poc = i;
      break;
    }
  }

  if (poc == -1) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");

  rje[poc] = a[poc];
  for (int i=pos(poc-1); i != poc; i=pos(i-1)) {
    ll tmp = a[pos(i-1)] + 1;

    ll slj = rje[pos(i+1)];

    ll dod = a[i] - tmp % slj;
    if (dod < 0) dod += slj;
    tmp += dod;
    if (!tmp) tmp += slj;
    
    rje[i] = tmp;
  }

  assert(check());
  REP(i, n) printf("%lld ", rje[i]);
  printf("\n");

  return 0;
}