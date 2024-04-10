#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<20;

int p[2*MAX];
ll pref[2*MAX];
int skok[MAX];
int n;
int minn, mind;
int rje;

int Poz(int x)
{
  if (x < 1)
    return x + n;
  if (x > n)
    return x - n;
  return x;
}

void PrviSkok(ll vel)
{
  for (int i=1, kraj=1; i<=n; i++) {
    for (;; kraj++) {
      if (kraj == i + n)
        break;
      if (pref[kraj] - pref[i-1] > vel)
        break;
    }

    skok[i] = kraj - i;
  }
}

void MinSkok()
{
  for (int i=1; i<=n; i++) {
    if (skok[i] != skok[Poz(i-1)] - 1) {
      if (skok[i] < minn) {
        minn = skok[i];
        mind = i;
      }
    }
  }
}

void Skaci(int poc)
{
  poc = Poz(poc);

  int preso=0;
  int kolko=0;

  for (int poz=poc; preso < n; ) {
    preso += skok[poz];
    kolko++;
    poz = Poz(poz + skok[poz]);
  }

  rje = min(rje, kolko);
}

int main()
{
  int q;

  scanf("%d%d", &n, &q);
  
  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    p[n+i] = p[i];
  }

  for (int i=1; i<=2*n; i++)
    pref[i] = pref[i-1] + p[Poz(i)];

  for (int i=0; i<q; i++) {
    minn = MAX;
    rje = MAX;
    ll vel;

    cin >> vel;
    PrviSkok(vel);
    MinSkok();

    for (int j=mind; j<mind + skok[mind]; j++)
      Skaci(j);

    printf("%d\n", rje);
  }

  return 0;
}