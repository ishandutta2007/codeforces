#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e18;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 500100

ll fw[MAXN], fw2[MAXN];

ll N,a,b;
ll A[MAXN];
vpi ord;

void update(ll x, ll y, ll v) { //inclusive
    for (ll tx=x; tx <= N; tx += tx&(-tx)) fw[tx] += v, fw2[tx] -= v*(x-1);
    for (ll ty=y+1; ty <= N; ty += ty&(-ty)) fw[ty] -= v, fw2[ty] += v*y; 
}
ll sum (ll x) {
    ll res = 0;
    for (ll tx=x; tx; tx -= tx&(-tx)) res += fw[tx]*x + fw2[tx];
    return res;
}
ll range_sum(ll x, ll y) { //inclusive
    return sum(y)-sum(x-1);
}

ll ans;

int main(){
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (ll i=1;i<=N;++i)cin>>A[i];
  for (ll i=1;i<=N;++i){
    ord.pb(mp(A[i],i));
  }
  sort(ALL(ord));
  for (auto i : ord){
    update(i.s, N, 1);
    ll x = i.s;
    ll t = x * range_sum(x,N) - (N-x+1)*range_sum(1,x-1);
    // cout<<i.f<<' '<<t<<'\n';
    ans += (i.f%MOD) * (t%MOD);
    ans %= MOD;
  }
  cout<<ans;
}