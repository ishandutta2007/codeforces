/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.03.21
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

struct num {
  static const int MA = (int)1e9 + 7, MB = (int)1e9 + 9;

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

template <const int maxN>
struct RMQ {
  int qst, qen, q[maxN], ind[maxN];

  void pop( int i ) {
    if (ind[qst] == i)
      qst++;
  }
  void push( int i, int f ) {
    while (qst < qen && q[qen - 1] >= f) // change to <= if you wanna "get_max"
      qen--;
    q[qen] = f, ind[qen++] = i;
  }
  int get_min() {
    return q[qst];
  }
};

const int N = 1e6;

int n, b[2 * N + 1];
char s[2 * N];
RMQ<2 * N> rmq;

int main() {
  gets(s), n = strlen(s);
  memcpy(s + n, s, n);

  forn(i, 2 * n) 
    b[i + 1] = b[i] + (s[i] == '(' ? 1 : -1);

  StrComparator<num> h(2 * n, s);
  int ind = -1;
  forn(i, n) 
    rmq.push(i, b[i]);
  forn(i, n) {
    rmq.push(i + n, b[i + n]);
    int mi = rmq.get_min() - b[i];
    int diff = b[n + i] - b[i];
    rmq.pop(i);
    bool good = (diff - 2 * mi == abs(b[n]));
    if (good && (ind == -1 || h.cmp(i, ind) < 0))
      ind = i;
  }
  assert(ind != -1);

  if (b[n] < 0) {
    forn(i, -b[n])
      putchar('(');
    forn(i, n)
      putchar(s[ind + i]);
  } else {
    forn(i, n)
      putchar(s[ind + i]);
    forn(i, b[n])
      putchar(')');
  }
  return 0;
}