//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
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
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=ll(1e15);

vector<ll> v[MAXn];
ll dp[MAXn][3];


ll pw(ll x,ll k)
{
    if(!k)return 1;
    ll a = pw(x,k/2);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

void add(ll &a,ll b)
{
    a = (a + b) % MOD;
}

void dfs(ll now,ll f)
{
    ll s = 1,c=0;
    for(ll k:v[now])if(k != f)
    {
        c++;
        dfs(k,now);
        s = s * (2 * dp[k][1] + dp[k][2])%MOD;
    }
    if(!c)
    {
        dp[now][2] = 1;
        return;
    }
    for(ll k:v[now])if(k != f)
    {
        add(dp[now][1],s * pw((2 * dp[k][1] + dp[k][2]),MOD-2) % MOD * (dp[k][0] + dp[k][2]));
    }
    ll tmp = 1;
    for(ll k:v[now])if(k != f)tmp = tmp * (dp[k][1] + dp[k][2]) % MOD;
    dp[now][2] = tmp;
    debug(now,s,tmp);
    dp[now][0] = (s - tmp + MOD) % MOD;
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,-1);
    REP1(i,n)debug(i,dp[i][0],dp[i][1],dp[i][2]);
    cout<<(dp[1][1] + dp[1][2]) % MOD<<endl;
}