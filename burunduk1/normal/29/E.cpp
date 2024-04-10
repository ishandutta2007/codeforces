#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

const int maxn = 503;

int n, m;
vector <int> g[maxn];

struct State
{
  int i, j, t;

  State() { }
  State(int i, int j, int t) {
    this->i = i;
    this->j = j;
    this->t = t;
  }
};

inline bool operator == (const State &a, const State &b)
{
  return a.i == b.i && a.j == b.j && a.t == b.t;
}

const int maxq = maxn * maxn * 2;

State p[maxn][maxn][2];
int qst, qen;
State q[maxq];

inline bool contains(const State &s)
{
  return p[s.i][s.j][s.t].t != -1;
}

inline State &P(const State &s)
{
  return p[s.i][s.j][s.t];
}

inline void add(const State &s, const State &prev)
{
  if (contains(s))
    return;
  if (s.t == 0 && s.i == s.j)
    return;
  P(s) = prev;
  q[qen++] = s;
  if (qen == maxq)
    qen = 0;
}

int main()
{
  scanf("%d%d", &n, &m);
  while (m--)
  {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    g[a].pb(b), g[b].pb(a);
  }

  State begin(0, n - 1, 0);
  memset(p, -1, sizeof(p));
  add(begin, begin);
  while (qst != qen)
  {
    State s = q[qst++];
    if (qst == maxq)
      qst = 0;
    if (!s.t)
      forn(i, sz(g[s.i]))
        add(State(g[s.i][i], s.j, 1), s);
    else
      forn(i, sz(g[s.j]))
        add(State(s.i, g[s.j][i], 0), s);
  }

  State end(n - 1, 0, 0);
  if (contains(end))
  {
    vector <State> ans;
    while (true)
    {
      ans.pb(end);
      if (end == begin)
        break;
      end = P(P(end));
    }
    reverse(all(ans));
    printf("%d\n", sz(ans) - 1);
    forn(i, sz(ans))
      printf("%d ", ans[i].i + 1);
    puts("");
    forn(i, sz(ans))
      printf("%d ", ans[i].j + 1);
    puts("");
  }
  else
  {
    puts("-1");
  }
  return 0;
}