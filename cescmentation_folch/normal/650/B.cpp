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
  ll n, a, b, t;
  cin >> n >> a >> b >> t;
  string str;
  cin >> str;
  ll D[n];
  ll E[n];
  ll res = 0;
  ll init = 1;
  if (str[0] == 'w') init += b;
  if (t >= init) res = 1;
  D[0] = 0;
  E[0] = 0;
  for (int i = 1; i < n; ++i) {
    D[i] = 1 + D[i - 1] + a;
    if (str[i] == 'w') D[i] += b;
    if (t >= init + D[i]) res = i + 1;
  }
  for (int i = n - 1; i > 0; --i) {
    E[i] = 1 + E[(i + 1)%n] + a;
    if (str[i] == 'w') E[i] += b;
    if (t >= E[i] + init) res = max(res, n - i + 1);
  }
//   cerr << "Dreta primer" << endl;
  ll j = 0;
  for (int i = 1; i < n; ++i) {
    j += a;
    ll k = init + D[i];
    ll ta = n - 1;
    ll tb = 0;
//     cerr << init << ' ' << D[i] << ' ' << j << endl;
    while (tb + 1 < ta) {
      ll tc = (ta + tb)/2;
      
      if (t >= j + k + E[tc]) ta = tc;
      else tb = tc;
    }
    if (t >= j + k + E[ta]) {
//       cerr << "fins a " << i << " torna a " << ta << endl;
      res = max(res, min(i + 1 + n - ta, n));
    }
  }
//   cerr << "Esquerra primer" << endl;
  j = 0;
  for (int i = n - 1; i > 0; --i) {
    j += a;
    ll k = init + E[i];
    ll ta = 1;
    ll tb = n;
//     cerr << init << ' ' << E[i] << ' ' << j << endl;
    while (ta + 1 < tb) {
      ll tc = (ta + tb)/2;
      
      if (t >= j + k + D[tc]) ta = tc;
      else tb = tc;
    }
    if (t >= j + k + D[ta]) {
//       cerr << "fins a " << i << " torna a " << ta << endl;
      res = max(res, min(n - i + 1 + ta, n));
    }
  }
  cout << res << endl;
}