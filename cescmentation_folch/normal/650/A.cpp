#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef map<ll,ll> mll;
typedef pair<ll, ll> pll;
typedef map<pll, ll> mpll;

#define pb push_back
#define REP(i,a,f) for(int i = a; i < f; ++i) 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  mll F;
  mll C;
  mpll P;
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    if (F.count(x) == 0) F[x] = 0;
    if (C.count(y) == 0) C[y] = 0;
    if (P.count(pll(x,y)) == 0) P[pll(x,y)] = 0;
    ++F[x];
    ++C[y];
    ++P[pll(x,y)];
  }
  ll res = 0;
  for (mll::iterator it = F.begin(); it != F.end(); ++it) {
    ll k = it->second;
    res += k*(k - 1)/2;
  }
  for (mll::iterator it = C.begin(); it != C.end(); ++it) {
    ll k = it->second;
    res += k*(k - 1)/2;
  }
  for (mpll::iterator it = P.begin(); it != P.end(); ++it) {
    ll k = it->second;
    res -= k*(k - 1)/2;
  }
  cout << res << endl;
}