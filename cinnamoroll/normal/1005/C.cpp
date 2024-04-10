#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 1<<50LL
#define fst first
#define snd second
#define pb push_back
#define int long long
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define RFOR(i,a,b) for(auto i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<ll,ll> P;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  map <int,int>mp;
  
  int maxi = 0;
  REP(_,n){
    int a;
    cin >> a;
    maxi = max(maxi,a);
    mp[a]++;
  }
  
  int ans = 0;
  ITR(i,mp){
    bool f = true;
    int cnt = 2;
    int x = i->first;
    int y = i->second;
    while(f && cnt <= maxi*2 && cnt >= 2){
      if(cnt - x <= 0 || cnt - x == x && y == 1){
        cnt *= 2;
        continue;
      }
      auto itr = mp.find(cnt - x);
      if(itr != mp.end()) f = false;
      cnt *= 2;
    }
    if(f){ ans += y;
         // debug(i->first);
         }
  }
  
  cout << ans << endl;
  
  return 0;
}