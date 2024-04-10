#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 1<<50LL
#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define RFOR(i,a,b) for(auto i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s,t;
  cin >> s >> t;
  
  int S = s.size()-1, T = t.size()-1;
  int ans = S+T+2;
  REP(i,min(S,T)+1){
    if(s[S-i] == t[T-i]) ans -= 2;
    else break;
  }
  
  cout << ans << endl;
  
  return 0;
}