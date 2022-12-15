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


const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn][MAXn],fg[MAXn][MAXn];
ii af[MAXn][MAXn];
vector<ii> dt[2 * MAXn];
string ans="";

int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP(i,n)
    {
        string s;
        cin>>s;
        REP(j,n)d[i][j] = s[j] - 'a';
    }
    REP(i,n)REP(j,n)dt[i+j].pb(ii(i,j));
    fg[0][0] = 1;
    if(!d[0][0])ans.pb('a');
    else if(k)af[0][0]=ii(0,1),ans.pb('a');
    else ans.pb(d[0][0] + 'a');
    for(int t = 1;t <= 2 * (n-1);t++)
    {
        ll mn = INF;
        for(ii now : dt[t])
        {
            ll x = now.X,y = now.Y;
            af[x][y] = ii(26,0);
            if(x != 0 && fg[x-1][y])
            {
                if(af[x-1][y].Y == k || !d[x][y])af[x][y] = min(af[x][y],ii(d[x][y],af[x-1][y].Y));
                else af[x][y] = min(af[x][y],ii(0,af[x-1][y].Y + 1));
            }
            if(y != 0 && fg[x][y-1])
            {
                if(af[x][y-1].Y == k || !d[x][y])af[x][y] = min(af[x][y],ii(d[x][y],af[x][y-1].Y));
                else af[x][y] = min(af[x][y],ii(0,af[x][y-1].Y + 1));
            }
        }
        for(ii now:dt[t])mn = min(mn,af[now.X][now.Y].X);
        assert(mn < 26);
        for(ii now: dt[t])if(af[now.X][now.Y].X == mn)fg[now.X][now.Y] = 1;
        ans.pb('a' + mn);
    }
    cout<<ans<<endl; 
}