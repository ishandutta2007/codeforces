#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

ll power(ll x, ll n) {
        ll t;
        if(n == 0) {
            return 1;
        }
        
        if(n == 1) {
            return x%MOD;
        }
        t = power(x, n / 2) % MOD;
        if(n % 2 == 0) {
            return t * t % MOD;
        }else{
            return t%MOD * t%MOD * x % MOD;
        }
    }


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,k;
  cin >> n >> k;

  if(n == 0){
     cout << 0 << endl;  
     return 0;
  }
  if(n % MOD == 0){
      cout << (MOD - (power(2,k)-1))%MOD << endl;
      return 0;
  }
  
  n %= MOD;

  cout << (n*2*power(2,k) - power(2,k) + 1) % MOD << endl;
  

  return 0;
}