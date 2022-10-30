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

int main()
{
  int n, k;

  scanf("%d%d", &n, &k);
  ll rje = 0;
  
  for (int i=0, iz=n-2; i<k; i++, iz-=2)
    rje += max(0, 2 * iz + 1);
  
  printf("%lld\n", rje);

  return 0;
}