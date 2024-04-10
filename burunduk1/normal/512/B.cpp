/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.02
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef BURUNDUK
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define err(...) 
#endif

typedef long long ll;

const int N = 300;
const int SZ = 1e6 + 3;
const int inf = 2e9;
const ll P = 1e9 + 7;

int n, l[N], c[N];
unordered_map<ll, int> h(SZ);

int go( int i, int g ) {
  err("%d %d\n", i, g);
  if (g == 1)
    return 0;
  if (i == n)
    return inf;
  int &f = h[i * P + g];
  if (f)
    return f - 1;
  err("[%d,%d] %d %d\n", i, g, l[i], __gcd(g, l[i]));
  f = 1 + min(go(i + 1, g), c[i] + go(i + 1, __gcd(g, l[i])));
  return f - 1;
}

int main() {
  h.rehash(SZ);
  cin >> n;
  forn(i, n)
    cin >> l[i];
  forn(i, n)
    cin >> c[i];
  int res = go(0, 0);
  cout << (res == inf ? -1 : res) << endl;
  return 0;
}