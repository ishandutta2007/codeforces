#include <cstdio>
#include <ctime>
#include <unistd.h>
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

const int MAX = 1<<18;
int MOD;
int pola;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;  
}

int mul(int a, int b) {
  return (int) (((ll) a * b) % MOD);
}

int eksp(int b, int e) {
  int r=1;
  for (; e; e /= 2, b = mul(b, b))
    if (e & 1) r = mul(r, b);
  return r;
}

int invv(int x) { return eksp(x, MOD-2); }
int divv(int a, int b) { return mul(a, invv(b)); }

int pref_naz[MAX];
int bio=0;
int get_sum_fast(int k, int l) {
  if (!bio++) {
    pref_naz[0] = 0;
    FOR(i, 1, MAX)
      pref_naz[i] = add(pref_naz[i-1], invv(i));
  }

  int ret=0;
  FOR(i, 1, k+1)
    ret = add(ret, mul(i-1, sub(pref_naz[i+l], pref_naz[i])));

  return ret;
}

int n, k;
int vel[2];
int cnt[2];

void get_cnt(int sz, int jos) {
  if (!jos) {
    assert(sz == vel[0] || sz == vel[1]);
    cnt[sz-vel[0]]++;
    return;
  }

  get_cnt(sz / 2, jos-1);
  get_cnt((sz+1)/2, jos-1);
}

int fak[MAX], invfak[MAX];
void gen_fak() {
  fak[0] = invfak[0] = 1;
  FOR(i, 1, MAX) {
    fak[i] = mul(i, fak[i-1]);
    invfak[i] = invv(fak[i]);
  }
}

int povrh(int a, int b) {
  if (a < b || b < 0) return 0;
  return mul(fak[a], mul(invfak[b], invfak[a-b]));  
}

int main()
{
  srand(time(0) * getpid());
  scanf("%d%d%d", &n, &k, &MOD); k--;
  
  gen_fak();
  pola = invv(2);
  
  if (k >= 25 || (1<<k) >= n) {
    printf("0\n");
    return 0;
  }

  vel[0] = n / (1<<k);
  vel[1] = vel[0] + 1;

  get_cnt(n, k);

  int sol = 0;
  REP(i, 2) //oba u istom
    sol = add(sol, mul(mul(cnt[i], povrh(vel[i], 2)), pola));

  REP(i, 2) REP(j, 2) {
    int koef;
    if (i == j) koef = mul(cnt[i], cnt[i]-1);
    else koef = mul(cnt[0], cnt[1]);
    sol = add(sol, mul(koef, mul(get_sum_fast(vel[i], vel[j]), pola)));
  }

  printf("%d\n", sol);
  
  return 0;
}