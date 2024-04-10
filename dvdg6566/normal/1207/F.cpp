#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
int MAXN = 500000;
int BSIZ = 700;
int memo[750][750];
int A[500010];
int N,a,b,c;
 
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N;
  while(N--){
    cin>>a>>b>>c;
    if (a == 1){
      A[b] += c;
      for(int i=1;i<=BSIZ;++i){
        ll lv = b%i;
        memo[i][lv] += c;
        // cout<<"Increase "<<i<<' '<<lv<<'\n';
      }
    }else{
      if (b > BSIZ){
        ll ans=0;
        for (ll p=c;p<=MAXN;p+=b){
          ans+=A[p];
        }
        cout<<ans<<'\n';
      }else cout<<memo[b][c]<<'\n';
    }
  }
}