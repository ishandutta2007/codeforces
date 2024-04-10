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

const int MAX = 1<<18, KOR = 450, LG = 18;

struct strq {
  int l, r, ind;
};

vector <int> V[MAX];
int disc[MAX], fin[MAX], vr=0;
int qa[MAX], qb[MAX];
int st[MAX], val[MAX];
vector <strq> Qovi;
vector <int> Q[MAX];
int sto[MAX];
int n, brq;
ll rje[MAX];
int lca[MAX][LG], dub[MAX];
int dod[MAX];

int find_lca(int a, int b) {
  if (dub[a] > dub[b]) swap(a, b);
  int raz = dub[b] - dub[a];
  REP(i, LG)
    if (raz >> i & 1)
      b = lca[b][i];
  
  if (a == b) return a;
  
  for (int i=LG-1; i>=0; i--) {
    if (lca[a][i] != lca[b][i]) {
      a = lca[a][i];
      b = lca[b][i];
    }      
  }    

  return lca[a][0];
}

void dfs(int x, int pr) {
  if (pr != -1) {
    lca[x][0] = pr;
    dub[x] = dub[pr] + 1;
  }

  FOR(i, 1, LG)
    lca[x][i] = lca[lca[x][i-1]][i-1];

  sto[vr] = x;
  disc[x] = vr++;
  for (auto it : V[x])
    if (it != pr)
      dfs(it, x);

  sto[vr] = x;
  fin[x] = vr++;
}

void solve(int ind) {
  int poc = ind * KOR;

  REP(i, MAX) Q[i].clear();
  REP(j, (int) Qovi.size()) {
    auto q = Qovi[j];
    if (q.l > poc - KOR && q.l <= poc) {
      Q[max(poc-1, q.r)].push_back(j);    
      //      TRACE(j _ ind _ max(poc-1, q.r));
    }
  }

  int cnt[MAX][2], bio[MAX];
  memset(cnt, 0, sizeof cnt);
  memset(bio, 0, sizeof bio);
  ll sum = 0;

  FOR(i, poc-1, max(2*n, poc)) {
    //    if (i == KOR - 1) TRACE(ind _ i _ Q[i].size());
    if (i != poc-1) {
      int node = sto[i], ko = bio[node] ? -1 : 1;
      bio[node]++;
      sum += cnt[val[node]][1^st[node]] * ko;
      cnt[val[node]][st[node]] += ko;
    }    
      
    for (auto kek : Q[i]) {
      auto q = Qovi[kek];

      FOR(tm, q.l, min(poc, q.r+1) + 1) {
	int x = (tm == min(poc, q.r+1)) ? dod[q.ind] : sto[tm];
	if (x == -1) continue;

	int koef = bio[x] ? -1 : 1;
	bio[x]++;
	sum += cnt[val[x]][1^st[x]] * koef;
	cnt[val[x]][st[x]] += koef;
      }

      rje[q.ind] += sum;
      //      TRACE(q.ind);

	FOR(tm, q.l, min(poc, q.r+1) + 1) {
	int x = (tm == min(poc, q.r+1)) ? dod[q.ind] : sto[tm];
	if (x == -1) continue;

	int koef = (bio[x] == 2) ? 1 : -1;
	bio[x]--;
	sum += cnt[val[x]][1^st[x]] * koef;
	cnt[val[x]][st[x]] += koef;
      }
    }
  }
}

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &st[i]);
  REP(i, n) scanf("%d", &val[i]);

  vector <int> T(val, val + n);
  sort(T.begin(), T.end());
  REP(i, n) val[i] = (int) (lower_bound(T.begin(), T.end(), val[i]) - T.begin());

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  dfs(0, -1);

  scanf("%d", &brq);
  memset(dod, -1, sizeof dod);
  
  REP(i, brq) {
    scanf("%d%d", &qa[i], &qb[i]); qa[i]--; qb[i]--;
    int lc = find_lca(qa[i], qb[i]);
    //    TRACE(qa[i] _ qb[i] _ lc);

    if (disc[qb[i]] < disc[qa[i]])
      swap(qa[i], qb[i]);
    
    if (lc == qa[i])
      Qovi.push_back({disc[qa[i]], disc[qb[i]], i});      
    else { 
      dod[i] = lc;
      Qovi.push_back({fin[qa[i]], disc[qb[i]], i});
    }
  }

  // for (auto it : Qovi)
  //   TRACE(it.l _ it.r _ it.ind);

  // TRACE(KOR * KOR);
  REP(i, KOR)
    solve(i);

  REP(i, brq)
    printf("%lld\n", rje[i]);

  return 0;
}