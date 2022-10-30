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
  int n;
  scanf("%d", &n);

  ll val = 2;

  for (int i=2; i<=n+1; i++) {
    ll imam = val / (i - 1);
    ll nakon = (i - 1) * (ll) i * i;
    printf("%lld\n", nakon - imam);
    val = (ll) (i - 1) * (ll) i;  
  }

  return 0;
}