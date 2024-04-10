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
  cin>>N>>M;
  for (int i=1;i<=M;++i){
    cin>>A[i];
    T+=A[i];
  }
  int excess = N-M;
  int lst = N;
  for (int i=M;i>=1;--i){
    // cout<<lst<<' '<<excess<<'\n';
    int l = A[i];
    int x = lst;
    x -= (min(l-1, excess));
    // cout<<"Start "<<x<<'\n';
    out.pb(x);
    if (x+l-1>N){
      cout<<-1;
      return 0;
    }
    excess -= (lst-x);
    lst = x-1;
  }
  if (excess>0){
    cout<<-1;
    return 0;
  }
  reverse(ALL(out));
  for (auto x:out)cout<<x<<' ';
}