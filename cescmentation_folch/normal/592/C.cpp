#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  ll a,b,l;
  cin >> l >> b >> a;
  
  ll g = gcd(a, b);
  
  ll h = a/g;
  
  ll res;
  
  if(log(h) + log(b) <= log(l) + 0.0000001){
//     cerr << 1223 <<endl;
    h *= b;
    if(ll(l/h) > 1) res = (ll(l/h)-1ll)*min(a, b);
    else res = 0;
//      cerr << res << endl;
    res += min(l, min(a - 1, b - 1));
//      cerr << res << endl;
    res += min(l%h + 1, min(a, b));
//      cerr << res << endl;
  }
  else {
    res = min(l, min(a - 1, b - 1));
  }
  
  ll k = gcd(res, l);
  cout << res/k << "/" << l/k << endl;
}