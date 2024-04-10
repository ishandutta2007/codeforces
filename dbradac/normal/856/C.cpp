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

const int MAXF = 1<<14;
const int MOD = 998244353;

int fak[MAXF], invfak[MAXF];

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

void genfak()
{
  fak[0] = invfak[0] = 1;
  for (int i=1; i<MAXF; i++) {
    fak[i] = mul(fak[i-1], i);
    invfak[i] = inv(fak[i]);
  }
}

int povrh(int a, int b)
{
  if (a < b || b < 0)
    return 0;
  return mul(fak[a], mul(invfak[b], invfak[a-b]));
}

const int M = 11;
const int MAX = 2005;

vector <int> Parni, Neparni;

int dp_parni[MAX][MAX][M], dp_neparni[MAX][MAX][M];

void gen_dp(const vector <int> &V, int dp[MAX][MAX][M]) {
  int n = (int) V.size();
  REP(i, n+2) REP(j, n+2) REP(k, M) dp[i][j][k] = 0;
  dp[0][0][0] = 1;

  REP(i, n) {
    REP(stav, n) {
      REP(ost, M) {
	int ja = dp[i][stav][ost];
	dp[i+1][stav][(ost + V[i]) % M] = add(dp[i+1][stav][(ost + V[i]) % M], ja);
	dp[i+1][stav+1][(ost + M - V[i]) % M] = add(dp[i+1][stav+1][(ost + M - V[i]) % M], ja);
      }      
    }
  }
}


int main()
{
  genfak();
  
  int brt;
  scanf("%d", &brt);

  for (; brt--; ) {
    Parni.clear();
    Neparni.clear();

    int n; 
    scanf("%d", &n);

    REP(i, n) {
      int x;
      scanf("%d", &x);
      int brz = 0;
      for (int tmp=x; tmp; tmp/=10, brz++);
      if (brz % 2) Neparni.push_back(x % M);
      else Parni.push_back(x % M);
    }
    
    gen_dp(Parni, dp_parni);
    gen_dp(Neparni, dp_neparni);

    int rje = 0;
    int parna_mjesta = 1 + ((int) Neparni.size() / 2);    
    int neparna_mjesta = (1 + (int) Neparni.size()) / 2;
    int uk_par = (1 + (int) Neparni.size()) / 2;
    int uk_nep = (int) Neparni.size() / 2;

    REP(nep, (int) Parni.size() + 1) {
      int par = (int) Parni.size() - nep;
      int koef = mul(mul(fak[nep], fak[par]), mul(fak[uk_par], fak[uk_nep]));
      koef = mul(koef, povrh(par + parna_mjesta - 1, parna_mjesta - 1));
      if (nep)
	koef = mul(koef, povrh(nep + neparna_mjesta - 1, neparna_mjesta - 1));
      //      TRACE(nep _ koef _ nep + neparna_mjesta - 1 _ neparna_mjesta - 1 _ povrh(nep + neparna_mjesta - 1, neparna_mjesta - 1));


      int dod = 0;
      REP(ost, M)
	dod = add(dod, mul(dp_neparni[(int) Neparni.size()][uk_nep][ost], dp_parni[(int) Parni.size()][nep][(M - ost) % M]));

      rje = add(rje, mul(koef, dod));
    }    

    printf("%d\n", rje);
  }

  return 0;
}