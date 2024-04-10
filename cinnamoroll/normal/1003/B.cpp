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

  int a,b,x;
  cin >> a >> b >> x;
  
  if(x == 1){
    REP(i,a) cout << 0;
    REP(i,b) cout << 1;
    return 0;
  }
  
  if(x >= 2){
    bool f;
    if(a >= b){
     while(x != 1){
       cout << 0;
       x--;a--;
       f = false;
       if(x == 1) break;
       cout << 1;
       x--;b--;
       f= true;
     }
    }
    else{
      while(x != 1){
       cout << 1;
       x--;b--;
       f = true;
       if(x == 1) break;
       cout << 0;
       x--;a--;
       f= false;
     }
    }
      
     if(f){
     REP(i,a) cout << 0;
     REP(i,b) cout << 1;
     }
     else{
     REP(i,b) cout << 1;
     REP(i,a) cout << 0;
     }
  }
  
  return 0;
}