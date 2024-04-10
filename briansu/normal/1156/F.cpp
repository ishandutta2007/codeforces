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


const ll MAXn=5e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=ll(1e15);

// ii(a, b) => a / b
ii operator * (ii a, ii b){return ii(a.X * b.X % MOD, a.Y * b.Y % MOD);}
ii operator + (ii a, ii b){return ii((a.X * b.Y + b.X * a.Y) % MOD, a.Y * b.Y % MOD);}
ii operator - (ii a, ii b){return ii(((a.X * b.Y - b.X * a.Y) % MOD + MOD) % MOD, a.Y * b.Y % MOD);}

ll pw(ll x,ll k)
{
    ll I = 1, t = x, tt = 1;
    for(;I <= k;I <<= 1, t = t * t % MOD)if(I & k)tt = tt * t % MOD;
    return tt;
}

ii dp[MAXn][MAXn]; // i left, last is j
ll ct[MAXn], pre[MAXn];

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)
    {
        ll t;
        cin>>t;
        ct[t]++;
    }
    REP1(i,n)pre[i] = ct[i] + pre[i-1];
    REP1(i, n)dp[n][i] = ii(0, 1);
    dp[n][0] = ii(1, 1);
    ii tt = ii(0, 1);
    for(int i = n-1;i >= 0;i --)
    {
        dp[i][0] = ii(0, 1);
        ii tmp = ii(0, 1);
        for(int j = 1;j <= n;j ++)
        {
            tmp = tmp + dp[i+1][j-1];
            dp[i][j] = tmp * ii(ct[j], i + 1);
            tt = tt + dp[i+1][j] * ii(ct[j] - 1, i + 1);
        }
    }
    cout<<tt.X * pw(tt.Y, MOD-2) % MOD<<endl;
}