#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 300500;

vector <int> Komp[MAX];
set <int> Rootovi;
int root[MAX];
map <int, int> M[MAX];

void Nope()
{
  printf("impossible\n");
  exit(0);
}

int Merge(int a, int b)
{
  a = root[a];
  b = root[b];
  if (a == b)
    return 0;

  if (Komp[a].size() < Komp[b].size())
    swap(a, b);

  for (auto it : Komp[b]) {
    Komp[a].push_back(it);
    root[it] = a;
  }
  vector <int>().swap(Komp[b]);

  Rootovi.erase(b);
  return 1;
}

int Moze(int node, int komp)
{
  for (auto it : Komp[komp])
    if (!M[node][it])
      return 1;
  return 0;
}

int main()
{
  int n, m, k, nema1=0;

  scanf("%d%d%d", &n, &m, &k);
  for (int i=0; i<n; i++) {
    if (i)
      Rootovi.insert(i);
    root[i] = i;
    Komp[i].push_back(i);
  }

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    if (a > b)
      swap(a, b);

    if (!a)
      nema1++;

    M[a][b] = 1;
    M[b][a] = 1;
  }

  if (n - 1 - nema1 < k)
    Nope();

  for (int i=1; i<n; i++) {
    for (set <int> :: iterator it = Rootovi.begin(); it != Rootovi.end();) {
      if (root[i] == *it) {
        it++;
        continue;
      }

      if (Moze(i, *it)) {
        int tmp = *it;
        Merge(i, tmp);
        it = Rootovi.lower_bound(tmp + 1);
      }
      else
        it++;
    }
  }

  if ((int) Rootovi.size() > k)
    Nope();

  for (auto it : Rootovi)
    if (!Moze(0, it))
      Nope();

  printf("possible\n");

  return 0;
}