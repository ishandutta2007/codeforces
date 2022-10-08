/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.04.04
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)
#define sz(a) (int)(a).size()

const int N = 1e6 + 10;

int n, k;
char s[N];
int z[N], add[N];

void zFunction() {
  int l = -1, r = -1;
  z[0] = 0;
  forab(i, 1, n - 1) {
    int k = 0;
    if (r >= i)
      k = min(z[i - l], r - i);
    while (i + k < n && s[i + k] == s[k])
      k++;
    z[i] = k;
    if (i + z[i] > r)
      l = i, r = i + z[i];
  }
}

typedef long long ll;
typedef unsigned long long ull;

struct num {
  static const int MA = 1e9 + 7, MB = 1e9 + 9;

  int a, b;

  num() { }
  num( int x ) : a(x), b(x) { }
  num( int _a, int _b ) : a(_a), b(_b) { }

  num operator + ( const num &x ) const { return num((a + x.a) % MA, (b + x.b) % MB); }
  num operator - ( const num &x ) const { return num((a + MA - x.a) % MA, (b + MB - x.b) % MB); }
  num operator * ( int x ) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
  num operator * ( const num &x ) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
  bool operator == ( const num &x ) const { return a == x.a && b == x.b; }

  explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};

template <class hash_t>
struct StrComparator {
  static const int P = 239017;
  static vector<hash_t> deg;

  int n;
  const char *s;
  hash_t *h;

  StrComparator( int n, const char *s ) : n(n), s(s) {
    h = new hash_t[n + 1];
    h[0] = 0;
    forn(i, n)
      h[i + 1] = h[i] * P + s[i];
    deg.reserve(n);
    while (sz(deg) <= n)
      deg.push_back(*deg.rbegin() * P);      
  }

  hash_t substr( int i, int len ) const { return h[i + len] - h[i] * deg[len]; }

  int lcp( int i, int j ) {
    int L = 0, R = n - max(i, j);
    while (L < R) {
      int M = (L + R + 1) / 2;
      if (substr(i, M) == substr(j, M))
        L = M;
      else
        R = M - 1;
    }
    return L;
  }

  int cmp( int a, int b ) {
    int LEN = n - max(a, b), L = lcp(a, b);
    return L < LEN ? (int)s[a + L] - s[b + L] : b - a;
  }

  bool operator() ( int i, int j ) { return cmp(i, j) < 0; }
};
template <class hash_t> vector<hash_t> StrComparator<hash_t>::deg(1, 1);

int main() {
  scanf("%d%d ", &n, &k);
  gets(s);
  zFunction();
  StrComparator<num> h(n, s);
  for (int l = 1; l * k <= n; l++) 
    if (h.substr(0, l * (k - 1)) == h.substr(l, l * (k - 1))) {
      //printf("l = %d, len = min(%d,%d) + 1\n", l, l, z[l * k]);
      add[l * k - 1] += 1;
      add[l * k + min(l, z[l * k])] -= 1;
    }

  int cnt = 0;
  forn(i, n)
    putchar('0' + ((cnt += add[i]) > 0));
  return 0;
}