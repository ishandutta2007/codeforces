#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

const int H = 1e9 + 7, MOD = 1e9 + 9, MAX = 600005;

typedef long long ll;

int Mul(int a, int b)
{
  return ((ll) a * b) % MOD;
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

int Sub(int a, int b)
{
  return (a - b + MOD) % MOD;
}

void Stavi(int fen[MAX], int pos, int val)
{
  for (pos++; pos < MAX; pos += pos & -pos)
    fen[pos] = Add(fen[pos], val);
}

int Vrati(int fen[MAX], int pos)
{
  int ret=0;
  for (pos++; pos; pos -= pos & -pos)
    ret = Add(ret, fen[pos]);

  return ret;
}

int raste[MAX], pada[MAX];
int p[MAX];
int pot[MAX];

int main()
{
  pot[0] = 1;
  for (int i=1; i<MAX; i++)
    pot[i] = Mul(pot[i-1], H);

  int n, rje = 0;

  scanf("%d", &n);

  for (int i=1; i<=n; i++)
    scanf("%d", &p[i]);

  for (int i=1; i<=n; i++) {
    int lgran = 1, rgran = n;

    if (p[i] - 1 < n - p[i])
      rgran = 2 * p[i] - 1;
    else
      lgran = 2 * p[i] - n;

    int hr = Sub(Vrati(raste, rgran), Vrati(raste, lgran-1));
    int hp = Sub(Vrati(pada, rgran), Vrati(pada, lgran-1));
  
    hr = Mul(hr, pot[MAX-rgran-lgran]);
    if (hr != hp)
      rje = 1;

    Stavi(raste, p[i], pot[p[i]]);
    Stavi(pada, p[i], pot[MAX-p[i]]);
  }

  if (!rje)
    printf("NO\n");
  else
    printf("YES\n");

  return 0;
}