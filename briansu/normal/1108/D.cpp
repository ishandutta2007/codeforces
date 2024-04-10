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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll dp[MAXn][3], p[MAXn][3];
ll d[MAXn];

int main()
{
    IOS();
    ll n;
    string s;
    cin>>n>>s;
    REP(i,n)
    {
        if(s[i] == 'R')d[i] = 0;
        else if(s[i] == 'G')d[i] = 1;
        else d[i] = 2;
    }
    REP1(i,n-1)REP(j, 3)dp[i][j] = INF;
    dp[0][1] = dp[0][2] = dp[0][0] = 1;
    dp[0][d[0]] = 0;
    REP1(i, n-1)REP(j, 3)
    {
        REP(k, 3)if(k != j)
        {
            if(dp[i-1][k] < dp[i][j])dp[i][j] = dp[i-1][k], p[i][j] = k;
        }
        if(j != d[i])dp[i][j]++;
    }
    ll mn = INF, c = -1;
    REP(i, 3)if(dp[n-1][i] < mn)mn = dp[n-1][i], c = i;
    string ret = "";
    for(int i = n-1;i >= 0;i--)
    {
        if(c == 0)ret.pb('R');
        else if(c == 1)ret.pb('G');
        else ret.pb('B');
        c = p[i][c];
    }
    reverse(ALL(ret));
    cout<<mn<<endl;
    cout<<ret<<endl;

}