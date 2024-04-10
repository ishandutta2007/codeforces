#include <cstdio>
#include <cassert>
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
const ll INF = 1e12;

ll dp[MAX][2]; //0 = incoming
vector <int> V[MAX];
int deg[MAX];
int t[MAX], h[MAX];
int n;

void rek(int node, int pr) {
  vector <ll> Raz;

  ll sum = 0;
  REP(i, (int) V[node].size()) {
    if (V[node][i] == pr) continue;

    int ch = V[node][i];
    rek(ch, node);

    Raz.push_back(dp[ch][1] - dp[ch][0]);
    sum += dp[ch][0];
  }
  
  sort(Raz.begin(), Raz.end(), greater<ll>());
  //start with all incoming  (all from me)
  
  dp[node][0] = dp[node][1] = -INF;
  REP(i, (int) Raz.size() + 1) {
    REP(st, 2) {
      int n_incoming = i + (st == 0 && node != 0);
      int n_outgoing = deg[node] - n_incoming;
      
      ll val = sum + (ll) min(n_incoming, n_outgoing) * t[node]; //no matched
      dp[node][st] = max(dp[node][st], val);
    }

    if (i != (int) Raz.size())
      sum += Raz[i];
  }

  if (node && h[pr] > h[node])
    dp[node][0] = -INF;
  if (node && h[pr] < h[node])
    dp[node][1] = -INF;
}

int main()
{
  ll sol = 0;
  scanf("%d", &n);

  REP(i, n) scanf("%d", &t[i]);
  REP(i, n) scanf("%d", &h[i]);

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  REP(i, n) deg[i] = (int) V[i].size();
  REP(i, n) sol += (ll) deg[i] * t[i];

  rek(0, 0);
  sol -= dp[0][0];

  printf("%lld\n", sol);

  return 0;
}