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

const int MOD = (int) 1e9 + 7;
const int mod = MOD;
const int MAX = 1<<19;

int mul(int a, int b) {
  return (int) (((ll) a * b) % mod);
}

int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

int pot(int b, int e) {
  int r=1;
  for (; e; e/=2, b=mul(b, b))
    if (e&1)
      r = mul(r, b);

  return r;
}

int inv(int x) {
  return pot(x, mod-2);
}

int fak[MAX], invfak[MAX];

void gen_f() {
  fak[0] = invfak[0] = 1;
  FOR(i, 1, MAX) {
    fak[i] = mul(i, fak[i-1]);
    invfak[i] = inv(fak[i]);
  }
}

int povrh(int a, int b) {
  if (a == -1 && b == -1) return 1;
  if (b < 0 || b > a) return 0;
  return mul(fak[a], mul(invfak[b], invfak[a-b]));
}

int broji(int cnt[2][2]) {
  if (!cnt[0][0] && !cnt[0][1] && !cnt[1][0] && !cnt[1][1]) return 1;
  REP(i, 2) REP(j, 2)
    if (cnt[i][j] < 0) return 0;

  int sm=0;
  REP(i, 2) REP(j, 2)
    sm += cnt[i][j];

  if (sm && !cnt[0][0] && !cnt[0][1]) return 0;
  if (!cnt[0][1] && (cnt[1][1] || cnt[1][0])) return 0;
  if (cnt[1][0] != cnt[0][1] && cnt[1][0] != cnt[0][1] - 1) return 0;

  int blok0 = 1 + cnt[1][0];
  int blok1 = cnt[0][1];
  int nula = blok0 + cnt[0][0];
  int jedan = blok1 + cnt[1][1];

  return mul(povrh(nula-1, blok0-1), povrh(jedan-1, blok1-1));
}

int go(int prvi, int poc, char *s, int jos, int cnt[2][2]) {
  if (!jos) return 0;

  int ret=0;
  if (s[0] == '0') {
    if (!prvi) cnt[poc][0]--;
    ret = add(ret, go(0, 0, s+1, jos-1, cnt));
    if (!prvi) cnt[poc][0]++;
  }
  else {
    if (!prvi) cnt[poc][1]--;
    ret = add(ret, go(0, 1, s+1, jos-1, cnt));
    if (!prvi) cnt[poc][1]++;

    if (!prvi) {
      cnt[poc][0]--;
      ret = add(ret, broji(cnt));
      cnt[poc][0]++;
    }
  }

  return ret;
}

int cnt[2][2];
char A[MAX], B[MAX];

int calc(char *s) {
  int sm=1;
  REP(i, 2) REP(j, 2)
    sm += cnt[i][j];

  if (sm < (int) strlen(s)) {
    swap(cnt[0][1], cnt[1][0]);
    swap(cnt[1][1], cnt[0][0]);
    int ret = broji(cnt);

    swap(cnt[0][1], cnt[1][0]);
    swap(cnt[1][1], cnt[0][0]);

    return ret;
  }
  if (sm > (int) strlen(s))
    return 0;

  return go(1, 1, s, (int) strlen(s), cnt);
}

int main()
{
  gen_f();

  scanf(" %s", A);
  scanf(" %s", B);
  REP(i, 2) REP(j, 2) scanf("%d", &cnt[i][j]);

  if (!cnt[0][0] && !cnt[0][1] && !cnt[1][0] && !cnt[1][1]) {
    if (strlen(A) == 1) printf("1\n");
    else printf("0\n");
    return 0;
  }

  int da=0;
  for (int i=(int) strlen(B)-1; i>=0; i--) {
    if (B[i] == '0') {
      B[i] = '1';
      da = 1;
      break;
    }
    else
      B[i] = '0';
  }
  if (!da) {
    for (int i=(int) strlen(B); i>0; i--)
      B[i] = B[i-1];
    B[0] = '1';
  }

  printf("%d\n", sub(calc(B), calc(A)));

  return 0;
}