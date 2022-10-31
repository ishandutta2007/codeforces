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

  int n,q;
  cin >> n >> q;
  
  int a[n];
  REP(i,n) cin >> a[i];
  
  sort(a,a+n);
  reverse(a,a+n);
  
  int bit[30] = {};
  REP(i,n){
    REP(j,30){
      if(a[i] & 1<<j) bit[j]++;
    }
  }
  

  
  REP(_,q){
    int Q;
    cin >> Q;
    int v[30] = {};
    REP(i,30){
      if(Q & 1<<i) v[i]++;
    }
    
    int ans = 0,cnt = 0;
    RREP(i,30){
      if(v[i] == 1) cnt++;
      if(bit[i] > 0){
        ans += min(cnt,bit[i]);
        cnt = max(0,cnt-bit[i]);
      }
      cnt *= 2;
    }
    if(cnt != 0) cout << -1 << endl;
    else cout << ans << endl;
  }
      
  
  return 0;
}