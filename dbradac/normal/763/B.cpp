#include <cstdio>
#include <map>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 500100;

int n;
P t1[MAX], t2[MAX];
vector <int> V[MAX];
int bio[MAX];
map <int, vector<pair<P, int> > > M;
int deg[MAX];
int rje[MAX];

void add_edge(int a, int b)
{
  V[a].push_back(b);
  V[b].push_back(a);
}

void go()
{
  M.clear();

  REP(i, n) {
    M[t1[i].X].push_back(make_pair(P(t1[i].Y, t2[i].Y), i));
    M[t2[i].X].push_back(make_pair(P(t1[i].Y, t2[i].Y), i));
  }

  for (auto it = M.begin(); it != M.end(); it++) {
    vector <pair<P, int> > T = it->Y;
    sort(T.begin(), T.end());

    int ind=0;
    for (int i=1; i<(int) T.size(); i++) {
      if (T[ind].X.Y > T[i].X.X)
        add_edge(T[ind].Y, T[i].Y);
      if (T[i].X.Y > T[ind].X.Y)
        ind = i;
    }
  }
}

int main()
{
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d%d", &t1[i].X, &t1[i].Y);
    scanf("%d%d", &t2[i].X, &t2[i].Y);
  }

  go();

  REP(i, n) {
    swap(t1[i].X, t1[i].Y);
    swap(t2[i].X, t2[i].Y);
  }

  go();
  
  vector <int> T;
  queue <int> Q;

  REP(i, n) {
    deg[i] = (int) V[i].size();
    if (deg[i] < 4) { Q.push(i); bio[i] = 1; }
  }

  for (; !Q.empty(); ) {
    int tmp = Q.front(); Q.pop();
    T.push_back(tmp);
    for (auto it : V[tmp]) {
      deg[it]--;
      if (deg[it] < 4 && !bio[it]) {
        Q.push(it);
        bio[it] = 1;
      }
    }
  }
  
  assert((int) T.size() == n);
  reverse(T.begin(), T.end());

  for (auto it : T) {
    int ima[5] = {0, 0, 0, 0, 0};
    for (auto itv : V[it])
      ima[rje[itv]] = 1;

    FOR(i, 1, 5) {
      if (!ima[i]) {
        rje[it] = i;
        break;
      }
    }
  }

  printf("YES\n");
  REP(i, n) { assert(rje[i]); printf("%d\n", rje[i]); }

  return 0;
}