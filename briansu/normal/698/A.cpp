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
//#define endl '\n'
#endif // brian
//}

const ll MAXn=1e2+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000;//1000000007;
const ll INF=ll(1e15);

ll n;
ll dp[MAXn][3];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,101)REP(j,3)dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        ll t;
        cin>>t;
        REP(j,3)dp[i][0]=min(dp[i][0],dp[i-1][j]);
        dp[i][0]++;
        if(t==2||t==3)dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        if(t==1||t==3)dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
    }
    cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<endl;
}