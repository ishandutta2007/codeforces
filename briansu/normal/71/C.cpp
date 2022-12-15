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
#define endl '\n'
#endif // brian
//}


const ll MAXn=2e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e18);



ll n;
bool d[MAXn];
vector<ll> pm;
vector<ll> p;
bool dp[MAXn][20];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<MAXn;i++)
    {
        bool b=1;
        for(int j=0;j<SZ(pm)&&pm[j]*pm[j]<=i;j++)if(i%pm[j]==0){b=0;break;}
        if(b)pm.pb(i);
    }
    cin>>n;
    REP(i,n)cin>>d[i];
    pm[0]=3;
    pm[1]=4;
    for(int j=0;j<SZ(pm)&&pm[j]<=n;j++)if(n%pm[j]==0)p.pb(n/pm[j]);
    debug(p);
    REP(i,n)
    {
        REP(j,SZ(p))
        {
            if(i<p[j])dp[i][j]=d[i];
            else dp[i][j]=d[i]&dp[i-p[j]][j];
        }
    }
    REP(i,SZ(p))
    {
        bool b=0;
        for(int j=n-p[i];j<n;j++)if(dp[j][i])b=1;
        if(b){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
}