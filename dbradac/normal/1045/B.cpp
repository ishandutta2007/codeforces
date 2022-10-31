#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MOD[2] = {(int) 1e9 + 7, (int) 1e9 + 9}, H[2] = {101, 3137};

int mul(int a, int b, int mod) {
  return (int) (((ll) a * b) % mod);
}

int add(int a, int b, int mod) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int sub(int a, int b, int mod) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

int pot(int b, int e, int mod) {
  int r=1;
  for (; e; e/=2, b=mul(b, b, mod))
    if (e&1)
      r = mul(r, b, mod);

  return r;
}

int inv(int x, int mod) {
  return pot(x, mod-2, mod);
}

vector <int> V, R;

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  REP(i, n) {
    int x;
    scanf("%d", &x);
    V.push_back(x);
    R.push_back(m-x-1);
  }
  reverse(R.begin(), R.end());

  int h_V[2] = {0, 0};

  REP(i, 2)
    REP(j, n)
      h_V[i] = add(h_V[i], pot(H[i], V[j], MOD[i]), MOD[i]);

  vector <int> H_B[2];
  REP(i, 2) H_B[i].push_back(0);

  REP(i, 2) {
    REP(j, n) {
      H_B[i].push_back(add(H_B[i].back(), pot(H[i], R[j], MOD[i]), MOD[i]));
    }
  }
  
  vector <int> Rez;
  
  REP(i, n) { //spari prvog u V s i-tim u R
    int sh = (int) (((ll) m + V[0] - R[i]) % m);
    int zadnji_preko = (int) (lower_bound(R.begin(), R.end(), m-sh) - R.begin());

    int th[2] = {0, 0};
    REP(j, 2) {
      int preko = sub(H_B[j].back(), H_B[j][zadnji_preko], MOD[j]);
      int nepreko = H_B[j][zadnji_preko];
      int potnepreko = pot(H[j], sh, MOD[j]);
      int potpreko = inv(pot(H[j], m-sh, MOD[j]), MOD[j]);

      th[j] = add(mul(preko, potpreko, MOD[j]), mul(nepreko, potnepreko, MOD[j]), MOD[j]);
    }

    if (th[0] == h_V[0] && th[1] == h_V[1])
      Rez.push_back((sh + m - 1) % m);
  }

  sort(Rez.begin(), Rez.end());
  printf("%d\n", (int) Rez.size());
  for (auto it : Rez)
    printf("%d ", it);
  printf("\n");

  return 0;
}