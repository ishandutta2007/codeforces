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

const llint INF = 1e15;
const int MAX = 1<<18;

struct str {
  llint val, beat, ind;
  P m1, m2;
};

bool operator < (const str &a, const str &b) {
  return a.val < b.val;
}

vector<str> gen(vector <P> p) {
  int n = (int) p.size();
  
  sort(p.begin(), p.end());
  vector <str> R;
  
  REP(i, n) {
    //    TRACE(p[i].first _ p[i].second _ i _ n _ p.size());
    str tmp; tmp.val = p[i].first;
    tmp.beat = p[i].second;
    tmp.ind = i;
    //    TRACE(p[i].second _ tmp.beat);
    
    if (!i) {
      tmp.m1 = P(tmp.beat, tmp.ind);
      tmp.m2 = P(-INF, -INF);
    }
    else {
      tmp.m1 = R.back().m1;
      tmp.m2 = R.back().m2;

      P nov = P(tmp.beat, tmp.ind);
      if (nov > tmp.m1) {
	tmp.m2 = tmp.m1;
	tmp.m1 = nov;
      }
      else if (nov > tmp.m2)
	tmp.m2 = nov;
    }

    //    TRACE("PUSH" _ tmp.m1.first _ tmp.m1.second);
    R.push_back(tmp);
  }

  return R;
}

llint daj(const vector <str> &V, llint para, llint ind) {
  auto it = upper_bound(V.begin(), V.end(), str{para, -1, -1, P(-1, -1), P(-1, -1)});
  if (it == V.end() || it->val > para) {
    if (it == V.begin()) return -INF;
    it--;
  }
  //  TRACE(it - V.begin());

  //  TRACE(it - V.begin() _ it->m1.first);
  if (it->m1.second == ind) return it->m2.first;
  return it->m1.first;
}

int main(void) {
  vector <P> CCC, DDD;
  
  llint n, imac, imad;
  scanf("%lld%lld%lld", &n, &imac, &imad);

  llint rje = 0;

  REP(i, n) {
    llint bt, cs;
    char tp;
    scanf("%lld%lld %c", &bt, &cs, &tp);
    if (tp == 'C')
      CCC.push_back(P(cs, bt));
    else
      DDD.push_back(P(cs, bt));
  }
  
  vector <str> C = gen(CCC);
  vector <str> D = gen(DDD);

  rje = 0;
  rje = max(rje, daj(C, imac, -1) + daj(D, imad, -1));
  //  TRACE(imac _ imad);
  //  TRACE(daj(C, imac, -1) _ daj(D, imad, -1));

  for (auto it : C) {
    if (it.val <= imac) {
      rje = max(rje, daj(C, (llint) imac - it.val, (llint) it.ind) + it.beat);
      //   TRACE(rje _ it.beat);
    }
  }

  for (auto it : D)
    if (it.val <= imad)
      rje = max(rje, daj(D, imad - it.val, it.ind) + it.beat);
  
  printf("%lld\n", rje);
  
  return 0;
}