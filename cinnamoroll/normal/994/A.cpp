#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define INF (1LL << 62)
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<P>> Graph;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  
  int a[n], b[m];
  REP(i,n){
      cin >> a[i];
  }
  
  REP(i,m){
      cin >> b[i];
  }
  
  
  REP(i,n){
      REP(j,m){
          if(a[i] == b[j]){
              cout << a[i] << " ";
              break;
          }
         
      }
  }
 cout << endl;
  return 0;
}