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


const ll MAXn=5e1+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn][MAXn];
ll dp[MAXn][MAXn][MAXn][MAXn];

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i, n)
    {
        string s;
        cin>>s;
        REP1(j, n)d[i][j] = (s[j - 1] == '#');
    }
    REP1(l1, n)
    {
        for(int i = 1;i + l1 - 1 <= n;i ++)
        {
            REP1(l2, n)
            {
                for(int j = 1;j + l2 - 1 <= n;j ++)
                {
                    ll a = i + l1 - 1;
                    ll b = j + l2 - 1;
                    ll &p = dp[i][j][a][b];
                    if(l1 == 1 && l2 == 1 && !d[i][j])p = 0;
                    else p = max(l1, l2);
                    for(int k = i;k < a;k ++)p = min(p, dp[i][j][k][b] + dp[k + 1][j][a][b]);
                    for(int k = j;k < b;k ++)p = min(p, dp[i][j][a][k] + dp[i][k + 1][a][b]);
                }
            }
        }
    }
    cout<<dp[1][1][n][n]<<endl;
}