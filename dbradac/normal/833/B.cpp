#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<16, TOUR = MAX, INF = 0x3f3f3f3f, MAXK = 55;

struct node {
  int val;
  node *l, *r;
} *root[MAX], *NIL;

node *insert(node *p, int lo, int hi, int begin, int val) {
  if (p == NIL) p = new node{0, NIL, NIL};
  if (lo >= begin+1 || hi <= begin) return p;  

  p = new node{p->val + val, p->l, p->r};
  if (lo + 1 == hi) return p;
  
  p->l = insert(p->l, lo, (lo+hi)/2, begin, val);
  p->r = insert(p->r, (lo+hi)/2, hi, begin, val);

  return p;
}

int vrati(node *p, int lo, int hi, int begin, int end) {
  if (p == NIL || lo >= end || hi <= begin) return 0;
  if (lo >= begin && hi <= end) return p->val;
  return vrati(p->l, lo, (lo+hi)/2, begin, end) +
    vrati(p->r, (lo+hi)/2, hi, begin, end);  
}

int q(int l, int r) {
  return vrati(root[l-1], 0, TOUR, l, r+1);
}

int prv_poz[MAX];
int prv[MAX];
int p[MAX];
int n, k;
vector <int> Prevovi[MAX];
int dp[MAXK][MAX];
int piv[MAXK][MAX];

void sol1(int ind, int pos, int from, int to) {
  from = max(pos, from);
  int raz = q(pos, from-1);
  //  if (ind == 2 && pos == 1) TRACE(raz);
  
  FOR(i, from, to+1) {
    if (prv_poz[i] < pos) raz++;
    int nval = raz + dp[ind-1][i+1];

    // if (ind == 2 && pos == 1)
    //   TRACE(i _ raz _ nval);
    
    if (nval > dp[ind][pos]) {
      dp[ind][pos] = nval;
      piv[ind][pos] = i;
    }
  }
}

void rek(int ind, int lo, int hi, int from, int to) {
  if (lo > hi) return;
  int mid = (lo + hi) / 2;
  sol1(ind, mid, from, to);

  //  TRACE(ind _ mid _ from _ to);

  rek(ind, lo, mid-1, from, piv[ind][mid]);
  rek(ind, mid+1, hi, piv[ind][mid], to);
}

int main()
{
  NIL = new node{0, NIL, NIL};
  NIL->l = NIL->r = NIL;
  root[0] = new node{0, NIL, NIL};
  
  scanf("%d%d", &n, &k);

  FOR(i, 1, n+1) {
    scanf("%d", &p[i]);
    Prevovi[prv[p[i]]].push_back(i);

    //    TRACE(prv[p[i]] _ i);

    prv_poz[i] = prv[p[i]];
    prv[p[i]] = i;
  }

  for (int i=0; i<MAX; i++) {
    if (i) {
      root[i] = new node{0, NIL, NIL};
      *root[i] = *root[i-1];
    }
    for (auto it : Prevovi[i])
      root[i] = insert(root[i], 0, TOUR, it, 1);
  }

  REP(i, MAXK)
    REP(j, MAX)
    dp[i][j] = -INF;
  
  FOR(i, 1, n+1) {
    dp[1][i] = q(i, n);
    //    TRACE(dp[1][i]);
  }

  FOR(i, 2, k+1) {
    rek(i, 1, n, 1, n);
    
    // FOR(j, 1, n+1)
    //   TRACE(i _ j _ dp[i][j]);
  }

  printf("%d\n", dp[k][1]);
  
  return 0;
}