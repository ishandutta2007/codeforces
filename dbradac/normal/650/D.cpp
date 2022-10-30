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

const int MAX = 400100, MOD = 1e9 + 7, INF = 0x3f3f3f3f;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int p[MAX];
int najdulji;
int n, q;
int lnac[MAX], rnac[MAX], lmax[MAX], rmax[MAX];
P proml[MAX], promr[MAX];
int lisl[MAX], lisr[MAX];
vector <P> Pref[MAX];
int lis[MAX];
int mozemax[MAX];
int rje[MAX];
vector <P> Q[MAX];

void GenPref(int polje[MAX], int koji[MAX], P prom[MAX])
{
  memset(lis, INF, sizeof lis);  
  for (int i=0; i<MAX; i++)
    Pref[i].clear();

  Pref[0].push_back(P(-INF, 1));
  lis[0] = -INF;

  for (int i=0; i<n; i++) {
    int lo = lower_bound(lis, lis + n + 1, p[i]) - lis - 1;

    koji[i] = lo;
    prom[i] = P(lo + 1, lis[lo+1]);
    lis[lo+1] = p[i];

    auto tmp = lower_bound(Pref[lo].begin(), Pref[lo].end(), P(p[i], -INF), greater<P>());      
    polje[i] = Pref[lo].back().Y;

    if (tmp != Pref[lo].begin()) {
      tmp--;
      polje[i] = Sub(polje[i], tmp->Y);
    }

    int dod = polje[i];
    if (Pref[lo+1].size())
      dod = Add(dod, Pref[lo+1].back().Y);

    Pref[lo+1].push_back(P(p[i], dod));
  }
}


int main()
{
  scanf("%d%d", &n, &q);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  GenPref(lnac, lmax, proml);
  for (int i=0; i<n; i++)
    p[i] = -p[i];
  reverse(p, p + n);

  int uknac=0;
  for (int i=n; i>=0; i--)
    if (lis[i] != INF) {
      najdulji = i;
      uknac = Pref[i].back().Y;
      break;
    }

  GenPref(rnac, rmax, promr);

  reverse(rnac, rnac + n);
  reverse(rmax, rmax + n);
  reverse(promr, promr + n);
  reverse(p, p + n);
  for (int i=0; i<n; i++) {
    p[i] = -p[i];
    promr[i].Y = -promr[i].Y;
  }

  memset(lisl, INF, sizeof lisl);
  lisl[0] = -INF;
  memcpy(lisr, lis, sizeof lisr);
  for (int i=0; i<=n; i++)
    lisr[i] = -lisr[i];

  for (int i=0; i<n; i++)
    if (lmax[i] + rmax[i] + 1 < najdulji || Mul(lnac[i], rnac[i]) != uknac)
      mozemax[i] = 1;

  for (int i=0; i<q; i++) {
    int poz, val;
    scanf("%d%d", &poz, &val); poz--;
    Q[poz].push_back(P(val, i));
  }
  
  for (int i=0; i<n; i++) {
    lisr[promr[i].X] = promr[i].Y;

    for (auto it : Q[i]) {
      if (mozemax[i])
        rje[it.Y] = najdulji;
      else
        rje[it.Y] = najdulji - 1;

      rje[it.Y] = max(rje[it.Y], lower_bound(lisl, lisl + n + 1, it.X) - lisl +
                                 lower_bound(lisr, lisr + n + 1, it.X, greater<int>()) - lisr - 1);
    }

    lisl[proml[i].X] = p[i];
  }

  for (int i=0; i<q; i++)
    printf("%d\n", rje[i]);

  return 0;
}