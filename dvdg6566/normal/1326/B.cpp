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
const ll MAXN = 100100;

ll T,a,b,N,c,d,e,f,sum,ans;
ll A[MAXN];
vi V;

int main(){
  cin>>N;
  ll curmax = 0;
  for (int i=1;i<=N;++i){
    cin>>a;
    b = a+curmax;
    cout<<b<<' ';
    curmax = max(curmax, b);
  }
}