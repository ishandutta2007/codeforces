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
const ll MAXN=500100;
const ll MAXK=17;
const ll INF=2e18;
const ll MOD=998244353;

ll N,K,ans;
ll fact[MAXN];
ll finv[MAXN];

ll qexp(ll A,ll B){
    if(B==0)return 1;
    ll h=qexp(A,B/2);
    h=h*h%MOD;
    if (B%2)h=h*A%MOD;
    return h;
}

ll qinv(ll A){
    return qexp(A,MOD-2);
}

ll choose(ll a, ll b){
    return fact[a]*finv[b]%MOD*finv[a-b]%MOD;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>K;
    fact[0]=1;
    for(int i=1;i<=N;++i)fact[i]=fact[i-1]*i%MOD;
    for(int i=0;i<=N;++i)finv[i]=qinv(fact[i]);

    for(int w=1;w<=N;++w){
        ll cnt=N/w;
        if(cnt<K)break;
        ll init=cnt-K;
        ll use=choose(cnt-1,K-1);
        ans=(ans+use)%MOD;
    }
    cout<<ans;
}