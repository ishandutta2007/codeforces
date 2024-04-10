#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 3610;
const int M = 1810;

const ll mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int h, w, n;
  cin >> h >> w >> n;
  vi H(h, 1);
  vi W(w, 1);
  for (int i = 0; i < n; ++i) {
    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;
    --h1; --w1; --h2; --w2;
    H[h1] = W[w1] = H[h2] = W[w2] = 0;
  }
  int f = 0;
  int c = 0;
  for (int i = 0; i < h; ++i) f += H[i];
  for (int i = 0; i < w; ++i) c += W[i];
  vvi F(3, vi(f/2 + 1, 0));
  vvi C(3, vi(c/2 + 1, 0));

  F[0][0] = 1;
  for (int i = 0; i < h; ++i) {
    int x0 = (i+1)%3;
    int x1 = i%3;
    int x2 = (i+2)%3;
    for (int j = 0; j <= f/2; ++j) {
      F[x0][j] = F[x1][j];
      if (j and i and H[i] and H[i-1]) {
        F[x0][j] += F[x2][j-1];
        if (F[x0][j] >= mod) F[x0][j] -= mod;
      }
    }
  }
  C[0][0] = 1;
  for (int i = 0; i < w; ++i) {
    int x0 = (i+1)%3;
    int x1 = i%3;
    int x2 = (i+2)%3;
    for (int j = 0; j <= c/2; ++j) {
      C[x0][j] = C[x1][j];
      if (j and i and W[i] and W[i-1]) {
        C[x0][j] += C[x2][j-1];
        if (C[x0][j] >= mod) C[x0][j] -= mod;
      }
    }
  }

  vvll D(N, vll(N,0));
  for (int i = 0; i < N; ++i) {
    D[i][0] = D[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      D[i][j] = (D[i-1][j] + D[i-1][j-1])%mod;
    }
  }
  vll fact(N);
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = ll(i)*fact[i-1]%mod;

  ll res = 0;

  for (int f1 = 0; f1 <= f/2; ++f1) {
    for (int c1 = 0; c1 <= c/2; ++c1) {
      if (2*f1 + c1 > f or 2*c1 + f1 > c) continue;
      ll val1 = D[f - 2*f1][c1]*fact[c1]%mod;
      ll val2 = D[c - 2*c1][f1]*fact[f1]%mod;
      res = (res + ll(F[h%3][f1])*ll(C[w%3][c1])%mod*val1%mod*val2)%mod;
    }
  }

  cout << res << '\n';

}