#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 1<<18;

ll p[MAX];
set <P> S;

int main()
{
  int n, k, x;
  
  scanf("%d%d%d", &n, &k, &x);

  int kol = 1;
  for (int i=0; i<n; i++) {
    scanf("%lld", &p[i]);
    if (p[i] < 0)
      kol ^= 1;

    S.insert(P(abs(p[i]), i));
  }

  for (; k; k--) {
    P tmp = *S.begin(); S.erase(S.begin());

    if (kol) {
      if (tmp.X < x || p[tmp.Y] == -x)
        kol = 0;

      if (p[tmp.Y] >= 0)
        p[tmp.Y] -= x;
      else
        p[tmp.Y] += x;
    }
    else {
      if (p[tmp.Y] >= 0)
        p[tmp.Y] += x;
      else
        p[tmp.Y] -= x;
    }

    S.insert(P(abs(p[tmp.Y]), tmp.Y));
  }

  for (int i=0; i<n; i++)
    printf("%lld ", p[i]);
  printf("\n");

  return 0;
}