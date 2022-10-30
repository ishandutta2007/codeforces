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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MOD = 1e9 + 7;

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

const int MAX = 5005, A = 30;

int dp[MAX][MAX];
int pref[MAX][MAX]; //dokle, zad
int pros[MAX];
char s[MAX];
int n;
vector <int> V[A];

int main()
{
  scanf("%d", &n);
  scanf(" %s", s+1);

  REP(i, A) V[i].push_back(-1);

  FOR(i, 1, n+1) {
    pros[i] = V[s[i]-'a'].back();
    V[s[i]-'a'].push_back(i);
  }
  
  REP(i, A)
    V[i].push_back(MAX-1);

  dp[1][1] = 1;
  pref[1][1] = 1;

  FOR(dokle, 1, n+1) {
    FOR(i, 1, n+1) {
      int nacin = sub(pref[dokle][i], pref[dokle][pros[i]+1]); //jer ne smije bit isto slovo
      if (dokle == 1 && pros[i] == -1) nacin = 1;

      dp[dokle+1][i+1] = add(dp[dokle+1][i+1], nacin);
    }

    if (dokle > 1)
      REP(i, MAX)
        dp[dokle+1][i] = add(dp[dokle+1][i], dp[dokle][i]);

    REP(i, MAX)
      pref[dokle+1][i] = add(dp[dokle+1][i], (i ? pref[dokle+1][i-1] : 0));
  }

  int rje = pref[n+1][MAX-2];
  printf("%d\n", rje);

  return 0;
}