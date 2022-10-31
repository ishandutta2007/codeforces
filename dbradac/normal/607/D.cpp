#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int TOUR = 1<<18, MOD = 1e9 + 7;

int Add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int Sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int Mul(int a, int b)
{
  return (int) (((long long) a * b) % MOD);
}

int Inverz(int x)
{
  int ret=1;
  for (int e=MOD-2; e; e /= 2, x = Mul(x, x))
    if (e & 1)
      ret = Mul(ret, x);
  return ret;
}

int Div(int a, int b)
{
  return Mul(a, Inverz(b));
}

struct node {
  int sum, mul, prop;
};

struct tour {
  node t[2*TOUR];

  tour() {
    for (int i=0; i<2*TOUR; i++) {
      t[i].sum = 0;
      t[i].mul = t[i].prop = 1;
    }
  }

  void propagiraj(int x) {
    for (int i=2*x; i<=2*x+1; i++) {
      t[i].sum = Mul(t[i].sum, t[x].prop);
      t[i].mul = Mul(t[i].mul, t[x].prop);
      t[i].prop = Mul(t[i].prop, t[x].prop);
    }

    t[x].prop = 1;
  }

  void stavi_sum(int pos, int lo, int hi, int ind, int val) {
    if (lo >= ind + 1 || hi <= ind)
      return;
    if (lo == ind && hi == ind + 1) {
      t[pos].sum = Mul(t[pos].mul, val);
      return;
    }

    propagiraj(pos);
    stavi_sum(2*pos+0, lo, (lo+hi)/2, ind, val);
    stavi_sum(2*pos+1, (lo+hi)/2, hi, ind, val);
    t[pos].sum = Add(t[2*pos].sum, t[2*pos+1].sum);
  }

  void stavi_sum(int pos, int val) {
    stavi_sum(1, 0, TOUR, pos, val);
  }

  void stavi_mul(int pos, int lo, int hi, int begin, int end, int val) {
    if (lo >= end || hi <= begin)
      return;
    if (lo >= begin && hi <= end) {
      t[pos].sum = Mul(t[pos].sum, val);
      t[pos].mul = Mul(t[pos].mul, val);
      t[pos].prop = Mul(t[pos].prop, val);
      return;
    }

    propagiraj(pos);
    stavi_mul(2*pos+0, lo, (lo+hi)/2, begin, end, val);
    stavi_mul(2*pos+1, (lo+hi)/2, hi, begin, end, val);
    t[pos].sum = Add(t[2*pos].sum, t[2*pos+1].sum);
  }

  void stavi_mul(int begin, int end, int val) {
    stavi_mul(1, 0, TOUR, begin, end, val);
  }

  int query_sum(int pos, int lo, int hi, int begin, int end) {
    if (lo >= end || hi <= begin)
      return 0;
    if (lo >= begin && hi <= end)
      return t[pos].sum;

    propagiraj(pos);
    return Add(query_sum(2*pos+0, lo, (lo+hi)/2, begin, end),
               query_sum(2*pos+1, (lo+hi)/2, hi, begin, end));
  }

  int query_sum(int begin, int end) {
    return query_sum(1, 0, TOUR, begin, end);
  }

  int query_mul(int pos, int lo, int hi, int ind) {
    if (lo >= ind + 1 || hi <= ind)
      return 0;
    if (lo == ind && hi == ind + 1)
      return t[pos].mul;

    propagiraj(pos);
    return Add(query_mul(2*pos+0, lo, (lo+hi)/2, ind),
               query_mul(2*pos+1, (lo+hi)/2, hi, ind));
  }

  int query_mul(int ind) {
    return query_mul(1, 0, TOUR, ind);
  }
} T;

vector <int> V[TOUR];
P ev[TOUR];
int disc[TOUR], fin[TOUR], vr=1;
int pocval[TOUR], par[TOUR];
int brdjec[TOUR];

void Dfs(int node)
{
  disc[node] = vr++;
  for (int i=0; i<(int) V[node].size(); i++)
    Dfs(V[node][i]);
  fin[node] = vr;
}

void Dodaj(int node)
{
  int p = par[node];
  
  T.stavi_mul(disc[p], fin[p], Mul(Inverz(brdjec[p]), brdjec[p] + 1));
  T.stavi_sum(disc[node], pocval[node]);
  brdjec[p]++;
}

int Query(int node)
{
  int ret = T.query_sum(disc[node], fin[node]);
  if (node)
    ret = Div(ret, T.query_mul(disc[par[node]]));
  return ret;
}

int main()
{
  int brq, brcv=1;

  scanf("%d%d", &pocval[0], &brq);

  for (int i=0; i<brq; i++) {
    int st;
    scanf("%d", &st);
    if (st == 2) {
      int tmp;
      scanf("%d", &tmp); tmp--;
      ev[i] = P(st, tmp);
    }
    else {
      scanf("%d%d", &par[brcv], &pocval[brcv]); par[brcv]--;
      V[par[brcv]].push_back(brcv);
      ev[i] = P(st, brcv++);
    }
  }

  Dfs(0);
  T.stavi_sum(disc[0], pocval[0]);

  for (int i=0; i<brcv; i++)
    brdjec[i] = 1;

  for (int i=0; i<brq; i++) {
    if (ev[i].X == 1)
      Dodaj(ev[i].Y);
    else
      printf("%d\n", Query(ev[i].Y));  }

  return 0;
}