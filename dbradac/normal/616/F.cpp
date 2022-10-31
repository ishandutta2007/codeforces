#include <map>
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

const int MAXN = 1<<21;

int suf[MAXN];
int d[MAXN];
map <int, int> A[MAXN];
int sink, alloc;
int term[MAXN];
int bio[MAXN];
ll dp[MAXN];

void init() {
  memset(suf, -1, sizeof suf);
  sink = alloc = 0;
}

void extend(int a) {
  int newsink = ++alloc;

  A[sink][a] = newsink;
  d[newsink] = d[sink] + 1;

  int w = suf[sink];
  while (w != -1 && A[w].find(a) == A[w].end()) {
    A[w][a] = newsink;
    w = suf[w];
  }

  if (w == -1) suf[newsink] = 0;
  else if (d[A[w][a]] == d[w] + 1) suf[newsink] = A[w][a];
  else {
    int newnode = ++alloc;
    int v = A[w][a];

    A[newnode] = A[v];
    A[w][a] = newnode;
    d[newnode] = d[w] + 1;
    suf[newsink] = newnode;
    suf[newnode] = suf[v];
    suf[v] = newnode;

    w = suf[w];
    while (w != -1 && (A[w].find(a) != A[w].end() && A[w][a] == v) && d[w] + 1 != d[v]) {
      A[w][a] = newnode;
      w = suf[w];
    }
  }

  sink = newsink;
}

void build(const int *s, int n) {  
  REP(i, n) extend(s[i]);
}

int bitan[MAXN], jelbitan[MAXN];
int dist[MAXN];

ll dfs(int x)
{
  if (bio[x]++) return dp[x]; 

  if (x == sink)
    dist[x] = 0;

  for (auto it = A[x].begin(); it != A[x].end(); it++) {
    dfs(it->Y);
    if (jelbitan[it->Y])
      dp[x] += bitan[it->Y];
    else
      dp[x] += dp[it->Y];

    dist[x] = max(dist[x], 1 + dist[it->Y]);
  }

  if (jelbitan[x]) dp[x] = 0;

  return dp[x];
}

char s[MAXN];
int niz[MAXN];
int poc[MAXN], kraj[MAXN];
int val[MAXN];
int prva_lev[MAXN];
int ind_node[MAXN];
int sajz;
int n;

ll solve()
{
  init();
  build(niz, sajz);

  int node = 0, ind = 0;
  REP(i, sajz) {
    node = A[node][niz[i]];
    ind_node[i] = node;
    if (i == kraj[ind]) {
      jelbitan[node] = 1;
      bitan[node] = val[ind];      
      ind++;
    }
  }

  dfs(0);

  prva_lev[0] = -1;
  FOR(i, 1, sajz) {
    if (jelbitan[ind_node[i]]) prva_lev[i] = i;
    else prva_lev[i] = prva_lev[i-1];
  }
  
  ll ret = 0;
  FOR(i, 1, MAXN) {
    int mind = d[suf[i]] + 1;
    int moj_kraj = sajz - 1 - dist[i];
    int len = min(d[i], moj_kraj - prva_lev[moj_kraj]);

    if (len >= mind)
      ret = max(ret, (ll) len * dp[i]);    
  }
    
  return ret;
}

void load()
{
  scanf("%d", &n);
  
  REP(i, n) {
    scanf(" %s", s);
    int len = (int) strlen(s);
    poc[i] = sajz;
    REP(j, len)
      niz[sajz+j] = s[j];
    sajz += len;

    kraj[i] = sajz;
    niz[sajz++] = i + 400;
  }

  REP(i, n) scanf("%d", &val[i]);
}

int main()
{
  load();
  printf("%lld\n", solve());  

  return 0;
}