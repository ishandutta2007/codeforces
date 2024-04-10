#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <set>
#include <queue>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define X first
#define Y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long ll;
typedef pair<int, int> P;

ll sve;

ll get(ll x) {
  return ((x % sve) + sve) % sve;
}

ll gc(ll a, ll b) {
  if (!b) return a;
  return gc(b, a % b);
}

int main() {
  int n, k, a, b;
  scanf("%d%d%d%d", &n, &k, &a, &b);
  sve = (ll) n * k;

  ll mn = 1e18, mx = 0;

  for (int poc : {-a, a}) {
    for (int kraj : {-b, b}) {
      REP(raz, n) {
	ll prvi = get(poc);
	ll drugi = get(kraj + (ll) k * raz);
	ll udalj = get(drugi - prvi);
	
	ll kolko = sve / gc(udalj, sve);
	mn = min(mn, kolko);
	mx = max(mx, kolko);
      }
    }
  }
  
  printf("%lld %lld\n", mn, mx);

  return 0;
}