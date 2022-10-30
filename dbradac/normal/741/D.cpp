#include <cstdio>
#include <unordered_map>
#include <set>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19, INF = 0x3f3f3f3f;

//multiset <P> S;
int mdub[(1<<26) * 2 / 3 + 10];
int p[MAX], dub[MAX];
vector <P> V[MAX];
int sub[MAX];
int rje[MAX];

int daj(int ind)
{
  if (ind % 3 == 0) {
    return mdub[2*(ind/3)] % (1<<20);
  }
  if (ind % 3 == 1) {
    int ret = mdub[2*(ind/3)] / (1<<20);
    ret += (mdub[2*(ind/3)+1] / (1<<20)) * (1<<10);
    return ret;
  }
  return mdub[2*(ind/3)+1] % (1<<20);
}

void postavi(int ind, int val)
{
  if (ind % 3 == 0) {
    mdub[2*(ind/3)] >>= 20;
    mdub[2*(ind/3)] <<= 20;
    mdub[2*(ind/3)] += val;
    //TRACE(mdub[2*(ind/3)]);
  }
  else if (ind % 3 == 1) {
    mdub[2*(ind/3)] <<= 12;
    mdub[2*(ind/3)] >>= 12;
    mdub[2*(ind/3)] += (1<<20) * (val % (1<<10));

    mdub[2*(ind/3)+1] <<= 12;
    mdub[2*(ind/3)+1] >>= 12;
    mdub[2*(ind/3)+1] += (1<<20) * (val / (1<<10));
  }
  else {
    mdub[2*(ind/3)+1] >>= 20;
    mdub[2*(ind/3)+1] <<= 20;
    mdub[2*(ind/3)+1] += val;
  }
}

inline void ubaci(int node, int dulj)
{
  int tmp = daj(p[node]);
  if (dulj > tmp)
    postavi(p[node], dulj);

//  mdub[pozz[node][26]] = max(mdub[pozz[node][26]], dulj);
//  S.insert(P(mask, -dulj));
}

inline void izbaci(int node)
{
  postavi(p[node], 0);
//  mdub[pozz[node][26]] = -INF;
//  S.erase(S.find(P(mask, -dulj)));
}

int query(int node, int dosad, int db)
{
  int ret = -INF;
  REP(i, 27) {
    int tmp = p[node] ^ (i == 26 ? 0 : (1<<i));
    tmp = daj(tmp);

    if (tmp)
      ret = max(ret, dosad + tmp - db);
    //auto it = S.lower_bound(P(tmp, -INF));
//    if (it != S.end() && it->X == tmp)
  //    ret = max(ret, dosad + ((-it->Y - db)));
  }

  return ret;
}

void ubaci_pod(int node)
{
  ubaci(node, dub[node]);
  for (auto it : V[node])
    ubaci_pod(it.X);
}

void izbaci_pod(int node)
{
  izbaci(node);
  for (auto it : V[node])
    izbaci_pod(it.X);
}

int dfs(int node)
{
  sub[node] = 1;
  for (auto it : V[node]) {
    p[it.X] = p[node] ^ (1<<it.Y);
    dub[it.X] = dub[node] + 1;
    sub[node] += dfs(it.X);
  }

  return sub[node];
}

int queryaj(int rt, int node)
{
  int ret = 0;
  ret = query(node, dub[node] - dub[rt], dub[rt]);

  for (auto it : V[node])
    ret = max(ret, queryaj(rt, it.X));

  return ret;
}

void rijesi(int node)
{
  int mx = -1, ind = -1;
  for (auto it : V[node])
    if (sub[it.X] > mx) {
      mx = sub[it.X];
      ind = it.X;
    }

  for (auto it : V[node])
    if (it.X != ind) {
      rijesi(it.X);
      rje[node] = max(rje[node], rje[it.X]);
      izbaci_pod(it.X);
    }

  if (ind != -1) {
    rijesi(ind);
    rje[node] = max(rje[node], rje[ind]);
  }

  for (auto it : V[node])
    if (it.X != ind) {
      rje[node] = max(rje[node], queryaj(node, it.X));
      ubaci_pod(it.X);
    }

  rje[node] = max(rje[node], query(node, 0, dub[node]));
  ubaci(node, dub[node]);
}

int main()
{
  int n;
  scanf("%d", &n);
  //n = 500000;

  FOR(i, 1, n) {
    int par;
    char s[5];
    scanf("%d %s", &par, s); par--;
  //  par = i / 2;
//    s[0] = rand() % 26 + 'a';
    V[par].push_back(P(i, s[0] - 'a'));
  }

  dub[0] = 1;
  dfs(0);

  rijesi(0);

  REP(i, n)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}