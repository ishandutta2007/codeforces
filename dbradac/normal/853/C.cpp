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

ll pov2(int x) { return (ll) x * (x-1) / 2; }

const int MAX = 1<<18;

struct str {
  int r1, r2, s1, s2, ind, koef;
} q[8*MAX];

int fen[MAX];

void stavi(int pos, int val) { 
  for (pos+=3; pos < MAX; pos += pos & -pos)
    fen[pos] += val;
}

int vrati(int pos) {
  int ret=0;
  for (pos+=3; pos; pos -= pos & -pos)
    ret += fen[pos];
  return ret;
}

int red[MAX], stup[MAX];
int n, brq;
int kol[16*MAX];
ll rje[MAX];

struct ev {
  int t, l, r, ind, koef;
} eventi[16*MAX];

void sweep() {
  int inde=0;
  REP(i, 8*brq) {
    eventi[inde++] = {q[i].r1-1, q[i].s1, q[i].s2, i, -1};
    eventi[inde++] = {q[i].r2, q[i].s1, q[i].s2, i, 1};
  }

  assert(inde == 16*brq);
  sort(eventi, eventi + inde, [] (const ev &a, const ev &b) { return a.t < b.t; });

  int j=0;
  for (; j<inde && eventi[j].t == 0; j++);
  FOR(i, 1, n+1) {
    stavi(stup[i], 1);    
    for (; j<inde && eventi[j].t <= i; j++) {
      kol[eventi[j].ind] += eventi[j].koef * (vrati(eventi[j].r) - vrati(eventi[j].l-1));
      //      TRACE(j _ eventi[j].ind _ eventi[j].r _ eventi[j].l _ (vrati(eventi[j].r) - vrati(eventi[j].l-1)));
    }
  }

  REP(i, 8*brq) {
    //    TRACE(q[i].ind _ q[i].koef _ kol[i]);
    rje[q[i].ind] += q[i].koef * pov2(kol[i]);
  }
}

int main()
{
  scanf("%d%d", &n, &brq);
  
  FOR(i, 1, n+1) {
    scanf("%d", &red[i]);
    stup[red[i]] = i;
  }

  //r1, r2, s1, s2, ind, koef
  int qq=0;

  //  TRACE(pov2(n));
  REP(i, brq) {
    int r1, r2, s1, s2;
    scanf("%d%d%d%d", &s1, &r1, &s2, &r2);
    //    TRACE(1 _ n _ 1 _ s1-1);
    
    q[qq++] = {1, r1-1, 1, n, i, 1};
    q[qq++] = {r2+1, n, 1, n, i, 1};
    q[qq++] = {1, n, 1, s1-1, i, 1};
    q[qq++] = {1, n, s2+1, n, i, 1};

    q[qq++] = {1, r1-1, 1, s1-1, i, -1};
    q[qq++] = {1, r1-1, s2+1, n, i, -1};
    q[qq++] = {r2+1, n, 1, s1-1, i, -1};
    q[qq++] = {r2+1, n, s2+1, n, i, -1};            
  }

  assert(qq == 8*brq);
  
  sweep();

  REP(i, brq)
    printf("%lld\n", pov2(n) - rje[i]);

  return 0;
}