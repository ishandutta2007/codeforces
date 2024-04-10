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

  string s;
  cin >> s;
  
  int cnt = 0,ans = 0,len = 0;
  REP(i,s.size()){
    if((s[i]-'0')%3 == 0){
      ans++;
      cnt = 0;
      len = 0;
      continue;
    }
    cnt += s[i]-'0';
    len++;
    if(cnt % 3 == 0 || len == 3){
      ans++;
      cnt = 0;
      len = 0;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}