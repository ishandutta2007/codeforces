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

  int n;
  cin >> n;
  
  vector<int> a(n);
  REP(i,n){
      cin >> a[i];
  }
  
  if(n == 1){
      cout << -1 << endl;
      return 0;
  }
  
  FOR(bit,1,1<<n-1){
      ll suma = 0,sumb = 0,cnt = 0;
      REP(i,n){
          if(bit & 1<<i){
               suma += a[i];
               cnt++;
          }
          else   sumb += a[i];
      }
      if(suma == sumb) continue;
      cout << cnt << endl;
      REP(i,n){
          if(bit & 1<<i) cout << i+1 << " ";
      }
      return 0;
  }
  
  cout << -1 << endl;
  
  return 0;
}