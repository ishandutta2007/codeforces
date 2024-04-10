#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

typedef pair<int, int> P;
typedef long long ll;

const int MX = 1e6 + 5, KOR = (int) sqrt(MX);

int sito[KOR];
vector <int> Pr;

void era() {
  FOR(i, 2, KOR) {
    if (!sito[i]) {
      Pr.push_back(i);
      for (int j=i; j<KOR; j+=i)
	sito[j] = 1;
    }
  }
}

vector <int> faktor(ll x) {
  vector <int> R;
  for (auto it : Pr) {
    if (!(x % it)) {
      R.push_back(it);
      for (; !(x % it); x /= it);	
    }
  }

  if (x > 1)
    R.push_back((int) x);

  return R;
}

int cnt(int a, int pr) {
  int ret=0;
  for (; !(a % pr); a /= pr)
    ret++;

  return ret;
}

int main()
{
  era();

  int q;
  scanf("%d", &q);

  for (; q--; ) {
    int a, b;
    scanf("%d%d", &a, &b);
    ll um = (ll) a * b;

    ll lo=1, hi=MX;
    for (; lo<hi; ) {
      ll mid = (lo + hi) / 2;
      if (mid * mid * mid >= um)
	hi = mid;
      else
	lo = mid + 1;
    }

    int ok = 1;
    if (lo * lo * lo != um)
      ok = 0;
    else {
      auto V = faktor(lo);
      
      ll A = 1, B = 1;    
      for (auto it : V) {
	int x = cnt(a, it);
	int y = cnt(b, it);

	REP(i, x) A *= it;
	REP(i, y) B *= it;
      
	if ((x + y) % 3 || x > 2*y || y > 2*x)
	  ok = 0;
      }

      if (A != a || B != b)
	ok = 0;
    }
    
    printf("%s\n", ok ? "Yes" : "No");
  }

  return 0;
}