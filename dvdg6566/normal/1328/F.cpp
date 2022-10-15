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
const ll INF = 1e10;
const ll MAXN = 200100;

ll N,K;
ll A[MAXN];
vpi V;

int main(){
  cin>>N>>K;
  for (int i=1;i<=N;++i){
    cin>>A[i];
  }
  sort(A+1,A+N+1);
  V.pb(0,0);
  for (int i=1;i<=N;++i){
    if (SZ(V) && V.back().f == A[i])++V.back().s;
    else V.pb(A[i], 1);
  }
  V.pb(INF,0);
  // for (auto i : V){
  //   cout<<i.f<<' '<<i.s<<'\n';
  // }
  ll cntabove = 0;
  ll cntbelow = 0;
  ll totabove = 0;
  ll totbelow = 0;
  ll A=1e18;
  ll B=1e18;
  ll C=1e18;

  for (auto i : V){
    cntabove += i.s;
    totabove += i.f*i.s;
  }
  // cout<<cntabove<<' '<<totabove<<'\n';
  for (int i=1;i<SZ(V)-1;++i){
    ll d = V[i].f;
    ll c = V[i].s;
    ll uval = V[i+1].f;
    ll lval = V[i-1].f;
    ll dblow = d - V[i-1].f;
    ll dabov = V[i+1].f - d;
    // Price adjustment process
    cntabove -= V[i].s;
    cntbelow += V[i-1].s;
    totabove -= V[i].s * V[i].f;
    totbelow += V[i-1].s * V[i-1].f;

    ll needs = K - c;
    if (needs <= 0){
      cout<<0;
      return 0;
    }
    if (needs <= cntbelow){
      // Try doing only from below
      ll tmp = lval * cntbelow - totbelow;
      tmp += needs * (dblow);
      A = min(A,tmp);
    }
    if (needs <= cntabove){
      ll tmp = totabove - uval * cntabove;
      tmp += needs * (dabov);
      B = min(B,tmp);
    }
    // cout<<d<<' '<<lval<<' '<<uval<<'\n';
    ll tmp = totabove - d * cntabove + d * cntbelow - totbelow;
    
    ll excess = cntbelow+cntabove - needs;
    tmp -= excess;
    // cout<<excess<<' '<<tmp<<'\n';
    // if (tmp == 253243){
    //   cout<<d<<'\n';
    //   cout<<tmp<<' '<<u*dabov + l*dblow<<' '<<totabove - uval * cntabove + lval * cntbelow - totbelow<<'\n';
    //   cout<<l<<' '<<u<<' '<<c<<'\n';
    // }
    // cout<<l<<' '<<u<<' '<<dabov<<' '<<dblow<<'\n';
    // cout<<tmp<<'\n';
    C = min(C,tmp);
  }
  ll ans = min({A,B,C});
  cout<<ans<<'\n';
  // if (ans == 253243)cout<<A<<' '<<B<<' '<<C<<'\n';
}