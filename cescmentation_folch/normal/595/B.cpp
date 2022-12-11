#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define pb push_back
#define REP(i,a,f) for(int i = a; i < f; ++i) 

int main() {
  ll mod = 1e9 + 7;
  int n, k;
  cin >> n >> k;
  ll p = 1;
  REP(i,0,k) p *= 10;
  ll a[n/k];
  ll b[n/k];
  REP(i,0,n/k) cin >> a[i];
  REP(i,0,n/k) cin >> b[i];
  
  ll res = 1;
  REP(i,0,n/k) {
    ll t = (p - 1)/a[i];
    ll t2 = (((b[i] + 1)*p/10)-1)/a[i];
    ll t3 = ((b[i]*p/10)-1)/a[i];
    if (b[i] == 0) t3 = -1;
    ll rr = (t3 + t - t2 + 1)%mod;
    res = (res*rr)%mod;
  }
  
  cout << res << endl;
}