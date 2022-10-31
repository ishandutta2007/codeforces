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
  string s;
  
  cin >> n >> s;
  vector <int>num;
  
  REP(i,n){
      if(n%(i+1) == 0){
         num.push_back(i+1);
      }
  }
  
  REP(i,num.size()){
      reverse(s.begin(),s.begin()+num[i]);
  }
  
  cout << s << endl;

  return 0;
}