#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1<<17;

struct str {
  int node, st;
  str (int node, int st) : node(node), st(st) {}
  str () {}
};

bool operator < (str a, str b)
{
  if (a.node != b.node)
    return a.node < b.node;
  return a.st < b.st;
}

vector <str> V[MAX];
map <pair<int, str>, int > M;
vector <pair<int, str> > R;
queue <int> Q;
int kad[MAX];
int best[MAX], odakle[MAX];
int proso[MAX];
int mint;
int n;

void Bfs()
{
  memset(kad, -1, sizeof kad);
  kad[n] = 0;
  Q.push(n);

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();

    for (int i=0; i<(int) V[tmp].size(); i++) {
      int nn = V[tmp][i].node;
      if (kad[nn] == -1) {
        kad[nn] = kad[tmp] + 1;
        Q.push(nn);
      }
    }
  }

  mint = kad[1];
}

void Bfs2()
{
  memset(best, -1, sizeof best);
  best[1] = 0;
  Q.push(1);

  for (; !Q.empty(); ) {
    int tmp = Q.front();
    Q.pop();

    for (int i=0; i<(int) V[tmp].size(); i++) {
      int nn = V[tmp][i].node;
      if (kad[tmp] == kad[nn] + 1) {
        if (best[nn] == -1 || best[nn] < best[tmp] + V[tmp][i].st) {
          if (best[nn] == -1)
            Q.push(nn);
          best[nn] = best[tmp] + V[tmp][i].st;
          odakle[nn] = tmp;
        }
      }
    }
  }
}

int main()
{
  int e;

  scanf("%d%d", &n, &e);

  for (int i=0; i<e; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    V[a].push_back(str(b, c));
    V[b].push_back(str(a, c));
  }

  Bfs();
  Bfs2();

  for (int node=n; node!=1; node = odakle[node]) {
    int a = node, b = odakle[node], st=0;
    for (int j=0; j<(int) V[node].size(); j++)
      if (V[node][j].node == b) {
        st = V[node][j].st;
        if (a > b)
          swap(a, b);
        M[make_pair(a, str(b, st))] = 1;

        if (!st)
          R.push_back(make_pair(a, str(b, st)));
      }
  }

  for (int i=1; i<=n; i++) {
    for (int j=0; j<(int) V[i].size(); j++) {
      int a = i, b = V[i][j].node, st = V[i][j].st;
      if (a > b)
        swap(a, b);
      if (!M[make_pair(a, str(b, st))]) {
        M[make_pair(a, str(b, st))] = 1;
        if (st)
          R.push_back(make_pair(a, str(b, st)));
      }
    }
  }

  printf("%u\n", R.size());
  for (int i=0; i<(int) R.size(); i++)
    printf("%d %d %d\n", R[i].first, R[i].second.node, 1 - R[i].second.st);

  return 0;
}