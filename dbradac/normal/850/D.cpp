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

const int MAXN = 67;

int dp[2][MAXN/2][MAXN][MAXN*MAXN/2];
int ima[MAXN];

void go_dp() {
  memset(dp, 0, sizeof dp);

  dp[0][0][0][0] = 1;
  REP(ind, 32) {
    REP(broj, MAXN-2) {
      REP(sum, MAXN*MAXN/2 - 35) {
	REP(st, 2) {
	  if (!dp[st][ind][broj][sum]) continue;

	  if (!ima[ind] || st) 
	    dp[0][ind+1][broj][sum] = 1;
	  if (ima[ind] && sum + ind >= broj * (broj + 1) / 2)
	    dp[1][ind][broj+1][sum + ind] = 1;
	} 
      }
    }
  }
}

void solve(int n) {
  int ind = 32, broj = n, sum = n * (n - 1) / 2;
  vector <int> T;

  for (; broj; ) {
    if (ima[ind] && dp[1][ind][broj-1][sum - ind]) {
      T.push_back(ind);
      broj--;
      sum -= ind;
    }
    else if (ima[ind] && dp[0][ind][broj-1][sum - ind]) {
      T.push_back(ind);
      broj--;
      sum -= ind;
    }
    else {
      assert(ind && dp[ima[ind-1]][ind-1][broj][sum]);
      ind--;
    }
  }

  assert((int) T.size() == n);

  sort(T.begin(), T.end());

  int e[n][n];
  memset(e, 0, sizeof e);

  int outd[n], indd[n];
  REP(i, n) {
    outd[i] = T[i];
    indd[i] = n - 1 - T[i];
  }

  REP(i, n) {
    if (i == n-1) assert(!indd[i] && !outd[i]);
    int bio[MAXN];
    memset(bio, 0, sizeof bio);

    for (; indd[i]; ) {
      int bst = -1;
      REP(j, n)
	if (!bio[j] && j != i && (bst == -1 || outd[j] > outd[bst]) && !e[j][i])
	  bst = j;

      assert(outd[bst] && !bio[bst]);

      e[bst][i] = 1;
      outd[bst]--;
      indd[i]--;
      bio[bst] = 1;
    }
    
    REP(j, n) {
      if (!e[j][i] && !e[i][j] && i != j) {
	e[i][j] = 1;
	outd[i]--;
	indd[j]--;
      }
    }

    assert(indd[i] == 0 && outd[i] == 0);
  }

  printf("%d\n", n);
  REP(i, n) {
    REP(j, n)
      printf("%c", (char) ('0' + e[i][j]));
    printf("\n");
  }
}

int main()
{
  int m;
  scanf("%d", &m);
  
  int mx = -1;
  REP(i, m) {
    int x;
    scanf("%d", &x);
    ima[x] = 1;
    mx = max(mx, x);
  }

  go_dp();
  FOR(n, mx+1, MAXN) {
    if (dp[0][32][n][n * (n-1) / 2]) {
      solve(n);
      return 0;
    }
  }  

  printf("=(\n");  

  return 0;
}