#include <stack>
#include <cstdio>
#include <cstring>
#include <queue>
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

// odredi: konstanta MAX
// odredi: konstanta ALPHA
// postavi: V = 0
// pazi: s[i] - 'A'

const int MAX = 1e7 + 1000, ALPHA = 2, MAXN = 755;

int V = 1;
int trie[MAX][ALPHA];
int fn[MAX];
int rijec[MAX], rijecfail[MAX];
int mark[MAX];

int node() {
  REP(i, ALPHA) trie[V][i] = 0;
  fn[V] = 0;
  return V++;
}

int insert(char *s, int ind) {
  int t = 0;

  for (; *s; s++) {
    if (trie[t][*s - 'a'] == 0) trie[t][*s - 'a'] = node();
    t = trie[t][*s - 'a'];
  }
  rijec[t] = ind;
  return t;
}

void init_aho() {
  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    int t = Q.front(); Q.pop();
    
    REP(c, ALPHA) {
      int x = trie[t][c];
      if (x) {
        Q.push(x);

        if (t) {
          fn[x] = fn[t];
          while (fn[x] && trie[fn[x]][c] == 0) fn[x] = fn[fn[x]];
          if (trie[fn[x]][c]) fn[x] = trie[fn[x]][c];
        }
      }
    }

    if (t) {
      if (rijec[fn[t]] != -1)
	rijecfail[t] = fn[t];
      else
	rijecfail[t] = rijecfail[fn[t]];
    }
  }
}

char ss[MAX];
string s[MAXN];
string tmps[MAXN];
int e[MAXN][MAXN];
int len[MAXN];
int gdje[MAXN];
vector <int> Vec[MAXN];
int bio[MAXN], spojen[MAXN];
int ima[MAXN];

int dfs(int x)
{
  if (bio[x]++) return 0;

  REP(i, (int) Vec[x].size()) {
    if (spojen[Vec[x][i]] == -1 || dfs(spojen[Vec[x][i]])) {
      spojen[Vec[x][i]] = x;
      return 1;
    }
  }    

  return 0;
}

int n;
int biol[MAXN], bior[MAXN];

void rekon(int x)
{
  if (biol[x]++) return;
  for (auto it : Vec[x]) {
    bior[it] = 1;
    if (spojen[it] != -1)
      rekon(spojen[it]);
  }    
}

int main()
{
  memset(rijec, -1, sizeof rijec);
  memset(rijecfail, -1, sizeof rijecfail);

  scanf("%d", &n);
    
  REP(i, n) {

    scanf(" %s", ss);
    s[i] = ss;
    len[i] = (int) strlen(ss);
    gdje[i] = insert(ss, i);
  }

  init_aho();

  REP(i, n) {
    int cookie = i + 1;
    int node = 0;
    REP(j, len[i]) {
      node = trie[node][s[i][j] - 'a'];
      int tmp = node;
      for (; tmp >= 0 && mark[tmp] != cookie; tmp = rijecfail[tmp]) {
	if (rijec[tmp] != -1)
	  e[i][rijec[tmp]] = 1;
	mark[tmp] = cookie;
      }
    }
  }

  REP(i, n) {
    REP(j, n)
      if (i != j && e[i][j]) Vec[i].push_back(j);
    random_shuffle(Vec[i].begin(), Vec[i].end());
  }

  memset(spojen, -1, sizeof spojen);
  int rje = 0;
  REP(i, n) {
    memset(bio, 0, sizeof bio);
    if (dfs(i)) {
      rje++;
      ima[i] = 1;
    }
  }  
  
  REP(i, n)
    if (!ima[i])
      rekon(i);

  vector <int> R;

  REP(i, n)
    if (!bior[i] && biol[i])
      R.push_back(i+1);

  assert((int) R.size() == n - rje);
  printf("%d\n", (int) R.size());
  for (auto it : R)
    printf("%d ", it);
  printf("\n");

  return 0;
}