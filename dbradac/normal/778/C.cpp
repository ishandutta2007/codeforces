#include <set>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 300100, MOD[2] = {(int) (1e9 + 7), (int) (1e9 + 9)}, H[2] = {3137, 10007};

int add(int a, int b, int mod)
{
  a += b;
  if (a >= mod)
    a -= mod;
  return a;
}

int sub(int a, int b, int mod)
{
  a -= b;
  if (a < 0)
    a += mod;
  return a;
}

int mul(int a, int b, int mod)
{
  return (int) (((ll) a * b) % mod);
}

int subt[MAX], dub[MAX];
int n;
vector <P> V[MAX];
int br[MAX];
multiset <P> S;
int ima_dub[MAX];

int ukupno = 0;
void dodaj(P tmp)
{
  if (S.find(tmp) == S.end()) ukupno++;
  S.insert(tmp);
}

void makni(P tmp)
{
  S.erase(S.find(tmp));
  if (S.find(tmp) == S.end()) ukupno--;
}

void load()
{
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    char c;
    scanf("%d%d %c", &a, &b, &c); a--; b--;
    V[a].push_back({b, (int) c});
  }
}

int dfs_sub(int x)
{
  ima_dub[dub[x]]++;
  subt[x] = 1;
  for (auto it : V[x]) {
    dub[it.X] = dub[x] + 1;
    subt[x] += dfs_sub(it.X);
  }
  return subt[x];
}

inline int dodaj_h1(int ind, int val, int c)
{
  return add(mul(val, H[ind], MOD[ind]), c, MOD[ind]);
}

inline P dodaj_h(P val, int c)
{
  return {dodaj_h1(0, val.X, c), dodaj_h1(1, val.Y, c)};
}

void dfs_izbaci(int x, P h)
{
  makni(h);
  for (auto it : V[x])
    dfs_izbaci(it.X, dodaj_h(h, it.Y));
}

void dfs_stavi(int x, P h)
{
  dodaj(h);
  for (auto it : V[x])
    dfs_stavi(it.X, dodaj_h(h, it.Y));
}

void dfs(int x, P h)
{
  pair<int, P> mx = {-1, {-1, -1}};
  for (auto it : V[x])
    mx = max(mx, {subt[it.X], it});

  for (auto it : V[x]) {
    if (it.X != mx.Y.X) {
      dfs(it.X, dodaj_h(h, it.Y));
      dfs_izbaci(it.X, dodaj_h(h, it.Y));
    }
  }

  if (mx.X != -1)
    dfs(mx.Y.X, dodaj_h(h, mx.Y.Y));

  for (auto it : V[x])
    if (it.X != mx.Y.X)
      dfs_stavi(it.X, dodaj_h(h, mx.Y.Y));
  
  dodaj(h);  
  
  if (mx.X != -1)
    br[dub[x]+1] += ukupno - 2;
  
  for (auto it : V[x])
    if (it.X != mx.Y.X) {
      dfs_izbaci(it.X, dodaj_h(h, mx.Y.Y));
      dfs_stavi(it.X, dodaj_h(h, it.Y));
    }
}

void solve()
{
  dfs_sub(0);
  dfs(0, {0, 0});

  P ret = {MAX, MAX};  
  
  FOR(i, 1, MAX)
    ima_dub[i] += ima_dub[i-1];

  FOR(i, 1, MAX)
    ret = min(ret, P(ima_dub[i-1] + br[i], i));

  printf("%d\n%d\n", ret.X, ret.Y);
}

int main()
{
  load();
  solve();
  
  return 0;
}