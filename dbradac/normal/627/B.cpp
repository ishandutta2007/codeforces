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

const int MAX = 401000;

ll fena[MAX], fenb[MAX];

void Stavi(ll fen[MAX], int pos, int val)
{
  for (pos++; pos < MAX; pos += pos & -pos)
    fen[pos] += val;
}

ll Vrati(ll fen[MAX], int pos)
{
  ll ret=0;
  for (pos++; pos; pos -= pos & -pos)
    ret += fen[pos];
  return ret;
}

int n, per, a, b, q;
ll p[MAX];

int main()
{
  scanf("%d%d%d%d%d", &n, &per, &a, &b, &q);

  for (int i=0; i<q; i++) {
    int st;
    scanf("%d", &st);

    if (st == 1) {
      int poz, val;
      scanf("%d%d", &poz, &val);
      Stavi(fena, poz, -min(a, (int) p[poz]));
      Stavi(fenb, poz, -min(b, (int) p[poz]));
      p[poz] += val;

      Stavi(fena, poz, min(a, (int) p[poz]));
      Stavi(fenb, poz, min(b, (int) p[poz]));
    }
    else {
      int poz;
      scanf("%d", &poz);
      printf("%lld\n", Vrati(fenb, poz - 1) + Vrati(fena, n) - Vrati(fena, poz + per - 1));
    }
  }


  return 0;
}