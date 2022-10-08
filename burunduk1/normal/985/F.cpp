/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

inline int add( int a, int mod ) { return a >= mod ? a - mod : a; }

struct num {
  static const int MA = 1e9 + 7, MB = 1e9 + 9;

  int a, b;

  num() { a = b = 0; }
  num( int x ) : a(x), b(x) { }
  num( int a, int b ) : a(a), b(b) { }

  num operator + ( const num &x ) const { return num(add(a + x.a, MA), add(b + x.b, MB)); }
  num operator - ( const num &x ) const { return num(add(a + MA - x.a, MA), add(b + MB - x.b, MB)); }
  num operator * ( int x ) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
  num operator * ( const num &x ) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
  bool operator == ( const num &x ) const { return a == x.a && b == x.b; }

  explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};

mt19937 R(time(NULL));

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, m;
	string s;
	cin >> n >> m >> s;

  const int K = 26, P = R();
  vector<num> deg(n + 1);
  vector<vector<num>> h(K, vector<num>(n + 1));
  vector<vector<int>> pos(K);
  deg[0] = 1;
  forn(i, n) {
    deg[i + 1] = deg[i] * P;
    forn(j, K)
      h[j][i + 1] = h[j][i] * P + num(s[i] == 'a' + j);
    pos[s[i] - 'a'].push_back(i);
  }
  forn(j, K)
    pos[j].push_back(n);

  auto get = [&]( int j, int l, int len ) { 
    return h[j][l + len] - h[j][l] * deg[len];
  };
	while (m--) {
		int a, b, len, equal = 1;
		cin >> a >> b >> len, a--, b--;

    forn(j, 26) {
      int p = *lower_bound(pos[j].begin(), pos[j].end(), a);
      if (p < a + len) {
        int j1 = s[b - a + p] - 'a';
        // printf("j = %d (%lld) --> j1 = %d (%lld)\n", j, (ll)get(j, a, len), j1, (ll)get(j1, b, len));
        equal &= (get(j, a, len) == get(j1, b, len));
      }
    }
    puts(equal ? "YES" : "NO");
	}
}