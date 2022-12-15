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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=ll(1e15);


void add(ll &a,ll b)
{
    a = (a + b) % MOD;
}


ll ct[20][2][(1<<10)],dp[20][2][(1<<10)],pw[25];


ll cal(ll x,ll k){ // <= x and used no more than k kinds of number
    string s = to_string(x);
    FILL(dp,0);
    FILL(ct,0);
    for(char &c:s)c -= '0';
    ct[0][1][0] = 1;
    for(int i = 1;i < SZ(s);i++)ct[i][0][0] = 1;
    pw[0] = 1;
    REP1(i,20)pw[i] = pw[i-1] * 10 % MOD;
    REP1(i,SZ(s))
    {
        REP(I,(1<<10))REP(j,10)
        {
            if(I == 0 && j == 0)continue;
            ll J = (I | (1<<j));
            ll K = j * pw[SZ(s) - i] % MOD;
            if(j < s[i-1])add(ct[i][0][J],ct[i-1][1][I]), add(dp[i][0][J], ct[i-1][1][I] * K + dp[i-1][1][I]);
            else if(j == s[i-1])add(ct[i][1][J],ct[i-1][1][I]), add(dp[i][1][J], ct[i-1][1][I] * K + dp[i-1][1][I]);
            add(ct[i][0][J],ct[i-1][0][I]), add(dp[i][0][J], ct[i-1][0][I] * K + dp[i-1][0][I]);
        }
    }
    ll tt = 0;
    REP(I,(1<<10))
    {
        ll tmp = 0;
        REP(i,10)if((1<<i) & I)tmp++;
        if(tmp > k)continue;
        debug(bitset<10>(I),dp[SZ(s)-1][0][I],dp[SZ(s)-1][1][I]);
        debug(bitset<10>(I),dp[SZ(s)][0][I],dp[SZ(s)][1][I]);
        if(tmp <= k)add(tt,dp[SZ(s)][0][I] + dp[SZ(s)][1][I]);
    }
    return tt;
}

int main()
{
    IOS();
    ll l,r,k;
    cin>>l>>r>>k;
    cout<<(cal(r,k) - cal(l-1,k) + MOD)%MOD<<endl;
}