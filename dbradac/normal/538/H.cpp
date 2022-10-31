#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;

const int MAX = 100005, INF = 0x3f3f3f3f;

P p[MAX];
P zavint[3];
P prosli[3];
int rje[MAX];
vector <int> V[MAX];
vector <int> R;
int n;

P Presjek(P a, P b)
{
  return P(max(a.X, b.X), min(a.Y, b.Y));
}

int Pase(P a, P b)
{
  P tmp = Presjek(a, b);
  return tmp.X <= tmp.Y;
}

int Dfs(int ind)
{
  int dr = 3 - rje[ind];
  zavint[rje[ind]] = Presjek(zavint[rje[ind]], p[ind]);
  R.push_back(ind);

  for (int i=0; i<(int) V[ind].size(); i++) {
    int nn = V[ind][i];
    if (!rje[nn]) {
      if (!Pase(p[nn], zavint[dr]))
        return 0;
      rje[nn] = dr;
      if (!Dfs(nn))
        return 0;
    }
    else if (rje[nn] != dr)
      return 0;
  }

  return 1;
}

int NapDfs(int ind)
{
  memcpy(prosli, zavint, sizeof prosli);
  R.clear();
  if (Dfs(ind))
    return 1;

  for (int i=0; i<(int) R.size(); i++)
    rje[R[i]] = 0;
  memcpy(zavint, prosli, sizeof zavint);
  return 0;
}

int StaviPoc()
{
  for (int i=0; i<n; i++) {
    if (rje[i])
      continue;

    if (!Pase(p[i], zavint[1]) && !Pase(p[i], zavint[2]))
      return 0;

    for (int j=1; j<=2; j++) {
      if (!Pase(p[i], zavint[j])) {
        rje[i] = 3 - j;
        if (!NapDfs(i))
          return 0;
      }
    }
  }

  return 1;
}

int Rijesi()
{
  for (int i=0; i<n; i++) {
    if (!rje[i]) {
      if (Pase(zavint[1], p[i])) {
        rje[i] = 1;
        if (!NapDfs(i))
          rje[i] = 0;
      }
      if (!rje[i]) {
        rje[i] = 2;
        if (!NapDfs(i))
          return 0;
      }
    }
  }

  return Pase(zavint[1], zavint[1]) && Pase(zavint[2], zavint[2]);
}

int main()
{
  int t, T, m;
  int minr=INF, maxl=-INF;
  char s[2][20] = { "IMPOSSIBLE", "POSSIBLE" };

  scanf("%d%d%d%d", &t, &T, &n, &m);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &p[i].X, &p[i].Y);
    minr = min(minr, p[i].Y);
    maxl = max(maxl, p[i].X);
  }

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  
  zavint[1] = P(-INF, minr);
  zavint[2] = P(maxl, INF);

  if (!StaviPoc()) {
    printf("%s\n", s[0]);
    return 0;
  }
  else {
    zavint[2].X = max(zavint[2].X, t - zavint[1].Y);
    zavint[1].Y = min(zavint[1].Y, T - zavint[2].X);
    if (!Rijesi()) {
      printf("%s\n", s[0]);
      return 0;
    }
    else {
      P tmp;
      if (zavint[1].Y + zavint[2].X < t)
        tmp = P(zavint[1].Y, t - zavint[1].Y);
      else if (zavint[1].Y + zavint[2].X > T)
        tmp = P(T - zavint[2].X, zavint[2].X);
      else
        tmp = P(zavint[1].Y, zavint[2].X);

      if (tmp.X < 0 || tmp.Y < 0)
        printf("%s\n", s[0]);
      else {
        printf("%s\n%d %d\n", s[1], tmp.X, tmp.Y);
        for (int i=0; i<n; i++)
          printf("%d", rje[i]);
        printf("\n");
      }
    }
  }

  return 0;
}