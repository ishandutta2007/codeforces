#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, q;
ll gc;
ll a, b;

bool solve(ll s1, ll s2, ll e1, ll e2){
  ll sd, ed;
  if(s1 == 1) sd = s2/a;
  else sd = s2/b;
  if(e1 == 2) ed = e2/b;
  else ed = e2/a;
  if(sd == ed) return true;
  else return false;
}

int main() {
  cin >> n >> m >> q;
  gc = __gcd(n, m);
  a = n/gc;
  b = m/gc;
  for(ll i = 0; i<q; i++){
    ll s1, s2, e1, e2;
    cin >> s1 >> s2 >> e1 >> e2;
    --s2; --e2;
    if(solve(s1, s2, e1, e2)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}