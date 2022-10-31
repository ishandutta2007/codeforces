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

const int MAX = 1<<17, TOUR = 1<<17, BUFSZ = 120 * (1<<17);

struct node {
  node *l, *r;
  int sum;
} buff[BUFSZ], *NIL;

node *roots[MAX];
int brojac=1;

node *stavi(node *pr, int lo, int hi, int begin)
{
  if (lo >= begin + 1 || hi <= begin) return pr;
  node *ja = &buff[brojac++];
  *ja = *pr;

  if (lo >= begin && hi <= begin + 1) {
    ja->sum++;
    return ja;
  }

  ja->l = stavi(pr->l, lo, (lo+hi)/2, begin);
  ja->r = stavi(pr->r, (lo+hi)/2, hi, begin);
  ja->sum = ja->l->sum + ja->r->sum;

  return ja;  
}

P nadi(node *pr, int lo, int hi, int begin, int jos)
{
  if (hi <= begin) return {MAX, 0};
  if (lo + 1 == hi && pr->sum > jos) return {lo, pr->sum};

  if (lo >= begin) {
    if (pr->sum <= jos) return P(MAX, pr->sum);
    P tmp = nadi(pr->l, lo, (lo+hi)/2, begin, jos);
    if (tmp.X < MAX) return tmp;
    P ret = nadi(pr->r, (lo+hi)/2, hi, begin, jos - tmp.Y);
    return {ret.X, ret.Y + tmp.Y};
  }
  
  P tmp = nadi(pr->l, lo, (lo+hi)/2, begin, jos);
  if (tmp.X < MAX) return tmp;
  P ret = nadi(pr->r, (lo+hi)/2, hi, begin, jos - tmp.Y);
  return {ret.X, ret.Y + tmp.Y};
}

int n;
int p[MAX];
int zad[MAX], prv[MAX];
vector <P> V;

int rje(int k)
{
  int ret = 0, poz = 1;
  for (; poz<=n; ret++) {
    //    TRACE(k _ poz);
    poz = nadi(roots[poz-1], 0, TOUR, poz, k).X;
  }
  return ret;
}

int main()
{
  scanf("%d", &n);

  NIL = new node;
  NIL->l = NIL->r = NIL;
  NIL->sum = 0;
  REP(i, BUFSZ) buff[i] = *NIL;

  roots[0] = &buff[0];
  
  FOR(i, 1, n+1) {
    scanf("%d", &p[i]);
    prv[i] = zad[p[i]];
    zad[p[i]] = i;
    V.push_back({prv[i], i});
  }

  sort(V.begin(), V.end());
  
  int ind = 0;
  REP(i, n+1) {
    if (i) roots[i] = roots[i-1];
    for (; ind < (int) V.size() && V[ind].X <= i; ind++)
      roots[i] = stavi(roots[i], 0, TOUR, V[ind].Y);
  }
  
  FOR(k, 1, n+1)
    printf("%d ", rje(k));  
  printf("\n");

  return 0;
}