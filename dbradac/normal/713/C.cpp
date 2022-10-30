#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int INF = 0x3f3f3f3f;
const int MAX = 3005;

vector <P> Dp[MAX];
int p[MAX];

void Spoji(int ind)
{
  vector <P> Nov;

  auto it = Dp[ind-1].begin(), pros = Dp[ind-1].begin();
  ll minn = 1e18;

  for (; it != Dp[ind-1].end(); it++) {
    if (it->X <= p[ind] || pros->X >= p[ind]) {
      minn = min(minn, it->Y);
      Dp[ind].push_back(P(it->X, minn + abs(p[ind] - it->X)));
    }
    else {
      ll val = pros->Y + (it->Y - pros->Y) / (it->X - pros->X) * (p[ind] - pros->X);
      minn = min(minn, val);

      Dp[ind].push_back(P(p[ind], minn));

      minn = min(minn, it->Y);
      Dp[ind].push_back(P(it->X, minn + abs(it->X - p[ind])));
    }

    pros = it;
  }
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    p[i] -= i;
  }

  Dp[0].push_back(P(-INF, abs(-INF - p[0])));
  Dp[0].push_back(P(p[0], 0));
  Dp[0].push_back(P(INF, abs(INF - p[0])));

  for (int i=1; i<n; i++)
    Spoji(i);

  ll rje = 1e18;
  for (auto it : Dp[n-1])
    rje = min(rje, it.Y);

  printf("%lld\n", rje);

  return 0;
}