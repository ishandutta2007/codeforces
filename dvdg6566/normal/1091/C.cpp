#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll, pi> pii;
typedef set<ll> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

ll N;
set<ll> S;

int main(){
  cin>>N;
  for (ll i=1;i*i<=N;++i){
    if (N%i!=0)continue;
    ll t = N/i;
    S.insert( (t*(t-1))/ 2 * i + t);
    S.insert( (i*(i-1))/2 * t + i);
  }
  for (auto i : S)cout<<i<<' ';
}