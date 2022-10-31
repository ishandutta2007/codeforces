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

  string s;
  cin >> s;
  
  bool f = false;
  if(s.size() <= 2) {
      cout << "No" << endl; return 0;
      
  }
  REP(i,s.size()-2){
      if(s[i] == 'A') {
          if(s[i+1] == 'B' && s[i+2] == 'C' || s[i+1] == 'C' && s[i+2] == 'B') f = true;
      }
      if(s[i] == 'B'){
          if(s[i+1] == 'A' && s[i+2] == 'C' || s[i+1] == 'C' && s[i+2] == 'A') f = true;
      }
      if(s[i] == 'C'){
          if(s[i+1] == 'B' && s[i+2] == 'A' || s[i+1] == 'A' && s[i+2] == 'B') f = true;
      }
      
  }
  
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}