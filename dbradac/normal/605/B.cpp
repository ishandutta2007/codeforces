#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

struct edge {
  int val, st, ind;
} p[MAX];

bool operator < (const edge &a, const edge &b)
{
  if (a.val != b.val)
    return a.val < b.val;
  return a.st > b.st;
}

void Nope()
{
  printf("-1\n");
  exit(0);
}

int ea[MAX], eb[MAX];
int root[MAX];
vector <P> Slob;
set <P> S;
vector <int> V[MAX];

void Spoji(int a, int b)
{
  a = root[a];
  b = root[b];

  S.erase(P(-(int) V[a].size(), a));
  S.erase(P(-(int) V[b].size(), b));

  for (int i=0; i<(int) V[a].size(); i++) {
    if ((int) Slob.size() >= MAX)
      break;
    for (int j=0; j<(int) V[b].size(); j++) {
      if ((int) Slob.size() >= MAX)
        break;
      if (V[a][i] != a || V[b][i] != b)
        Slob.push_back(P(V[a][i], V[b][j]));
    }
  }

  if (V[a].size() < V[b].size())
    swap(a, b);

  for (int i=0; i<(int) V[b].size(); i++) {
    root[V[b][i]] = a;
    V[a].push_back(V[b][i]);
  }

  S.insert(P(-(int) V[a].size(), a));
}

int main()
{
  int n, m;

  scanf("%d%d", &n, &m);

  for (int i=1; i<=n; i++) {
    V[i].push_back(i);
    root[i] = i;
    S.insert(P(-1, i));
  }

  for (int i=0; i<m; i++) {
    scanf("%d%d", &p[i].val, &p[i].st);
    p[i].ind = i;
  }

  sort(p, p + m);

  for (int i=0; i<m; i++) {
    if (p[i].st) {
      if (S.size() < 2)
        Nope();

      set <P> :: iterator it = S.begin();
      set <P> :: iterator it2 = it; it2++;
      ea[p[i].ind] = root[it->Y];
      eb[p[i].ind] = root[it2->Y];
      Spoji(it->Y, it2->Y);
    }
    else {
      if (Slob.empty())
        Nope();

      P tmp = Slob.back();      
      Slob.pop_back();
      ea[p[i].ind] = tmp.X;
      eb[p[i].ind] = tmp.Y;
    }
  }

  for (int i=0; i<m; i++)
    printf("%d %d\n", ea[i], eb[i]);

  return 0;
}