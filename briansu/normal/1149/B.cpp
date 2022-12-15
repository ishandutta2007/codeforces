//{
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
const ll MOD=1000000007;
const ll INF=ll(1e7);

ll nxt[MAXn][30];

ll dp[255][255][255];

string d[4];
ll n, q;
string s;

void cal(ll a,ll b,ll c)
{
    ll ret = INF;
    if(a != 0 && dp[a-1][b][c] != INF)ret = min(ret, nxt[dp[a-1][b][c]+1][d[1][a-1] - 'a']);
    if(b != 0 && dp[a][b-1][c] != INF)ret = min(ret, nxt[dp[a][b-1][c]+1][d[2][b-1] - 'a']);
    if(c != 0 && dp[a][b][c-1] != INF)ret = min(ret, nxt[dp[a][b][c-1]+1][d[3][c-1] - 'a']);
    //debug(a, b, c, ret);
    dp[a][b][c] = ret;
}


int main()
{
    IOS();
    
    cin>>n>>q>>s;
    REP(i,n+1)REP(j,26)nxt[i][j] = INF;
    REP(i,n)nxt[i][s[i]-'a'] = i;
    for(int i = n-1;i >= 0;i --)REP(j,26)nxt[i][j] = min(nxt[i][j], nxt[i+1][j]);
    //debug(nxt[3][2]);
    REP(i,n)REP(j, 3)debug(i, j, nxt[i][j]);
    dp[0][0][0] = -1;
    while(q--)
    {
        char tp;
        ll t;
        cin>>tp>>t;
        if(tp == '-')d[t].pop_back();
        else{
            char c;
            cin>>c;
            d[t].pb(c);
            
            if(t == 1)REP(i, SZ(d[2]) + 1)REP(j, SZ(d[3]) + 1)cal(SZ(d[t]), i, j);
            else if(t == 2)REP(i, SZ(d[1]) + 1)REP(j, SZ(d[3]) + 1)cal(i, SZ(d[t]), j);
            else REP(i, SZ(d[1]) + 1)REP(j, SZ(d[2]) + 1)cal(i, j, SZ(d[t]));
        }
        debug(SZ(d[1]), SZ(d[2]), SZ(d[3]), dp[SZ(d[1])][SZ(d[2])][SZ(d[3])]);
        if(dp[SZ(d[1])][SZ(d[2])][SZ(d[3])] != INF)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}