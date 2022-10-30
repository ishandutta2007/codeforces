#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> P;
typedef long double lf;

const int MAX = 1<<17;
const lf EPS = 1e-4;

lf ccw(const P &a, const P &b, const P &c)
{
  return (lf) a.X * (b.Y - c.Y) + (lf) b.X * (c.Y - a.Y) + (lf) c.X * (a.Y - b.Y);
}

vector <P> Hull;
ll dp[MAX];
int n;
int a[MAX], b[MAX];
int ind=0;

void dodaj(const P &tmp)
{
  for (; Hull.size() > 1 && ccw(Hull[Hull.size()-2], Hull.back(), tmp) > -EPS; )
    Hull.pop_back();
  Hull.push_back(tmp);
}

ll eval(P toc, ll x)
{
  return toc.X * x + toc.Y;
}

ll query(ll x)
{
  ind = min(ind, (int) Hull.size() - 1);
  for (; ind < (int) Hull.size() - 1 && eval(Hull[ind], x) >= eval(Hull[ind+1], x); ind++);
  return eval(Hull[ind], x);
}

int main()
{
  scanf("%d", &n);
  REP(i, n)
    scanf("%d", &a[i]);
  REP(i, n)
    scanf("%d", &b[i]);

  dp[0] = 0;
  dodaj(P(b[0], dp[0]));

  FOR(i, 1, n) {
    dp[i] = query(a[i]);
    dodaj(P(b[i], dp[i]));
  }

  printf("%lld\n", dp[n-1]);

  return 0;
}