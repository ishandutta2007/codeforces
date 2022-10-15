#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
ll INF = 1e15;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define f first 
#define s second
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100

ll ans;
ll N,A[MAXN];
vi des;
set<ll> bound;

int main(){
    // freopen("in.txt","r",stdin);
    cin >> N;
    ans = N*(N+1)/2;

    for (ll i=0;i<N;++i)cin>>A[i];
    for (ll i=0;i<N;++i)des.pb(A[i]);
    sort(ALL(des));
    des.pb(N+1);
    for (ll i=1;i<=N;++i){
        ll nxt = *lb(ALL(des), i);
        ans -= (nxt-i);
        // cout<<i<<' '<<nxt<<'\n';
    }
    // cout<<ans<<'\n';
    bound.insert(0);
    bound.insert(N+1);
    for (ll i=0;i<N-1;++i){
        ll a = A[i];
        ll b = A[i+1];
        pi bg;
        if (a == b)continue;
        if (a<b){
            bg = mp(a,N+1);
        }else{
            bg = mp(0,a);
            // A is bigger
        }
        ll r = (bg.s - b)*(b - bg.f);
        // cout<<r<<'\n';
        ll l = *(--bound.ub(b)); // Largest dude before A
        ll e = *(bound.lb(b)); // Smallest dude after A
        l = max(l, bg.f);
        e = min(e, bg.s);

        ll block = (e-b)*(b-l);
        // cout<<"Block is from " << l << " to " << e << " and has length " << block<<'\n';
        if (block < r)ans += (r-block);
        bound.insert(a);
    }
    cout<<ans;
}