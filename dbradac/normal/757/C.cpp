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

const int MOD = 1e9 + 7;
const int MAX = 1<<20;

int getr()
{
  return (rand() << 15) + rand();
}

int mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

P hs[MAX];
P val[MAX];
vector <int> V[MAX];
int fak[MAX];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  REP(i, n) {
    val[i] = {getr(), getr()};

    int k;
    scanf("%d", &k);
    REP(j, k) {
      int x;
      scanf("%d", &x); x--;
      hs[x].X += val[i].X;
      hs[x].Y += val[i].Y;
    }
  }

  fak[0] = 1;
  FOR(i, 1, MAX)
    fak[i] = mul(i, fak[i-1]);

  sort(hs, hs + m);
  int rje = 1;
  for (int i=0; i<m; ) {
    int j = i;
    for (; j < m && hs[j] == hs[i]; j++);
    rje = mul(rje, fak[j-i]);
    i = j;
  }

  printf("%d\n", rje);

  return 0;
}