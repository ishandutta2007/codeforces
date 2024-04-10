#include <cstdio>
#include <set>
#include <map>
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

const int MAX = 1<<19, TOUR = 1<<19, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int val[MAX], st[MAX];
set <int> S;

void nope() {
  printf("0\n");
  exit(0);
}

char s[20];
map <int, int> Buy, Sell;
map <int, int> M;

int main()
{
  scanf("%d", &n);

  REP(i, n) {
    scanf(" %s%d", s, &val[i]);
    if (s[1] == 'C')
      st[i] = 1;
  }

  int nac = 1;
  int buy = -1, sell = -1;

  REP(i, n) {
    if (!st[i]) {
      S.insert(val[i]);
      if (buy != -1 && buy >= val[i]) Buy[val[i]] = 1;
      if (sell != -1 && sell <= val[i]) Sell[val[i]] = 1;
      M[val[i]] = i;
    }
    else {
      if (buy != -1 && buy >= val[i]) Buy[val[i]] = 1;
      if (sell != -1 && sell <= val[i]) Sell[val[i]] = 1;
      if (!Buy[val[i]] && !Sell[val[i]]) nac = (nac * 2) % MOD;

      S.erase(val[i]);

      int tmp = sell;
      if (tmp == -1 || val[i] < tmp) tmp = val[i];

      auto it = S.lower_bound(tmp);
      if (it != S.end())
        sell = *it;
      else sell = -1;

      tmp = buy;
      if (tmp == -1 || val[i] > tmp) tmp = val[i];
      it = S.lower_bound(tmp);

      if (it != S.begin()) {
        it--;
        buy = *it;
      }
      else buy = -1;

      M[val[i]] = -1;
    }
  }

  int izmedu = 0;
  for (auto it = M.begin(); it != M.end(); it++) {
    int vl = it->first;
    if (it->second != -1) {
      if ((buy == -1 || vl > buy) && (sell == -1 || vl < sell))
        izmedu++;

      if (buy != -1 && buy >= vl) Buy[vl] = 1;
      if (sell != -1 && sell <= vl) Sell[vl] = 1;
    }
  }

  nac = (int) (((ll) nac * (izmedu+1)) % MOD);

  REP(i, n) if (Buy[val[i]] && Sell[val[i]]) nope();

  printf("%d\n", nac);

  return 0;
}