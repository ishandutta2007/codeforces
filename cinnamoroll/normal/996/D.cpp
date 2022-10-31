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
    
    int a[2*n];
    REP(i,2*n){
        cin >> a[i];
    }
    
    int cnt = 0;
    REP(i,n){
        if(a[2*i] != a[2*i+1]){
            int j = 2*i+1;
            while(a[2*i] != a[j]){
                j++;
            }
            while(j != 2*i+1){
                swap(a[j],a[j-1]);
                cnt++;
                j--;
            }
        }
    }
    
    cout << cnt << endl;

  return 0;
}