#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

ll sum, x;
ll dp[100][2];

ll Rek(int poz, int prek)
{
  if (dp[poz][prek] != -1)
    return dp[poz][prek];

  if (poz >= 50)
    return !prek;

  ll ret=0;

  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      int tx = i ^ j, ts = i + j + prek;
      if (tx != (x >> poz & 1) || (ts % 2) != (sum >> poz & 1))
        continue;

      ret += Rek(poz + 1, ts / 2);
    }
  }

  return dp[poz][prek] = ret;
}

int main()
{
  memset(dp, -1, sizeof dp);

  scanf("%lld%lld", &sum, &x);

  ll rje = Rek(0, 0);
  if (sum == x)
    rje -= 2;

  printf("%lld\n", rje);

  return 0;
}