#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<18, INF = 0x3f3f3f3f;

vector <int> V[MAX];
int dp[MAX][2];

void Rek(int node, int prosli)
{
  int sum0 = 0;
  dp[node][0] = dp[node][1] = 1;
  vector <int> S;

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli) {
      Rek(nn, node);
      S.push_back(dp[nn][1] - dp[nn][0]);
      sum0 += dp[nn][0];
    }
  }

  sort(S.begin(), S.end());

  dp[node][0] = sum0 + 1;
  dp[node][1] = sum0 + 1;

  if (S.size() > 1)
    dp[node][0] = min(dp[node][0], sum0 + S[0] + S[1] - 1);
  if (S.size())
    dp[node][1] = min(dp[node][1], sum0 + S[0]);

  dp[node][0] = min(dp[node][0], dp[node][1]);
}

int main()
{
  int n, x, y;

  scanf("%d%d%d", &n, &x, &y);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  if (x >= y) {
    int md = 0;
    for (int i=0; i<n; i++)
      md = max(md, (int) V[i].size());

    if (md == n - 1)
      printf("%lld\n", ((ll) n - 2) * y + x);
    else
      printf("%lld\n", ((ll) n - 1) * y);
    return 0;
  }

  Rek(0, -1);
  int tmp = dp[0][0];
  printf("%lld\n", ((ll) n - 1) * x + ((ll) tmp - 1) * (y - x));

  return 0;
}