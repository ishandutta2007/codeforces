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

const int MOD = 1e9 + 7;

int add(int a, int b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
  return a;
}

int sub(int a, int b)
{
  a -= b;
  if (a < 0)
    a += MOD;
  return a;
}

int mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int pot(int x, int e)
{
  int r = 1;
  for (; e; x = mul(x, x), e /= 2)
    if (e & 1)
      r = mul(r, x);
  return r;
}

int inv(int x)
{
  return pot(x, MOD - 2);
}

int divv(int a, int b)
{
  return mul(a, inv(b));
}

const int DIM = 2;

typedef long long llint;

struct Matrix {
  int a[DIM][DIM];
  int *operator [] (int r) { return a[r]; };

  Matrix(int x = 0) {
    memset(a, 0, sizeof a);
    if (x) REP(i, DIM) a[i][i] = x;
  }
} const I(1);

Matrix operator * (Matrix A, Matrix B) {
  const llint mod2 = llint(MOD) * MOD;
  Matrix C;
  REP(i, DIM) REP(j, DIM) {
    llint w = 0;
    REP(k, DIM) {
      w += llint(A[i][k]) * B[k][j];
      if (w >= mod2) w -= mod2;
    }
    C[i][j] = (int) (w % MOD);
  }
  return C;
}

Matrix operator ^ (Matrix A, llint b) {
  Matrix R = I;
  for (; b > 0; b /= 2) {
    if (b % 2) R = R*A;
    A = A*A;
  }
  return R;
}

Matrix operator + (Matrix A, Matrix B)
{
  Matrix C;
  REP(i, DIM) REP(j, DIM)
    C[i][j] = add(A[i][j], B[i][j]);
  return C;
}

const int TOUR = 1<<17;
const int MAX = TOUR;

Matrix potfib[105];
Matrix id, nula;

int p[MAX], n;
int brq, st[MAX], l[MAX], r[MAX], q_val[MAX];

struct tour {
  Matrix prop;
  Matrix val;
} t[2*TOUR];

void propagiraj(int pos)
{
  FOR(i, 2*pos, 2*pos+2) {
    t[i].prop = t[i].prop * t[pos].prop;
    t[i].val = t[i].val * t[pos].prop;
  }
  t[pos].prop = id;
}

void load()
{
  scanf("%d%d", &n, &brq);
  REP(i, n) { scanf("%d", &p[i]); p[i]--; }
  //  scanf("%d", &brq);
  REP(i, brq) {
    scanf("%d%d%d", &st[i], &l[i], &r[i]); l[i]--; r[i]--;
    if (st[i] == 1) scanf("%d", &q_val[i]);
  }
}

void init()
{
  REP(i, 2*TOUR) t[i].prop = id;
  REP(i, n) t[i+TOUR].val = potfib[1] ^ p[i];
  FOR(i, n, TOUR) t[i+TOUR].val = nula;
  for (int i=TOUR-1; i; i--)
    t[i].val = t[2*i].val + t[2*i+1].val;

  //  REP(i, 2) REP(j, 2) TRACE(i _ j _ t[1].val.a[i][j]);
}

int vrati(int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin) return 0;
  if (lo >= begin && hi <= end)
    return add(t[pos].val[0][0], t[pos].val[0][1]);
  propagiraj(pos);
  return add(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
	     vrati(2*pos+1, (lo+hi)/2, hi, begin, end));
}

void stavi(int pos, int lo, int hi, int begin, int end, Matrix val)
{
  if (lo >= end || hi <= begin) return;
  if (lo >= begin && hi <= end) {
    t[pos].prop = t[pos].prop * val;
    t[pos].val = t[pos].val * val;
    return;
  }

  propagiraj(pos);
  stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  t[pos].val = t[2*pos].val + t[2*pos+1].val;
}

void solve()
{
  init();
  REP(i, brq) {
    if (st[i] == 2)
      printf("%d\n", vrati(1, 0, TOUR, l[i], r[i] + 1));
    else
      stavi(1, 0, TOUR, l[i], r[i] + 1, potfib[1] ^ q_val[i]);
  }
}

int main()
{
  REP(i, DIM) id[i][i] = 1;
  
  potfib[0] = id;
  potfib[1].a[0][0] = 0;
  potfib[1].a[0][1] = 1;
  potfib[1].a[1][0] = 1;
  potfib[1].a[1][1] = 1;

  int brt=1;
  //  scanf("%d", &brt);

  for (; brt--; ) {
    load();
    solve();
  }
  
  return 0;
}