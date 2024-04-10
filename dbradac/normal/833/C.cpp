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
typedef unsigned long long ull;

ull A, B;
int tmp_cnt[10];
int znamA[20], znamB[20];
ull pot10[20];

int check() {
  int cnt[10];  
  memcpy(cnt, tmp_cnt, sizeof cnt);
  int uk=0;
  FOR(i, 1, 10) uk += cnt[i];
  cnt[0] = 300;

  int okB = 0, okA = 0;
  
  for (int i=19; i>=0; i--) {   
    int a = znamA[i], b = znamB[i];
    
    //    TRACE(i _ a _ b _ okA _ okB _ uk);
    if (uk > i+1) break;
    
    if (!okA) {
      if (b < a)
	break;

      FOR(zn, a+1, b)
	if (cnt[zn] && (zn || uk <= i))
	  return 1;
      
      if (cnt[b]) {
	cnt[b]--;
	if (b) uk--;
	okA |= b > a;
      }
      else {
	if (!cnt[a]) break;
	cnt[a]--;
	if (a) uk--;
	okB |= b > a;
      }
    }
    else {
      REP(zn, b)
	if (cnt[zn] && (zn || uk <= i))
	  return 1;

      if (cnt[b]) {
	cnt[b]--;
	if (b) uk--;	
      }
      else
	break;
    }
  }

  if (okA && okB && !uk) return 1;
    //  if (okA && okB) return 1;

  memcpy(cnt, tmp_cnt, sizeof cnt);
  uk=0;
  FOR(i, 1, 10) uk += cnt[i];
  cnt[0] = 300;

  okB = 0, okA = 0;

  //  TRACE("KURCINA");
  for (int i=19; i>=0; i--) {
    int a = znamA[i], b = znamB[i];

    //TRACE(i _ a _ b _ okA _ okB _ uk);
    if (uk > i+1) break;
    
    if (!okB) {
      if (b < a)
	break;

      FOR(zn, a+1, b)
	if (cnt[zn] && (zn || uk <= i))
	  return 1;

      if (cnt[a]) {
	cnt[a]--;
	if (a) uk--;
	okB |= b > a;
      }
      else {
	if (!cnt[b]) break;
	cnt[b]--;
	if (b) uk--;
	okA |= b > a;
      }
    }
    else {
      FOR(zn, a+1, 10)
	if (cnt[zn] && (zn || uk <= i))
	  return 1;

      if (cnt[a]) {
	cnt[a]--;
	if (a) uk--;	
      }
      else
	break;
    }
  }

  //  TRACE(okA _ okB);
  if (okA && okB && !uk) return 1;
  return 0;
}

int ret=0;
void rek(int zn, int imam) {
  if (zn >= 10) {
    int tmp = check();
    ret += tmp;
    return;

    //ret += check();
    // if (tmp) {
    //   TRACE("GAGA");
    //   REP(i, 10)
    // 	REP(j, tmp_cnt[i])
    // 	TRACE(i);
    // }
    
    return;
  }
  rek(zn+1, imam);

  if (imam < 18) {//asoifjoasjfiowaeapsfrkpawekf pkwepofk poawekf poawkxb
    tmp_cnt[zn]++;
    rek(zn, imam+1);
    tmp_cnt[zn]--;
  }
}

void gen_zn(ull x, int p[20]) {
  REP(i, 20)
    p[i] = (int) ((x / pot10[i]) % 10);
}

int main()
{
  pot10[0] = 1;
  FOR(i, 1, 20)
    pot10[i] = pot10[i-1] * 10;
  
  cin >> A >> B;
  A--;
  B++;
  gen_zn(A, znamA);
  gen_zn(B, znamB);

  // REP(i, 5)
  //   TRACE(i _ znamA[i]);
  
  rek(1, 0);
  printf("%d\n", ret);
   
  //  tmp_cnt[2] = tmp_cnt[3] = 1;
  
  // //  tmp_cnt[1] = tmp_cnt[2] = 1;
  // TRACE(check());

  return 0;
}