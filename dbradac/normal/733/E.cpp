#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=a; i<b; i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20;

char s[MAX];
vector <ll> L, R;
ll rje[2][MAX];

ll dajsum(vector <ll> &V, int x)
{
  if (V.empty()) return 0;
  return V.back() - ((x == (int) V.size()) ? 0 : V[V.size()-x-1]);
}

int main()
{
  int n;
  
  scanf("%d %s", &n, s);

  memset(rje, -1, sizeof rje);

  REP(st, 2) {
    for (int i=n-1; i>=0; i--)
      if (s[i] == 'D')
        R.push_back(i + (R.empty() ? 0 : R.back()));

    REP(i, n) {
      if (s[i] == 'D')
        R.pop_back();
      
      if (s[i] == 'U') {
        if (L.size() < R.size())
          rje[st][i] = 2 * dajsum(R, (int) L.size() + 1) - 2 * dajsum(L, (int) L.size()) - i + 1;
        else
          rje[st][i] = 2 * dajsum(R, (int) R.size()) - 2 * dajsum(L, (int) R.size()) + n - i;
      }

      if (s[i] == 'U')
        L.push_back(i + (L.empty() ? 0 : L.back()));
    }

    L.clear();
    R.clear();
    reverse(s, s + n);

    REP(i, n) {
      if (s[i] == 'U')
        s[i] = 'D';
      else
        s[i] = 'U';
    }
  }

  REP(i, n)
    printf("%lld ", rje[0][i] == -1 ? rje[1][n-i-1] : rje[0][i]);
  printf("\n");

  return 0;
}