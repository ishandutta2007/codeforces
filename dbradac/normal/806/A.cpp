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
  int tt;
  scanf("%d", &tt);

  for (; tt--; ) {
    ll a, b, p, q;
    scanf("%lld%lld%lld%lld", &a, &b, &p, &q);
    if (p == q || !p) {
      if (a * q != b * p)
	printf("-1\n");
      else
	printf("0\n");
    }
    else {
      ll k = (b - a + q - p - 1) / (q - p);
      if (k * p < a)	
	k = (a + p - 1) / p;
      if (k * q < b)
	k = (b + q - 1) / q;
      //      if (k * 

      //      TRACE(k _ k*q);
      printf("%lld\n", k*q - b);
    }
  }

  return 0;
}