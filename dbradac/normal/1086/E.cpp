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

const int MAX = 2020;
const int MOD = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return (int) (((ll) a * b) % MOD);
}

int fak[MAX];
void gen_fak() {
  fak[0] = 1;
  FOR(i, 1, MAX) fak[i] = mul(fak[i-1], i);
}

int N;
int f[MAX][MAX];
int pot_fnn[MAX];

void calc_f() {
  REP(n, MAX) f[n][0] = fak[n];

  REP(n, MAX) {
    FOR(k, 1, n+1) {
      if (k > 1)
	f[n][k] = mul(k-1, f[n-1][k-2]);
      f[n][k] = add(f[n][k], mul(n-k, f[n-1][k-1]));      
    }
  }

  pot_fnn[0] = 1;
  FOR(i, 1, MAX)
    pot_fnn[i] = mul(pot_fnn[i-1], f[N][N]);
}

int p[MAX][MAX];

void stavi(int fen[], int pos, int val) {
  for (pos++; pos < MAX; pos += pos & -pos)
    fen[pos] += val;
}

int vrati(int fen[], int pos) {
  int ret=0;
  for (pos++; pos; pos -= pos & -pos)
    ret += fen[pos];
  return ret;
}

int fen[2][2][MAX];
int bio_gor[MAX], bio_dol[MAX];

void upd(int x, int st) {
  int a = bio_gor[x], b = bio_dol[x];
  stavi(fen[a][b], x, st);
}

int main()
{
  scanf("%d", &N);
  
  gen_fak();
  calc_f();  

  REP(i, N) REP(j, N) scanf("%d", &p[i][j]);
  
  int sol=0;
  REP(i, N) {
    memset(bio_gor, 0, sizeof bio_gor);
    memset(bio_dol, 0, sizeof bio_dol);
    memset(fen, 0, sizeof fen);
    FOR(x, 1, N+1) upd(x, 1); //stavi sve

    REP(j, N) {
      if (i) { //iznad mene
	upd(p[i-1][j], -1);
	bio_gor[p[i-1][j]] = 1;
	upd(p[i-1][j], 1);
      }

      
      int ja = p[i][j];
      int k = vrati(fen[0][0], MAX-5);

      if (i) upd(p[i-1][j], -1); //ovog iznad mene ne smijem stavit (1)

      int kolko;
      if (i) {
	kolko = add(mul(vrati(fen[1][0], ja-1), f[N-j-1][k]),
			mul(vrati(fen[0][0], ja-1), f[N-j-1][k-1]));
      }
      else
	kolko = mul(vrati(fen[0][0], ja-1), fak[N-j-1]);

      sol = add(sol, mul(kolko, pot_fnn[N-i-1]));
      
      if (i) upd(p[i-1][j], 1); //vrati (1)

      upd(p[i][j], -1);
      bio_dol[p[i][j]] = 1;
      upd(p[i][j], 1);
    }
  }

  printf("%d\n", sol);
  
  return 0;
}