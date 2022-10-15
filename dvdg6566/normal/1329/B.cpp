#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 500100;

ll N,a,b,c,d,e,f,g,T,M,k,ans;
ll A[MAXN], B[MAXN];
vi V[MAXN];
vi out;

int main(){
  cin>>T;
  while (T--){
    cin>>N>>M;
    ll cur = 1;
    ll rep = 1;
    ans = 1;
    while (cur*2<=N){
      ll len = 2*cur-cur-1;
      cur = 2*cur;
      ans += (rep*len)%M;
      ans%=M;
      rep=ans+1;
      ans = (ans+rep)%M;
    }
    ll lo = N - cur;
    ans += (rep*lo)%M;
    ans %= M;
    cout<<ans<<'\n';
  }
}