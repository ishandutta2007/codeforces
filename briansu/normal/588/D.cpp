//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream &operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
#else
#define debug(...)
#define endl '\n'
#endif // brian
//}

const ll MAXn=1e6+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n,l,k;
ll dp[MAXn];
ll d[MAXn];
vector<ll> u;
ll bit[MAXn];
void add(ll x,ll a)
{
    while(x<=n)
    {
        bit[x]=(bit[x]+a)%MOD;
        x+=x&-x;
    }
}
ll qr(ll x)
{
    ll r=0;
    while(x>0)
    {
        r=(r+bit[x])%MOD;
        x-=x&-x;
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l>>k;
    REP(i,n)cin>>d[i];
    REP(i,n)u.pb(d[i]);
    sort(ALL(u));
    u.resize(unique(ALL(u))-u.begin());
    REP(i,n)d[i]=lower_bound(ALL(u),d[i])-u.begin()+1;
    //_OUTC(cout,d,d+n);
    ll ans=0;
    ll c=(l-1)/n,rm=(l-1)%n;
    for(int i=1;i<=k;i++)
    {
        if((i-1)*n>=l)break;
        REP(j,n)
        {
            if(i==1)dp[j]=1;
            else dp[j]=qr(d[j]);

            if(rm>=j)ans=(ans+((c-(i-1)+1)%MOD)*dp[j])%MOD;
            else ans=(ans+((c-(i-1))%MOD)*dp[j])%MOD;
            debug(i,j,dp[j],ans);
        }
        REP(j,n+1)bit[j]=0;
        REP(j,n)add(d[j],dp[j]);
    }
    cout<<ans<<endl;
}