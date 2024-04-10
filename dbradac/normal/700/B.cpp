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

const int MAX = 1<<18;

vector <int> V[MAX];
int bitan[MAX];
int n, k;
ll rje = 0;

int Sub(int node, int prosli)
{
  int ret = bitan[node];

  for (auto it : V[node])
    if (it != prosli)
      ret += Sub(it, node);

  if (node)
    rje += min(ret, 2 * k - ret);

  return ret;
}

int main()
{
  scanf("%d%d", &n, &k);

  for (int i=0; i<2*k; i++) {
    int tmp;
    scanf("%d", &tmp); tmp--;
    bitan[tmp] = 1;
  }

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  Sub(0, -1);
  printf("%lld\n", rje);

  return 0;
}