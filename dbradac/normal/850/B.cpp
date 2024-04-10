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
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<21;

int p[MAX], n, x, y;
int sito[MAX];
int sum[MAX];
ll sumpoz[MAX];

void sit() {
  FOR(i, 2, MAX)
    if (!sito[i])
      for (int j=2*i; j<MAX; j+=i)
	sito[j] = 1;
}

void gen() {
  n = rand() % 5 + 1;
  REP(i, n) p[i] = rand() % 1000000 + 1;
  x = rand() % 1000000000;
  y = rand() % 1000000000;
}

int main()
{
  sit();
  //  gen();

  scanf("%d%d%d", &n, &x, &y);
   
  REP(i, n) {
    scanf("%d", &p[i]);
    sum[p[i]]++;
    sumpoz[p[i]] += p[i];
  }

  FOR(i, 1, MAX) {
    sum[i] += sum[i-1];
    sumpoz[i] += sumpoz[i-1];
  }

  // TRACE(n _ x _ y);
  // REP(i, n) TRACE(p[i]);

  ll rje = (ll) n * x;
  FOR(i, 2, MAX/2) {
    if (sito[i]) continue;

    ll tmp = 0;

    int cnt = 0;
    int raz = min(i, x/y + 1);
    for (int j=0; j<MAX/2; j+=i) {
      int gor = j + i;
      int dol = j + i - raz;
      cnt += sum[gor] - sum[dol];
      tmp += ((ll) sum[gor] - sum[dol]) * (j+i) - (sumpoz[gor] - sumpoz[dol]);
      if (tmp * y > rje) break;
    }

    tmp = tmp * y + ((ll) n - cnt) * x;
    //    if (cnt > n) TRACE(i _ cnt);
    assert(cnt <= n);
    rje = min(rje, tmp);
  }

  assert(rje <= (ll) n * y);
  cout << rje << endl;

  return 0;
}