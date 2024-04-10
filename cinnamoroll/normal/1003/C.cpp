#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 9223372036854775807
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for(long long i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;
  
  int a[n];
  REP(i,n) cin >> a[i];
  
  ll s[n+1] = {};
  REP(i,n){
    s[i+1] = s[i] + a[i];
  }
  
  double maxi = 0;
  FOR(j,k,n+1){
    REP(i,n-j+1){

      maxi = max(maxi,(double)(s[i+j]-s[i])/j);
      
    }
  }
  
  cout << fixed  << maxi << endl;
  
  return 0;
}