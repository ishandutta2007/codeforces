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

  int n,m;
  cin >> n >> m;
  
//  if(m==n){
 //   cout << 1 << endl;
 //   return 0;
 // }
  
  int a[n] = {};
  int b[n];
  int index;
  REP(i,n){
    cin >> b[i];
    if(b[i] == m) index = i;
  }
  
  RREP(i,index){
    a[i] = a[i+1] + (b[i]>m?1:-1);
  }
  
  FOR(i,index+1,n){
    a[i] = a[i-1] + (b[i]>m?1:-1);
  }
  
 // REP(i,n) cout << a[i] << " ";
  
  map <int,int>lodd,rodd,leve,reve;
  
  REP(i,index+1){
    if(i%2 == 0){
      leve[a[i]]++;
    }
    else{
      lodd[a[i]]++;
    }
  }
  
  FOR(i,index,n){
    if(i%2 == 0){
      reve[a[i]]++;
    }
    else{
      rodd[a[i]]++;
    }
  } 
  
  ll ans = 0;
  ITR(i,leve){
    ans += i->second*reve[-i->first];
    ans += i->second*rodd[-i->first+1];
  }
  
  ITR(i,lodd){
    ans += i->second*rodd[-i->first];
    ans += i->second*reve[-i->first+1];
  }
  
  cout << ans << endl;
  
  return 0;
}