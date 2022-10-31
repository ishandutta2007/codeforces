#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1<<18;

int p[MAX];
int maxx[200][MAX];
int ind[MAX], br=0; //neki gcd na kojoj je poz
int n;
int nemoze[MAX], kolko[MAX], pref[MAX];
vector <int> Gc[MAX];

int gcd(int a, int b)
{
  if (!b)
    return a;
  return gcd(b, a % b);
}

int Mod(int x)
{
  if (x >= n)
    return x - n;
  return x;
}

void Calc1(int poz, int vel)
{
  for (int i=0; i<vel; i++) {
    maxx[poz][i] = p[i];
    for (int j=Mod(i+vel); j!=i; j = Mod(j + vel))
      maxx[poz][i] = max(maxx[poz][i], p[j]);
  }
}

void CalcMax()
{
  for (int i=1; i<=n; i++)
    if (!(n % i)) {
      ind[i] = br++;
      Calc1(ind[i], i);
    }
}

ll Rijesi(int gc)
{
  memset(nemoze, 0, sizeof nemoze);
  memset(kolko, 0, sizeof kolko);
  memset(pref, 0, sizeof pref);

  int prvi = -1;
  for (int i=0; i<n; i++) 
    if (maxx[ind[gc]][i%gc] > p[i]) {      
      nemoze[i] = 1;
      if (prvi == -1)
        prvi = i;
    }

  if (prvi == -1) {
    for (int i=0; i<n; i++)
      kolko[i] = n;
  }
  else {
    int zad=0;
    for (int i=0; i<n; i++) {
      if (nemoze[i]) {
        for (int j=zad; j<=i; j++)
          kolko[j] = i - j;

        zad = i + 1;
      }
    }

    for (int i=zad; i<n; i++)
      kolko[i] = n - i + prvi;
  }
  
  for (int i=0; i<(int) Gc[gc].size(); i++)
    pref[Gc[gc][i]]++;

  for (int i=1; i<MAX; i++)
    pref[i] += pref[i-1];
  
  ll ret=0;
  for (int i=0; i<n; i++)
    ret += pref[kolko[i]];

  return ret;
}

int main()
{
  ll ret=0;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  CalcMax();

  for (int i=1; i<=n; i++)
    Gc[gcd(i, n)].push_back(i);

  for (int i=1; i<n; i++)
    if (!(n % i))
      ret += Rijesi(i);

  cout << ret << endl;

  return 0;
}