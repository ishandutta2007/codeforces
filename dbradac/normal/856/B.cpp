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

const int MAX = 1<<21;

int n_id;
struct node {
  node *p[26];
  int id;
  node() {
    id = n_id++;
    memset(p, 0, sizeof p);
  }
} *root[2];

int lev[MAX];

int insert(node *rt, char *s, int st) {
  int len = (int) strlen(s);
  node *tmp = rt;
  
  REP(i, len) {
    int c = (int) (s[i] - 'a');
    if (!(tmp->p[c])) tmp->p[c] = new node;
    tmp = tmp->p[c];
    lev[tmp->id] = st;
  }
  
  return tmp->id;
}

vector <int> V[MAX];
int krnji[MAX], isti[MAX];
int dp[MAX][2];

void find_odg(int odg[MAX], node *p1, node *p2) {
  odg[p1->id] = p2 ? p2->id : -1;
  //TRACE(p1->id _ odg[p1->id]);

  REP(i, 26)
    if (p1->p[i])
      find_odg(odg, p1->p[i], (p2 && p2->p[i]) ? p2->p[i] : 0);
}

void puni(node *p) {
  if (krnji[p->id] != -1 && isti[krnji[p->id]] != -1)
    V[isti[krnji[p->id]]].push_back(p->id);

  REP(i, 26)
    if (p->p[i])
      puni(p->p[i]);  
}

int rek(int ind, int st) {
  if (dp[ind][st] != -1) return dp[ind][st];
  
  int sum0 = 0, sum1 = 0;
  for (auto it : V[ind]) {
    sum0 += rek(it, 0);
    sum1 += rek(it, 1);
  }

  dp[ind][0] = max(1 + sum1, sum0);
  dp[ind][1] = sum0;

  return dp[ind][st];
}

int main()
{
  int brt;
  scanf("%d", &brt);

  memset(krnji, -1, sizeof krnji);
  memset(isti, -1, sizeof isti);
  memset(dp, -1, sizeof dp);
  
  for (; brt--;) {
    n_id = 0;
    root[0] = new node;
    root[1] = new node;

    int n;
    scanf("%d", &n);
    char s[MAX];

    REP(i, n) {
      scanf(" %s", s);      
      insert(root[0], s, 1);
      insert(root[1], s+1, 0);
    }

    REP(i, 26)
      if (root[0]->p[i])
	find_odg(krnji, root[0]->p[i], root[1]);

    lev[root[0]->id] = 1;
    krnji[root[0]->id] = -1;

    //    TRACE("AJMO ISTI");
    find_odg(isti, root[1], root[0]);
    puni(root[0]);

    int rje = 0;
    REP(i, n_id)
      if (lev[i] && (krnji[i] == -1 || isti[krnji[i]] == -1))
	rje += rek(i, !i);
    
    printf("%d\n", rje);
    
    REP(i, n_id) {
      lev[i] = 0;
      dp[i][0] = dp[i][1] = -1;
      krnji[i] = isti[i] = -1;
      V[i].clear();
    }
  }
  
  return 0;
}