#include <cstdio>
#include <ctime>
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

const int MAX = 1<<18;
const double TL = 0.95;

int val[MAX];
int pise[MAX];
P par[MAX];
P p[MAX];
vector <int> Kr;
int n;

int nevalja(int poz)
{
  return (pise[poz] + pise[(poz+1) % (2*n)] + pise[(poz + 2) % (2*n)]) % 3 == 0;
}

void pogledaj(int poz)
{
  for (int i=poz-2; i<=poz; i++)
    if (nevalja((i+2*n) % (2*n)))
      Kr.push_back((i+2*n) % (2*n));
}

void gen()
{
  n = rand() % 2 + 3;
  int per[20];
  REP(i, 2*n)
    per[i] = i;
  random_shuffle(per, per + 2*n);

  REP(i, n)
    par[i] = P(per[2*i], per[2*i+1]);
}

int main()
{
  scanf("%d", &n);

  REP(i, n) {
    scanf("%d%d", &par[i].X, &par[i].Y); par[i].X--; par[i].Y--;
    p[par[i].X] = P(i, 0);
    p[par[i].Y] = P(i, 1);

    int st = 0;
    pise[par[i].X] = st ^ 0;
    pise[par[i].Y] = st ^ 1;
  }

  REP(i, 2*n)
    if (nevalja(i))
      Kr.push_back(i);

  for (; !Kr.empty(); ) {
    if ((double) clock() / CLOCKS_PER_SEC > TL) {
      printf("-1\n");
      return 0;
    }

    int poz = Kr.back();
    Kr.pop_back();

    if (!nevalja(poz)) continue;
    int tmp = rand() % 3;

    poz = (tmp + poz) % (2*n);
    int ind = p[poz].X;
    int drugi = par[ind].X ^ par[ind].Y ^ poz;

    pise[poz] ^= 1;
    pise[drugi] ^= 1;

    pogledaj(poz);
    pogledaj(drugi);
  }

  REP(i, n)
    printf("%d %d\n", pise[par[i].X] + 1, pise[par[i].Y] + 1);

  REP(i, 2*n)
    assert(!nevalja(i));

  return 0;
}