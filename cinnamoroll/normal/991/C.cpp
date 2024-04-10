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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  ll n;
  cin >> n;
  ll r = n;
  ll l = 0;

  
  while(r-l > 1){
      ll ans = l + (r - l) / 2;
      ll sumA = 0,sumB = 0,c = n;
      while(c > 0){
          sumA += min(c,ans);
          c -= ans;
          sumB += max(c/10,(ll)0);
          c -= c/10;
      }
        if (sumA*2 >= n) {
            r = ans;
        } else{
            l = ans;
        }
  }
  
  cout << r << endl;

  return 0;
}