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

const int MAX = 1<<17;

int cnt[MAX];
vector <int> postoje;
llint sz1, sz2;
int rje=MAX;

int ok(llint a, llint b) {
  return max(a, b) >= max(sz1, sz2) &&
    min(a, b) >= min(sz1, sz2);
}

void rek(int ind, int dosad, llint a, llint b) {
  //  TRACE(ind _ a _ b);
  
  if (ind == (int) postoje.size()) return;
  
  int vel = postoje[ind];

  REP(i, cnt[vel]+1) {
    llint na = a, nb = b;
    
    for (int j=0; j<i && na < MAX; j++, na *= vel);
    int uzeo=0;
    for (int k=0; k<cnt[vel] - i && nb < MAX && !ok(na, nb); k++, nb *= vel, uzeo++);
    
    if (ok(na, nb)) {
      //      TRACE(na _ nb);
      rje = min(rje, dosad + i + uzeo);
    }
    else
      rek(ind+1, dosad + i + uzeo, na, nb);
  }  
}

int main(void) {
  llint h, w;
  int n;

  scanf("%lld%lld%lld%lld%d", &sz1, &sz2, &h, &w, &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }

  for (int i=MAX-1; i; i--)
    if (cnt[i])
      postoje.push_back(i);

  rek(0, 0, h, w);
  printf("%d\n", rje < MAX/2 ? rje : -1);
  
  return 0;
}