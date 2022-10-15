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
const ll MOD = 998244353;
const ll INF = 1e9;
const ll MAXN = 200100;

ll T,a,b,N,c,d,e,f,sum,ans,K;
ll A[MAXN];
vpi V;
vi t;

int main(){
  cin>>N>>K;
  for (int i=1;i<=N;++i){cin>>A[i];V.pb(A[i], i);}
  sort(ALL(V));reverse(ALL(V));
  ll ft = 0;
  for (int i=0;i<K;++i){
    ft += V[i].f;
    t.pb(V[i].s);
  }
  sort(ALL(t));
  // for (auto x:t)cout<<x<<' ';cout<<'\n';

  ll snd = 1;
  for (int i=0;i<SZ(t)-1;++i){
    a = t[i];
    b = t[i+1];
    snd = snd*(b-a);
    snd %= MOD;
  }
  cout<<ft<<' '<<snd;
}