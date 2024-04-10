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

  int n,B;
  cin >> n >> B;
  
  int a[n];
  REP(i,n) cin >> a[i];
  
  int check[n];
  check[0] = a[0]%2==0?1:-1;
  
  FOR(i,1,n){
      check[i] = check[i-1] + (a[i]%2==0?1:-1);
  }
  
  vector <int>v;
  REP(i,n-1){
      if(check[i]==0) v.push_back(abs(a[i]-a[i+1]));
  }
  
  sort(v.begin(),v.end());
  
  int ans = 0;
  while(B > 0 && ans < v.size()){
      if(v[ans] > B) break;
      B -= v[ans];
      ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}