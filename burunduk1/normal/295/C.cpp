/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.11
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

typedef long long ll;

const int N = 53;
const int MOD = (int)1e9 + 7;

struct state
{
  int n1, n2, where;

  state() { }
  state( int a, int b, int c ) : n1(a), n2(b), where(c) { }
};

int n, m, n1, n2, f[N][N][2], d[N][N][2], C[N][N];
vector <state> next[N][N][2];
vector <int> w[N][N][2];
int qst, qen;
state q[N * N * 2];

inline void add( int &a, int b )
{
  if ((a += b) >= MOD)
    a -= MOD;
}

int mul( int a, int b )
{
  return (ll)a * b % MOD;
}

inline int sum( int a, int b )
{
  add(a, b);
  return a;
}

int main()
{
  scanf("%d%d", &n, &m), m /= 50;
  forn(i, n)
  {
    int a;
    scanf("%d", &a);
    (a == 50 ? n1 : n2)++;
  }
  C[0][0] = 1;
  forn(i, N - 1)
    forn(j, N - 1)
      add(C[i + 1][j + 1], C[i][j]), add(C[i + 1][j], C[i][j]);
  #define GET(mas, s) mas[s.n1][s.n2][s.where]
  forn(i, n1 + 1)               
    forn(j, n2 + 1)
    {
      forn(i1, i + 1)
        forn(j1, j + 1)
          if (i1 + j1 && i1 + 2 * j1 <= m)
          {
            next[i][j][0].pb(state(i - i1, j - j1, 1));
            w[i][j][0].pb(mul(C[i][i1], C[j][j1]));
          }
      forn(i1, n1 - i + 1)
        forn(j1, n2 - j + 1)
          if (i1 + j1 && i1 + 2 * j1 <= m)
          {
            next[i][j][1].pb(state(i + i1, j + j1, 0));
            w[i][j][1].pb(mul(C[n1 - i][i1], C[n2 - j][j1]));
          }
    }

  memset(d, -1, sizeof(d));
  q[qen++] = state(n1, n2, 0);
  GET(d, q[0]) = 0;
  GET(f, q[0]) = 1;
  while (qst < qen)
  {
    state s = q[qst++];
    forn(e, GET(next, s).size())
    {
      state to = GET(next, s)[e];
      if (GET(d, to) == -1)
        GET(d, to) = GET(d, s) + 1, q[qen++] = to;
    }
  }
  forn(i, qen)
  {                                                           
    state s = q[i];
    forn(e, GET(next, s).size())
    {
      state to = GET(next, s)[e];
      if (GET(d, to) == GET(d, s) + 1)
      {
        //printf("[%d,%d,%d] += [%d,%d,%d] * w = %d * %d\n", to.n1, to.n2, to.where, s.n1, s.n2, s.where, GET(f, s), GET(w, s)[e]);
        add(GET(f, to), mul(GET(f, s), GET(w, s)[e]));
      }
    }
  }
  printf("%d\n%d\n", d[0][0][1], f[0][0][1]);
  return 0;
}