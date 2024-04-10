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

  int n,p;
  cin >> n >> p;
  
  
  char c[n];
  REP(i,n){
      cin >> c[i];
  }
  
  int f = -1;
  REP(i,n-p){
      

      
          
      if(c[i] == '.' && c[i+p] == '0'){
              c[i] = '1'; f = 1;break;
          }
          
      else if(c[i] == '.'){
            c[i] = '0'; c[i+p] = '1'; f = 1;break;
          }
      
      else if(c[i] == '0' && c[i+p] == '.'){
              c[i+p] = '1'; f = 1;break;
          }
          
      else if(c[i+p] == '.'){
              c[i+p] = '0'; c[i] = '1';
              f = 1; break;
      }
      
      else if(c[i] != c[i+p]) { f=1; break;}

      }
          

  
  
  if(f == -1) {cout << "No" << endl;}
  else{ 
    REP(i,n){
        if(c[i] == '.') c[i] = '0';
        cout << c[i];
    }
  }
  
  return 0;
}