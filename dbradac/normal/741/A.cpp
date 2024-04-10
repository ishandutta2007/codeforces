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
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 105;

ll lcm(ll a, ll b)
{
  ll g = __gcd(a, b);
  return a / g * b;
}

int n;
int p[MAX];
vector <P> Cik;
int indeg[MAX];
int bio[MAX];

void nope()
{
  printf("-1\n");
  exit(0);
}

void vrti()
{
  REP(i, n)
    indeg[p[i]]++;
  REP(i, n)
    if (!indeg[i])
      nope();

  ll rje = 1;
  REP(i, n) {
    if (bio[i]) continue;
    int tmp = i, sz = 0;
    for (; tmp != i || !sz; sz++, tmp = p[tmp]);
    tmp = sz;
    if (tmp % 2) rje = lcm(rje, tmp);
    else rje = lcm(rje, tmp / 2);      
  }

  printf("%lld\n", rje);
}

int main()
{
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &p[i]); p[i]--;
  }

  vrti();

  return 0;
}