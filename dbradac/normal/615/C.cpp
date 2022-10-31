#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;
#define X first
#define Y second

const int MAX = 2105, MOD = 1e9 + 7, H = 3137;

int lenm, lenv;
char mal[MAX], vel[MAX];
vector <pii> V;

pii Moze(int poz)
{
  pii ret = pii(0, 0);

  for (int i=1; i<=lenm; i++) {
    int j=i;
    for (; j<=lenm; j++)
      if (mal[j] != vel[poz+j-i])
        break;

    ret = max(ret, pii(j - i, i));
  }

  return pii(ret.X + poz, ret.Y);
}

int main() {
  scanf("%s%s", mal + 1, vel + 1);

  lenm = (int) strlen(mal + 1);
  lenv = (int) strlen(vel + 1);

  for (int poz=1; poz<=lenv;) {
    int sw=0;
    pii dokle = Moze(poz);

    reverse(mal + 1, mal + lenm + 1);

    pii tmp = Moze(poz);
    if (tmp > dokle) {
      dokle = tmp;
      sw = 1;
    }

    if (!sw)
      V.push_back(pii(dokle.Y, dokle.Y + dokle.X - poz - 1));
    else
      V.push_back(pii(lenm - dokle.Y + 1, lenm + 2 - (dokle.Y + dokle.X - poz)));

    reverse(mal + 1, mal + lenm + 1);

    if (dokle.X <= poz) {
      printf("-1\n");
      return 0;
    }
    poz = dokle.X;
  }

  printf("%d\n", (int) V.size());
  for (int i=0; i<(int) V.size(); i++)
    printf("%d %d\n", V[i].X, V[i].Y);

  return 0;
}