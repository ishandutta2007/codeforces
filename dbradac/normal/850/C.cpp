#include <cstdio>
#include <map>
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

const int MAX = 1<<20;

int dp[MAX];

int sg(int mask) {
  if (!mask) return 0;
  if (mask < MAX && dp[mask] != -1) return dp[mask];
  
  int ima[34];
  memset(ima, 0, sizeof ima);

  FOR(i, 1, 32) {
    if (mask < (1<<(i-1))) break;
    int nmask = (mask >> i) | (mask & ((1<<(i-1)) - 1));
    ima[sg(nmask)] = 1;
  }
  REP(i, 34) {
    if (!ima[i]) {
      if (mask < MAX) dp[mask] = i;
      //      TRACE(mask _ i);
      return i;
    }
  }

  assert(0);
}

map <int, int> M;
int p[105], n;

int get_mask(int pr) {
  int ret = 0;
  REP(i, n) {
    int pot = 0;
    for (int tmp=p[i]; !(tmp % pr); tmp /= pr)
      pot++;
    
    if (pot)
      ret |= 1<<(pot-1);
  }

  //  TRACE(pr _ ret);
  return ret;
}

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", &p[i]);
  memset(dp, -1, sizeof dp);

  int rje = 0;
  REP(i, n) {
    for (int j=2; j*j <= p[i]; j++) {
      if (!(p[i] % j)) {
	int msk = get_mask(j);
	for (; !(p[i] % j); p[i] /= j);
	if (M[j]++) continue;
	rje ^= sg(msk);
      }
    }

    if (p[i] != 1)
      if (!M[p[i]]++)
	rje ^= sg(get_mask(p[i]));
  }

  printf("%s\n", rje ? "Mojtaba" : "Arpa");

  return 0;
}