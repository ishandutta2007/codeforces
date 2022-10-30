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
typedef pair<ll, ll> P;
#define X first
#define Y second

const int MAX = 1<<20;
const int MOD = 1e9 + 7;

vector <int> Pr;
int p[MAX];
int fi[MAX];

void sito()
{
  fi[1] = 1;
  FOR(i, 2, MAX) {
    if (!p[i]) {
      Pr.push_back(i);
      for (int j=i; j<MAX; j+=i)
	p[j] = i;
      
      fi[i] = i-1;
    }
    else {
      int pot = 1;
      for (int tmp=i; !(tmp % p[i]); tmp /= p[i], pot *= p[i]);
      fi[i] = fi[pot] * fi[i/pot];
      if (pot == i)
	fi[i] = (i / p[i]) * (p[i] - 1);
    }
  }
}

ll f(ll x)
{
  if (x < MAX)
    return fi[x];

  ll ret = x;

  REP(i, (int) Pr.size()) {
    int pr = Pr[i];
    if ((ll) pr * pr > x) break;
    if (!(x % pr)) {
      ret /= pr;
      ret *= pr-1;
      for (; !(x % pr); x /= pr);
    }
  }

  if (x > 1) {
    ret /= x;
    ret *= x-1;
  }
  
  return ret;
}


ll fk(ll n, ll k)
{
  if (n == 1) return 1;
  if (k == 1) return f(n);
  
  if (k % 2 == 0) return fk(n, k-1);
  return f(fk(n, k-1));
}

int main()
{
  sito();
  
  ll n, k;
  scanf("%lld%lld", &n, &k);
  if (k > 100000) printf("1\n");
  else printf("%lld\n", fk(n, k) % MOD);

  return 0;
}