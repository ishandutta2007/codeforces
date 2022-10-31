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

  int n,k;
  cin >> n >> k;
  
  ll p[n],c[n];
  REP(i,n){
      cin >> p[i];
  }
  
  REP(i,n){
      cin >> c[i];
  }
  
  vector<pair<ll,pair<ll,int>>> pair;
  REP(i,n){
      pair.push_back({p[i],{c[i],i}});
  }
  
  sort(pair.begin(),pair.end());
  
  ll sum[k] = {};int a = pair[0].first;
  ll ANS[n];
  ANS[pair[0].second.second] = pair[0].second.first;
  FOR(i,1,n){
      sum[0] = max(sum[0],pair[i-1].second.first);
      sort(sum,sum+k);
      ll ans = 0;
      REP(j,k){
          ans += sum[j];
      }
  ANS[pair[i].second.second] = ans+pair[i].second.first;
  }
  
  REP(i,n){
      cout << ANS[i] << " ";
  }
  
  return 0;
}