#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1<<17, MOD = 1000000009;

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Add(int a, int b)
{
  return (a + b) % MOD;
}

map <P, int> M;
set <int> S;
P koor[MAX];
int potpor[MAX];
int poten[MAX];
int done[MAX];

int main()
{
  int n, rez=0;

  scanf("%d", &n);
  
  poten[0] = 1;
  for (int i=1; i<n; i++)
    poten[i] = Mul(poten[i-1], n);

  for (int i=1; i<=n; i++) {
    scanf("%d%d", &koor[i].X, &koor[i].Y);
    M[P(koor[i].X, koor[i].Y)] = i;
  }
  
  for (int i=1; i<=n; i++)
    for (int j=-1; j<=1; j++)
      if (M[P(koor[i].X+j, koor[i].Y-1)])
        potpor[i]++;
  
  for (int i=1; i<=n; i++) {
    int ne = 0;
    for (int j=-1; j<=1; j++) {
      int tmp = M[P(koor[i].X+j, koor[i].Y+1)];
      if (tmp && potpor[tmp] == 1)
        ne = 1;
    }
    if (!ne)
      S.insert(i);
  }

  for (int i=n-1, ind=0; i>=0; i--, ind ^= 1) {
    int tmp;

    if (!ind)
      tmp = *(--S.end());
    else
      tmp = *S.begin();

    S.erase(tmp);
    done[tmp] = 1;
    potpor[tmp] = MOD;
    rez = Add(rez, Mul(tmp-1, poten[i]));

    for (int j=-1; j<=1; j++) {
      P t = P(koor[tmp].X+j, koor[tmp].Y+1);
      if (M[t]) {
        int oz = M[t];
        potpor[oz]--;
        if (potpor[oz] == 1) {
          for (int k=-1; k<=1; k++) {
            int oznovi = M[P(t.X+k, t.Y-1)];
            if (oznovi)
              S.erase(oznovi);
          }
        }
      }
    }

    for (int j=-1; j<=1; j++) {
      P t = P(koor[tmp].X+j, koor[tmp].Y-1);
      if (M[t]) {
        int oz = M[t], ne = 0;
        for (int k=-1; k<=1; k++) {
          int oznovi = M[P(t.X+k, t.Y+1)];
          if (oznovi && potpor[oznovi] == 1)
            ne = 1;
        }
        if (!ne && !done[oz])
          S.insert(oz);
      }
    }
  }

  printf("%d\n", rez);

  return 0;
}