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
ll MOD = 998244353;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

ll p, c, N;
vi fact;

int main(){
  cin>>N;
  if (N == 1 || N == 2){
    cout<<N;
    return 0;
  }
  fact.pb(1);
  for (ll i=1;i<=N;++i)fact.pb((fact.back()*i)%MOD);
  p = c = 3;
  for (int i=4; i<=N;++i){
    p += fact[i-1]-1;
    p%=MOD;
    c = (p * (i))%MOD;
    c%=MOD;
    p = c;
  }
    cout<<(c + fact[N])%MOD << '\n';
}