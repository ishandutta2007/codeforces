#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 1<<18;
const ll INF = 1e18;
const int MIL = 1e9;

ll blog, com;
int p[MAX];
int n, treb;
ll za5;
deque <int> Q[5][5];
int kol[5][5];
ll sum[5][5];

ll EvalJednog(int on, int t)
{
  return za5 * ((t - on) / 5) + ((t - on) % 5) * (ll) com;
}

void Izbaci(int ind)
{
  P maxx = P(-INF, -INF);

  for (int i=0; i<5; i++)
    if (!Q[ind][i].empty())
      maxx = max(maxx, P(EvalJednog(Q[ind][i].front(), 2 * MIL + ind), i));

  kol[ind][maxx.Y]--;
  sum[ind][maxx.Y] -= Q[ind][maxx.Y].front();
  Q[ind][maxx.Y].pop_front();
}

ll Eval(int t)
{
  int ost = t % 5;
  ll ret = 0;
  
  for (int i=0; i<5; i++) {
    int dod = ((ost - i + 5) % 5);
    ret += (ll) kol[ost][i] * dod * com;
    ret += (((ll) t * kol[ost][i]) - (sum[ost][i] + (ll) kol[ost][i] * dod)) / 5 * za5;    
  }
    
  return ret;
}

int main()
{
  scanf("%d%d%lld%lld", &n, &treb, &blog, &com);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    p[i] += MIL;
  }

  sort(p, p + n);
  za5 = (ll) min(5 * com, blog);

  ll rje = INF;
  for (int i=0; i<n; i++) {
    for (int j=0; j<5; j++) {
      kol[j][p[i] % 5]++;
      sum[j][p[i] % 5] += p[i];
      Q[j][p[i] % 5].push_back(p[i]);

      if (i >= treb)
        Izbaci(j);
    }

    if (i >= treb - 1)
      for (int j=p[i]; j<p[i]+5; j++)
        rje = min(rje, Eval(j));

  }
  
  printf("%lld\n", rje);

  return 0;
}