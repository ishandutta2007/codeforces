#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<18;

int cntpot[MAX][50];

void rastav(int x) {
  for (int i=2; i*i <= x; i++) {
    if ((x % i == 0)) {
      int pot = 0;
      while(!(x % i)) {
        pot++;
        x /= i;
      }

      cntpot[i][pot]++;
    }
  }

  if (x > 1) cntpot[x][1]++;
}

int main()
{
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    rastav(x);
  }

  ll ret=1;
  FOR(i, 2, MAX) {
    int sum=0;
    REP(j, 50) sum += cntpot[i][j];
    cntpot[i][0] = n-sum;
    
    int jos=2;
    ll val=1;
    REP(j, 50) {
      REP(k, cntpot[i][j]) {
        if (jos) {
          jos--;
          if (!jos)
            ret *= val;
        }
      }

      if (!jos) break;
      val *= i;
    }
  }

  printf("%lld\n", ret);

  return 0;
}