#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 500005;

int sito[MAX];
int gore[MAX];
int p[MAX];
int kolko[MAX];

void Eratosten()
{
  int brp=0;
  for (int i=2; i<MAX; i++)
    if (!sito[i]) {
      brp++;
      for (int j=i; j<MAX; j+=i)
        sito[j] = i;
    }
}

vector <int> Prosti(int x)
{
  vector <int> T;

  for (; x > 1; ) {
    int tmp = sito[x];
    for (; !(x % tmp); x /= tmp);
    T.push_back(tmp);
  }

  return T;
}

int Submask(vector <int> &V, int mask)
{
  int ret = 1;
  vector <int> T;

  for (int i=0; i<(int) V.size(); i++)
    if ((1<<i) & mask)
      ret *= V[i];

  return ret;
}

void Dodaj(vector <int> V, int st)
{
  for (int i=0; i<(1<<(int) V.size()); i++)
    kolko[Submask(V, i)] += st;
}

int Fui(vector <int> V)
{
  int ret=0;

  for (int i=0; i<(1<<(int) V.size()); i++) {
    int st = 1;
    if (__builtin_popcount(i) % 2)
      st = -1;

    ret += st * kolko[Submask(V, i)];
  }

  return ret;
}

int main()
{
  Eratosten();

  int n, q;
  ll rje=0;
  
  scanf("%d%d", &n, &q);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<q; i++) {
    int tmp;
    scanf("%d", &tmp); tmp--;
    vector <int> V = Prosti(p[tmp]);
  
    if (gore[tmp]) {
      Dodaj(V, -1);
      rje -= Fui(V);
    }
    else {
      rje += Fui(V);
      Dodaj(V, 1);
    }

    gore[tmp] ^= 1;
    printf("%I64d\n", rje);
  }

  return 0;
}