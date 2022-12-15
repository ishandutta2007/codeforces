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


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

bitset<MAXn * MAXn> dp[2][MAXn][MAXn];
ll ct[MAXn];

ll C = 100,CC = 10000 + 2;

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP(i,n)
    {
        ll x;
        cin>>x;
        ct[x] ++;
    }
    vector<ll> v;
    REP1(i,C)if(ct[i])v.pb(i);
    if(SZ(v) <= 2)
    {
        cout<<n<<endl;
        return 0;
    }
    dp[0][0][0][0] = 1;
    REP1(i,C)
    {
        REP(j,C+1)dp[0][i][j] = dp[0][i-1][j];
        REP(_,ct[i])for(int j = C;j > 0;j--)dp[0][i][j] |= (dp[0][i][j-1]<<i);
    }
    dp[1][C+1][0][0] = 1;
    for(int i = C; i > 0;i--)
    {
        REP(j,C+1)dp[1][i][j] = dp[1][i+1][j];
        REP(_,ct[i])for(int j = C;j > 0;j--)dp[1][i][j] |= (dp[1][i][j-1]<<i);
    }

    ll mx = 0;
    REP1(i,C)REP1(j,ct[i])
    {
        bool ok = 1;
        for(int k = 0;k <= j;k++)for(int l = 0;l <= i * j;l++)if(dp[0][i-1][k][l] && dp[1][i+1][j-k][i * j - l])
        {
            ok = 0;
            break;
        }
        if(ok)debug(i,j);
        if(ok)mx = max(mx,j);
        else break;

    }
    cout<<mx<<endl;
}