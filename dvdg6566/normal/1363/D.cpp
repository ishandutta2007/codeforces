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
const ll MAXN=1010;
const ll MAXK=17;
const ll INF=1e18;
const ll MOD=998244353;

vi V[MAXN];
ll N,K,T,a;
ll out[MAXN];
ll blk[MAXN];
vi t;

int cnt=0;
ll ask(){
    t.clear();
    for (int i=1;i<=N;++i)if(!blk[i])t.pb(i);
    if(!SZ(t))return 0;
    cout<<"? "<<SZ(t)<<' ';
    for (auto i:t)cout<<i<<' ';
    cout<<endl;
    ll x;cin>>x;return x;
}

ll dnc(ll a, ll b, ll val){
    if(a==b)return a;
    assert(a<=b);
    cerr<<a<<' '<<b<<'\n';
    ll m=(a+b)/2;
    for (int i=1;i<=N;++i)blk[i]=1;
    for (int i=a;i<=m;++i){
        for (auto w:V[i])blk[w]=0;
    }
    ll h=ask();
    if(h==val){
        return dnc(a,m,val);
    }else{
        return dnc(m+1,b,val);
    }
}

int main(){
    cin>>T;
    while(T--){
        cin>>N>>K;
        for (int i=1;i<=K;++i)out[i]=0;
        for (int i=1;i<=K;++i){
            V[i].clear();
            ll n;cin>>n;
            while(n--){cin>>a;V[i].pb(a);}
        }
        for (int i=1;i<=N;++i)blk[i]=0;
        ll glob=ask();
        ll a=dnc(1,K,glob);
        for (int w=1;w<=K;++w)out[w]=glob;
        for (int i=1;i<=N;++i)blk[i]=0;
        for (auto t:V[a])blk[t]=1;
        out[a]=ask();

        string A;
        cout<<"! ";
        for (int w=1;w<=K;++w)cout<<out[w]<<' ';
        cout<<endl;
        cin>>A;
        // if (A!="CORRECT")assert(0);
    }
}