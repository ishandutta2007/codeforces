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


const ll MAXn=5e7+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll pw(ll x,ll k)
{
    if(!k)return 1;
    ll a = pw(x, k / 2);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

ii operator * (ii a,ii b)
{
    return ii((a.X * b.X) % MOD, (a.Y * b.Y) % MOD);
}
ii operator + (ii a,ii b)
{
    return ii((a.X*b.Y + b.X * a.Y) % MOD, (a.Y * b.Y) % MOD);
}


int ispm[MAXn];
vector<ll> pm;

ii dp[52][2][52];

vector<ii> p;

int main()
{
    IOS();
    for(ll i = 2;i < MAXn;i ++)
    {
        if(!ispm[i])pm.pb(i);
        for(int j = 0;pm[j] * i < MAXn;j ++)
        {
            ispm[pm[j] * i] = 1;
            if(i % pm[j] == 0)break;
        }
    }
    ll n, k;
    cin>>n>>k;
    for(ll x:pm)
    {
        if(n % x == 0)
        {
            p.pb(ii(x, 0));
            while(n % x == 0)
            {
                p.back().Y += 1;
                n /= x;
            }
        }
    }
    if(n != 1)p.pb(ii(n, 1));
    ll mx = 0;
    for(ii tmp:p)mx = max(mx, tmp.Y);
    bool fg = 0;
    REP(i, mx + 1)REP(j,2)REP(l, mx + 1)dp[i][j][l] = ii(0, 1);
    REP(i, mx + 1)dp[i][0][i] = ii(1,1);
    debug(123);
    for(int j = 0;j < k;j ++)
    {
        fg = !fg;
        REP(i, mx + 1)REP(l, mx + 1)dp[i][fg][l] = ii(0, 1);
        for(int i = 0;i <= mx;i ++)
        {
            ii tmp = ii(0, 1);
            for(int l = i;l >= 0;l --)
            {
                tmp = tmp + ii(1, l + 1) * dp[i][!fg][l];
                dp[i][fg][l] = dp[i][fg][l] + tmp;
            }
        }
    }
    
    debug(456);

    ii ans = ii(1, 1);
    for(ii tmp: p)
    {
        ll x = 1;
        ii t = ii(0, 1);
        for(int i = 0;i <= tmp.Y;i ++)
        {
            t = t + ii(x, 1) * dp[tmp.Y][fg][i];
            x = x * tmp.X % MOD;
        }
        ans = ans * t;
    }
    cout<<ans.X * pw(ans.Y, MOD-2) % MOD<<endl;

}