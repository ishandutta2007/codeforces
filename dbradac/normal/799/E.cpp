#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define _ << " _ " <<

#define TRACE(x) cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

// #define TRACE(x)
// #define debug(...)

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;
#define X first
#define Y second

const int MAXN = 1<<19;
const llint INF = 1e18;

int lajk[MAXN][2];
llint cost[MAXN];
int n, m, k;

multiset <P> UzOb, UzJedan[2], UzOs;
multiset <P> Oboje, Jedan[2], Ostali;
llint sum = 0;
int ok = 0;

void uzmi(multiset<P> &S, multiset<P> :: iterator it, multiset <P> &Uz) {
  //  TRACE("uzmi" _ it->X _ it->Y+1);
  if (it->X != INF) sum += it->X;
  if (it->X == INF) ok++;
  
  Uz.insert(*it);  
  S.erase(it);
}

void izbaci(multiset<P> &S, P tmp, multiset <P> &Uz) {
  //  TRACE("izbaci" _ tmp.X _ tmp.Y+1);
  if (tmp.X != INF) sum -= tmp.X;
  if (tmp.X == INF) ok--;
  
  auto it2 = Uz.find(tmp);
  if (it2 != Uz.end())
    Uz.erase(it2);

  S.insert(tmp);
}

llint rje = INF;

void upd() {
  //  TRACE(ok _ sum);
  if (ok == 0) rje = min(rje, sum);
}

void stavi_min() {
  P mn = *Ostali.begin();
  REP(i, 2)
    mn = min(mn, *Jedan[i].begin());
  
  REP(i, 2) {
    if (mn == *Jedan[i].begin()) { uzmi(Jedan[i], Jedan[i].begin(), UzJedan[i]); return; }
  }
  
  uzmi(Ostali, Ostali.begin(), UzOs);
}

P daj_max(multiset<P> &S) {
  if (S.empty()) return {-1, -1};
  auto it = --S.end();
  return *it;
}

void izbaci_max() { 
  P mx = daj_max(UzOs);
  REP(i, 2) {
    if ((int) UzJedan[i].size() + (int) UzOb.size() > k)
      mx = max(mx, daj_max(UzJedan[i]));
  }

  if (mx == daj_max(UzOs)) { izbaci(Ostali, mx, UzOs); return; }
  REP(i, 2) {
    if (mx == daj_max(UzJedan[i]) &&
	(int) UzJedan[i].size() + (int) UzOb.size() > k) {
      izbaci(Jedan[i], mx, UzJedan[i]);
      return;
    }
  }
}

int main(void) {
  // n = 200000;
  // m = 100000;
  // k = 50000;
  scanf("%d%d%d", &n, &m, &k);
  if (m < k || m > n) { printf("-1\n"); return 0; }       
  
  REP(i, n) scanf("%lld", &cost[i]);
  //  REP(i, n) cost[i] = rand();
   
  REP(i, 2) {
    int kol;
    scanf("%d", &kol);
    //    kol = rand() % n;
    REP(j, kol) {
      int ind;
      scanf("%d", &ind); ind--;
      //ind = rand() % n;
      lajk[ind][i] = 1;
    }
  }

  int brob = 0;
  REP(i, n) {
    P tmp = P(cost[i], (llint) i);
    
    if (lajk[i][0] && lajk[i][1]) { brob++; Oboje.insert(tmp); }
    else if (lajk[i][0]) Jedan[0].insert(tmp);
    else if (lajk[i][1]) Jedan[1].insert(tmp);
    else Ostali.insert(tmp);
  }

  // for (auto it : Oboje) TRACE("ob" _ it.X);
  // for (auto it : Jedan[0]) TRACE("j0" _ it.X);
  // for (auto it : Jedan[1]) TRACE("j1" _ it.X);
  // for (auto it : Ostali) TRACE("os" _ it.X);  
  
  REP(i, 2)
    while ((int) Jedan[i].size() < MAXN) Jedan[i].insert(P(INF, INF));    
  while ((int) Oboje.size() < MAXN) Oboje.insert({INF, INF});
  while ((int) Ostali.size() < MAXN) Ostali.insert({INF, INF});  

  int mora_ob = 0;
  for (; mora_ob + 2*(k-mora_ob) > m; mora_ob++);

  REP(i, mora_ob)
    uzmi(Oboje, Oboje.begin(), UzOb);
  
  int mora_jed = k - mora_ob;
  REP(i, mora_jed)
    REP(j, 2)
      uzmi(Jedan[j], Jedan[j].begin(), UzJedan[j]);
  
  REP(i, m - 2*mora_jed - mora_ob)
    stavi_min();

  //  TRACE(mora_ob _ mora_jed);
      
  upd();  
  
  REP(i, m) {
    uzmi(Oboje, Oboje.begin(), UzOb);    
    izbaci_max();
      
    for (;;) {
      P pros = {ok, sum};
      izbaci_max();      
      stavi_min();

      //      TRACE(i _ pros.X _ pros.Y _ ok _ sum);
      
      if (P(ok, sum) >= pros) break;
    }
    //    TRACE(i _ ok _ sum);

    upd();
  }

  printf("%lld\n", rje < INF/2 ? rje : -1);
  
  return 0;
}