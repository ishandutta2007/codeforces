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

const int MAX = 1<<20;

int fen[MAX];

void stavi(int pos, int val)
{
  for (pos+=3; pos < MAX; pos += pos & -pos)
    fen[pos] += val;
}

int vrati(int pos)
{
  int ret = 0;
  for (pos+=3; pos; pos -= pos & -pos)
    ret += fen[pos];

  return ret;
}

int sum(int a, int b)
{
  if (b >= a)
    return vrati(b) - vrati(a-1);
  return vrati(b) + vrati(MAX-5) - vrati(a-1);
}

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  k = min(k, n-k);

  ll sjec = 0;
  int poz = 0;

  REP(i, n) {
    int npoz = (poz + k) % n;
    sjec += sum(poz+1, npoz-1);
    ll V = n + sjec;
    ll E = n + i + 1 + 2 * sjec;
    ll F = 2 - V + E;

    printf("%lld ", F-1);

    stavi(poz, 1);
    stavi(npoz, 1);

    poz = npoz;
  }
  printf("\n");

  return 0;
}