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
  
  
  map <ll,int>mp;
  REP(i,n){
      ll x,y;
      cin >> x >> y;
      mp[x]++;
      mp[y+1]--;
  }
  
  auto itr = mp.begin();
  int keep;
  while(itr != mp.end()){
      keep = itr->second;
      itr++;
      itr->second += keep;
  }
  
  ll ans[n+1] = {};
  
  itr = mp.begin();
  while(itr != mp.end()){
      int num = itr->second;
      ans[num] -= itr->first;
      itr++;
      ans[num] += itr->first;
  }
  
  REP(i,n) cout << ans[i+1] << " ";
      
  
  return 0;
}