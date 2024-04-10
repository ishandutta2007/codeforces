#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

const ll mod = 998244353;

ll solve(vs V) {
  int n = (int)V.size();
  if (!n) return 0;
  
  int l = 0;
  unordered_map<char, int> M;
  for (auto s : V) {
    char a = s[0];
    if (M.count(a) == 0) {
      M[a] = l++;
    }
    a = s.back();
    if (M.count(a) == 0) {
      M[a] = l++;
    }
  }
  set<string> S;
  for (auto s : V) {
    S.insert(s);
    reverse(s.begin(), s.end());
    S.insert(s);
  }
  vvi P(l, vi(l, 0));
  for (auto s : S) {
    int a = M[s[0]];
    int b = M[s.back()];
    ++P[a][b];
  }
  vvvi D(l, vvi(l, vi(l, 0)));
  for (int a = 0; a < l; ++a) {
    for (int b = a; b < l; ++b) {
      for (int c = b; c < l; ++c) {
        for (int d = 0; d < l; ++d) {
          D[a][b][c] = (D[a][b][c] + P[a][d]*P[b][d]%mod*P[c][d])%mod;
        }
        D[a][c][b] = D[b][a][c] = D[b][c][a] = D[c][a][b] = D[c][b][a] = D[a][b][c];
      }
    }
  }
  ll res = 0;
  for (int a = 0; a < l; ++a) {
    for (int b = a; b < l; ++b) {
      for (int c = b; c < l; ++c) {
        for (int d = c; d < l; ++d) {
          ll val = D[a][b][c]*D[b][c][d]%mod*D[a][b][d]%mod*D[a][c][d]%mod;
          ll cont = 24;
          if (a == b) {
            if (b == c) {
              if (c == d) cont = 1;
              else cont = 4;
            }
            else if (c == d) cont = 6;
            else cont = 12;
          }
          else if (b == c) {
            if (c == d) cont = 4;
            else cont = 12;
          }
          else if (c == d) cont = 12;
          res = (res + cont*val)%mod;
        }
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vvs V(11);
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    V[a.size()].push_back(a);
  }
  ll res = 0;
  for (int i = 3; i <= 10; ++i) {
    res = (res + solve(V[i]))%mod;
  }
  cout << res << '\n';
}