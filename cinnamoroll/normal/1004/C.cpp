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
  
  map <int,int>mp;
  bool f[100001];
  REP(i,100001)f[i] = true;
  
  int a[n];
  REP(i,n){
      cin >> a[i];
      mp[a[i]]++;
  }
  
  ll ans = 0;
  int cnt = mp.size();
  REP(i,n){
      mp[a[i]]--;
      if(mp[a[i]] == 0) cnt--;
      if(f[a[i]])ans += cnt;
      f[a[i]] = false;
    //  debug(ans);
  }
  
  cout << ans << endl;
  
  
  return 0;
}