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

  int a,b,c,d;
  cin >> a >> b >> c >> d;
  a--;b--;c--;d--;
  
  int n =45, m = 45;
  char ca[n][m];
  
  REP(i,22){
      REP(j,22){
          ca[i][j] = 'B';
          ca[i][j+23] = 'C';
          ca[i+23][j] = 'D';
          ca[i+23][j+23] = 'A';
      }
  }
  
  REP(i,n){
      ca[i][22] = 'A';
      ca[22][i] = 'A';
  }
  
  
  
  REP(i,10){
      REP(j,10){
          if(a == 0) break;
          ca[i*2 + 1][j*2 + 1] = 'A';
          a--;
      }
      if(a == 0) break;
  }
  
    REP(i,10){
      REP(j,10){
          if(b == 0) break;
          ca[i*2 +1][j*2 + 24] = 'B';
          b--;
      }
      if(b == 0) break;
  }
  
    REP(i,10){
      REP(j,10){
          if(c == 0) break;
          ca[i*2 + 24][j*2 + 1] = 'C';
          c--;
      }
      if(c == 0) break;
  }
  
    REP(i,10){
      REP(j,10){
          if(d == 0) break;
          ca[i*2 + 24][j*2 + 24] = 'D';
          d--;
      }
      if(d == 0) break;
  }
  
  cout << n << " " << m << endl; 
  
  REP(i,n){
      REP(j,m){
          cout << ca[i][j];
      }
      cout << endl;
  }
  
  return 0;
}