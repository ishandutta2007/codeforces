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

ll f[500];

int main()
{
  ll n;
  scanf("%lld", &n);

  f[0] = 1;
  f[1] = 2;

  for (int i=2; i; i++) {
    f[i] = f[i-1] + f[i-2];
    if (f[i] > n) {
      printf("%d\n", i-1);
      return 0;
    }
  }

  return 0;
}