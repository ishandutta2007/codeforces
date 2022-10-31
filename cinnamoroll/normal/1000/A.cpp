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

  int n;
  cin >> n;
  
  map <string,int>mp;
  
  REP(i,n){
      string s;
      cin >> s;
      mp[s]++;
  }

  int ans = 0;
  REP(i,n){
      string s;
      cin >> s;
      if(mp[s] != 0) mp[s]--;
      else ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}