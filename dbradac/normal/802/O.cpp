#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef pair<ll, ll> P;

const int MAX = 1<<19;

int a[MAX], b[MAX], n, k;

P calc(ll x) {
  ll cnt=0, val=0;
  priority_queue <ll> Qa, Qb;
  
  REP(i, n) {
    Qa.push(-a[i]);

    ll stav = b[i] + x + (-Qa.top());
    ll prom = Qb.empty() ? (ll) (1e18) : b[i] - Qb.top();

    if (stav < prom && stav < 0) {
      cnt++, val += stav;
      Qa.pop();
      Qb.push(b[i]);
    }
    else if (prom < 0) {
      val += prom;
      Qb.pop();
      Qb.push(b[i]);
    }
  }

  return {cnt, val};
}

int main()
{
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n) scanf("%d", &b[i]);

  ll lo = -1e12, hi = 1e12;
  for (; lo<hi; ) {
    ll mid = (lo + hi) / 2;
    if (hi < 0) mid = (lo + hi - 1) / 2;

    if (calc(mid).X > k) lo = mid + 1;
    else hi = mid;
  }

  printf("%lld\n", calc(lo).Y - lo * k);

  return 0;
}