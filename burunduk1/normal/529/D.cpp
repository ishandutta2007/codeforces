/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.03.21
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

typedef pair <int, int> pii;
typedef vector <int> vi;

const int N = 2e4;
const int T = 24 * 60 * 60;

int was, n, M, add, cnt, ans[N];
vi ind[T];

int main() {
  scanf("%d%d%d", &n, &M, &add);
  forn(i, n) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    ind[s + 60 * (m + 60 * h)].pb(i);
  }

  set<pii> s;
  forn(i, T) {
    while (sz(s) && s.begin()->first <= i)
      s.erase(s.begin());
    for (int j : ind[i])  {
      if (sz(s) < M)
        ans[j] = ++cnt;
      else {
        ans[j] = s.rbegin()->second;
        s.erase(*s.rbegin());
      }
      s.insert(pii(i + add, ans[j]));
    }
    was |= sz(s) == M;
  }
  if (!was)
    puts("No solution");
  else {
    printf("%d\n", cnt);
    forn(i, n)
      printf("%d\n", ans[i]);
  }
  return 0;
}