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
    cin >> n;
    
    int mini = MOD,index = -1;
    for(int i =0; i<n; i++){
        int q; 
        cin >> q;
        if(max(0,q-i) % n == 0){
            if(mini > max(0,q-i)+i+1){
             mini = max(0,q-i)+i+1;
             index = i+1;
            }
        }
        else{
            if(mini > (max(0,q-i)/n+1)*n+i+1){
                mini = ((q-i)/n+1)*n+i+1;
                index = i+1;
            }
        }
    }

    cout << index << endl;

  return 0;
}