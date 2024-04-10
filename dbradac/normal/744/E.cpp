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

const int MAXN = 32, MAXS = 1<<17;
const int MOD = 1e9 + 7, H = 3137;

int add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int n, T; //T = sumlen
string s[MAXN];
int len[MAXN];
int poz_s[MAXN];
vector <pair<int, P> > V[MAXS];
int __h[MAXS], pot[MAXS];
int *h = __h + 5;

int geth(int l, int ln)
{  
  return sub(h[l+ln-1], mul(h[l-1], pot[ln]));
}

int ok(int a, int poza, int b)
{
  int kol = min(len[b], len[a] - poza);
  return geth(poz_s[a] + poza, kol) == geth(poz_s[b], kol);
}

int slj_poz(int a, int poza, int b)
{
  if (!ok(a, poza, b)) return -1;
  if (poza + len[b] == len[a]) return T;
  if (poza + len[b] < len[a]) return poz_s[a] + poza + len[b];
  return poz_s[b] + len[a] - poza;
}

char ss[MAXS];
void load()
{
  scanf("%d", &n);
  REP(i, n) {
    scanf(" %s", ss);
    s[i] = ss;
    len[i] = (int) s[i].size();

    poz_s[i] = !i ? 0 : (poz_s[i-1] + len[i-1]);

    REP(j, len[i])
      h[j+poz_s[i]] = add(mul(h[j+poz_s[i]-1], H), s[i][j]);
  }

  T = poz_s[n-1] + len[n-1];
}

void gen()
{
  REP(i, n) V[T].push_back({poz_s[i], P(i, i)});

  REP(a, n) {
    REP(b, n) {
      REP(poza, len[a]) {
	if (!poza && s[a] == s[b]) continue;
	int tmp = slj_poz(a, poza, b);
	
	if (tmp != -1)
	  V[poz_s[a] + poza].push_back({tmp, P(min(a, b), max(a, b))});
      }
    }
  }
}

int bio[MAXS];
int dfs(int node, int l, int r)
{
  if (bio[node]) return bio[node] == 1;
  
  bio[node] = 1;
  for (auto it : V[node])
    if (it.Y.X >= l && it.Y.Y <= r && dfs(it.X, l, r))
      return 1;

  bio[node] = 2;
  return 0;
}

int nema_cik(int l, int r)
{
  memset(bio, 0, sizeof bio);
  REP(i, T+1)
    if (!bio[i] && dfs(i, l, r))
      return 0;

  return 1;
}

void solve()
{
  int rje = 0;
  gen();

  for (int i=0, j=0; i<n; i++) {
    j = max(j, i);
    for (; j<n && nema_cik(i, j); j++);
    rje += j - i;
  }

  printf("%d\n", rje);
}

int main()
{
  pot[0] = 1;
  FOR(i, 1, MAXS) pot[i] = mul(pot[i-1], H);

  load();
  solve();

  return 0;
}