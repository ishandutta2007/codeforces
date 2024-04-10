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

const int MAX = 1<<17, MAXK = 42, INF = 1e9;

vector <int> V[MAX];
int kol[MAXK], ost[MAXK];
vector <int> Gdje[MAX];

int Ubaci(int x, int vel)
{
  if (x == -1)
    return 0;

  for (int i=2; i<=vel; i++)
    if (!(vel % i))
      if (ost[i] != -1 && ost[i] != (x % i))
        return 0;

  for (int i=2; i<=vel; i++)
    if (!(vel % i)) {
      if (!kol[i])
        ost[i] = x % i;
      kol[i]++;
    }

  return 1;
}

void Makni(int x, int vel)
{
  assert(x != -1);
  
  for (int i=2; i<=vel; i++) {
    if (!(vel % i)) {
      kol[i]--;
      if (!kol[i])
        ost[i] = -1;
    }
  }
}

int main()
{
  int n, m;

  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++) {
    int k;
    scanf("%d", &k);
    for (int j=0; j<k; j++) {
      int tmp;
      scanf("%d", &tmp);
      V[i].push_back(tmp);
      Gdje[tmp].push_back(i);
    }
  }

  for (int i=1; i<=m; i++) {
    memset(kol, 0, sizeof kol);
    memset(ost, -1, sizeof ost);

    int dokle = 0;
    int mx = 0;

    for (auto it : Gdje[i]) {
      dokle = max(dokle, it);
      for (; dokle < n; ) {
        int poz = -1;
        for (int j=0; j<(int) V[dokle].size(); j++)
          if (V[dokle][j] == i)
            poz = j;

        if (!Ubaci(poz, (int) V[dokle].size()))
          break;
        dokle++;
      }

      mx = max(mx, dokle - it);

      int poz = -1;
      for (int j=0; j<(int) V[it].size(); j++)
        if (V[it][j] == i)
          poz = j;

      Makni(poz, (int) V[it].size());
    }

    printf("%d\n", mx);
  }

  return 0;
}