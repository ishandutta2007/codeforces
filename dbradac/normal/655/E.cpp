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

const int MAX = 1<<21, MOD = 1e9 + 7;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

char s[MAX];
int zad[30];
int nac[MAX];
vector <int> V[30];

int main()
{
  int n, k, pocl;

  scanf("%d%d%s", &n, &k, s);
  pocl = (int) strlen(s);

  memset(zad, -1, sizeof zad);
  for (int i=0; i<pocl; i++)
    zad[s[i] - 'a'] = i;

  for (int i=pocl; i<n+pocl; i++) {
    int nov = 0;
    for (int j=0; j<k; j++)
      if (zad[j] < zad[nov])
        nov = j;

    s[i] = char ('a' + nov);
    zad[nov] = i;
  }

  int len = n + pocl;
  memset(zad, -1, sizeof zad);

  int rje = 1;
  for (int i=0; i<len; i++) {
    int c = s[i] - 'a';
    if (zad[c] == -1)
      nac[i] = Add(nac[i], 1);
    
    for (int j=0; j<k; j++)
      for (int l=(int) V[j].size()-1; l>=0; l--) {
        if (V[j][l] < zad[c])
          break;
        nac[i] = Add(nac[i], nac[V[j][l]]);
      }

    zad[c] = i;
    V[c].push_back(i);

    rje = Add(rje, nac[i]);
  }

  printf("%d\n", rje);

  return 0;
}