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

const int MAX = 10005;

void Nope()
{
  printf("unfair\n");
  exit(0);
}

struct str {
  int kol;
  vector <int> T;
};

P q[MAX];
vector <str> V;

int Pod(int x)
{
  if (x < 0)
    return -1;
  return x / 5;
}

void Dodaj(int lo, int hi, int kol)
{
  if (kol < 0)
    Nope();

  str nov = {kol, vector<int> (5, 0) };

  for (int i=0; i<5; i++)
    nov.T[i] = Pod(hi - i) - Pod(lo - i - 1);

  V.push_back(nov);
}

void Moze(int mask, int kol)
{
  for (int i=0; i<(int) V.size(); i++) {
    int tmp = 0;
    for (int j=0; j<5; j++)
      if (mask & (1<<j))
        tmp += V[i].T[j];

    tmp = min(tmp, V[i].kol);
    kol -= tmp;
  }

  if (kol > 0)
    Nope();
}

int main()
{
  int n, m, brq;

  scanf("%d%d%d", &n, &m, &brq);

  for (int i=0; i<brq; i++)
    scanf("%d%d", &q[i].X, &q[i].Y);
  
  q[brq++] = P(m, n);
  q[brq++] = P(0, 0);
  sort(q, q + brq);

  for (int i=0; i<brq; i++) {
    if (i && (q[i].X == q[i-1].X && q[i].Y != q[i-1].Y))
      Nope();

    if (i)
      Dodaj(q[i-1].X + 1, q[i].X, q[i].Y - q[i-1].Y);
  }

  for (int i=1; i<(1<<5); i++)
    Moze(i, n / 5 * __builtin_popcount(i));

  printf("fair\n");

  return 0;
}