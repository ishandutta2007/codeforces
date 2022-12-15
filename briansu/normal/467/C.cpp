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
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#endif // brian
//}

const ll MAXn=5e3+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(2e18);


ll d[MAXn];
ll dp[MAXn][MAXn];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    REP(i,n)cin>>d[i+1];
    partial_sum(d,d+n+1,d);
    pary(d+1,d+n+1);
    for(ll i=1;i<=k;i++)
    {
        ll mx=0;
        for(ll j=i*m;j<=n;j++)
        {
            mx=max(mx,dp[i-1][j-m]);
            dp[i][j]=mx+d[j]-d[j-m];
        }
        //pary(dp[i],dp[i]+n);
    }
    ll ans=0;
    REP(i,n)ans=max(ans,dp[k][i+1]);
    cout<<ans<<endl;
}