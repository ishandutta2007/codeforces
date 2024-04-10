#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 1LL<<50
#define fst first
#define sec second
#define pb push_back
#define int long long
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(int itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(int itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<ll,ll> P;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  int x[n],y[n];
  REP(i,n) cin >> x[i] >> y[i];
  
  int cnt = max(x[0],y[0]);
  bool f = true;
  FOR(i,1,n){
      if(cnt < min(x[i],y[i])){
          f = false;
          break;
      }
      if(max(x[i],y[i]) <= cnt) cnt = max(x[i],y[i]);
      else                      cnt = min(x[i],y[i]);
  }
  
  if(f) cout << "YES" << endl;
  else  cout << "NO"  << endl;
  return 0;
}