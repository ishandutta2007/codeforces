#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 150500;

vector <int> V;
int p[MAX];
int n;
set <P> S;
int brok = 0;
int jelok[MAX];

int Ok(int poz)
{
  if (!(poz % 2))
    return p[poz] < p[poz + 1];
  return p[poz] > p[poz + 1];
}

void Makni(int poz)
{
  brok -= jelok[poz];
  jelok[poz] = 0;
}

void Stavi(int poz)
{
  brok -= jelok[poz];
  jelok[poz] = Ok(poz);
  brok += jelok[poz];
}

void Prom(int a, int b)
{
  for (int i=-1; i<=0; i++)
    if (a + i >= 0 && a + i < n - 1)
      Makni(a + i);

  for (int i=-1; i<=0; i++)
    if (b + i >= 0 && b + i < n - 1)
      Makni(b + i);

  swap(p[a], p[b]);

  for (int i=-1; i<=0; i++)
    if (a + i >= 0 && a + i < n - 1)
      Stavi(a + i);

  for (int i=-1; i<=0; i++)
    if (b + i >= 0 && b + i < n - 1)
      Stavi(b + i);
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<n-1; i++) {
    jelok[i] = Ok(i);
    if (!Ok(i)) {
      V.push_back(i);
      V.push_back(i + 1);
    }
    else
      brok++;
  }

  if ((int) V.size() > 10)
    printf("0\n");
  else {
    for (int i=0; i<(int) V.size(); i++) {
      for (int j=0; j<n; j++) {
        Prom(V[i], j);
        if (brok == n - 1)
          S.insert(P(min(V[i], j), max(V[i], j)));

        Prom(V[i], j);
      }
    }

    printf("%d\n", (int) S.size());
  }

  return 0;
}