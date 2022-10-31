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

  int n,k;
  string s;
  
  cin >> n >> k >> s;
  
  map <int,int>mp;
  REP(i,s.size()){
      mp[s[i]-'a']++;
  }
  
  int i = 0;
  while(k > 0){
      if(mp[i] <= k){
          k -= mp[i];
          mp[i] = 0;
          i++;
      }
      else{
          mp[i] -= k;
          break;
      }
  }
  
  string ans;
  for(int i = s.size()-1; i >= 0;i--){
      if(mp[s[i]-'a'] != 0){
          ans += s[i];
          mp[s[i]-'a']--;
      }
  }
  
  reverse(ans.begin(),ans.end());
  
  cout << ans << endl;

  return 0;
}