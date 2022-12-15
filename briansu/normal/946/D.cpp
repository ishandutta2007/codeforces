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
const ll MOD=1000000007;
const ll INF=ll(1e15);

int d[MAXn][MAXn],dp[MAXn][MAXn],mn[MAXn];



int main()
{
    IOS();
    ll n,m,k;
    cin>>n>>m>>k;
    REP1(i,n)
    {
      string s;
      cin>>s;
      REP(j,m)d[i][j+1]=s[j]-'0';
      REP1(j,m)d[i][j]+=d[i][j-1];
      pary(d[i],d[i]+m+1);
    }
    REP1(i,n)
    {
      REP(j,k+1)dp[i][j]=MAXn*MAXn;
      REP(j,k+1)mn[j]=m;
      REP1(a,m)for(int b=a-1;b<=m;b++)
      {
        ll ct=d[i][m]-(d[i][b]-d[i][a-1]);
        debug(i,a,b,ct,b-a+1);
        if(ct<=k)mn[ct]=min((ll)mn[ct],b-a+1);
      }
      REP(j,k+1)REP(x,k+1)if(j+x<=k)dp[i][j+x]=min(dp[i][j+x],dp[i-1][j]+mn[x]);
    }
    REP1(i,n)REP(j,k+1)debug(i,j,dp[i][j]);
    int ans=MAXn*MAXn;
    REP(i,k+1)ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
}