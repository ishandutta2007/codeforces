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

ll gcd(ll a, ll b)
{
if(a % b == 0)
return b;
return gcd(b, a % b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll l,r,x,y;
  cin >> l >> r >> x >> y;
  
  ll ans = 0;
  ll p = x*y;
  
  vector <ll>v;
  
  for(ll i = 1; i <= sqrt(y); i++){
      if(p%i==0){
          v.push_back(i);
          if(y/i != i){
              v.push_back(y/i);
          }
      }
  }
  
  REP(i,v.size()){
      if(l <= v[i] && v[i] <= r){
           REP(j,v.size()){
                if(l <= v[j] && v[j] <= r){
                    if(gcd(v[i],v[j]) == x && v[i]*v[j] == p) ans++;
               }
            }
        }
    }
  
  
  cout << ans << endl;
  return 0;
}