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
const ll INF=ll(1e9) + 5;

ll d[MAXn];

ll dp[MAXn][MAXn];
vector<ii> v;
ll pre[MAXn];

int main()
{
    IOS();
    ll n,s,m,k;
    cin>>n>>s>>m>>k;
    REP1(i,n)cin>>d[i];
    REP(i,s)
    {
        ll l,r;
        cin>>l>>r;
        v.pb({l,r});
    }
    sort(ALL(v));
    ll l = 0,r = INF;
    while(l != r-1)
    {
        ll h = (l+r)/2;
        FILL(pre,0);
        REP1(i,n)if(d[i] <= h)pre[i] = 1;
        REP1(i,n)pre[i] += pre[i-1];
        FILL(dp,0);
        
        REP1(ct,m)
        {
            ll mx = 0;
            ll it = 0;
            REP(i,s)
            {
                while(it < v[i].X)mx = max(mx,dp[ct-1][it]),it++;
                dp[ct][v[i].Y] = max(dp[ct][v[i].Y],mx + pre[v[i].Y] - pre[v[i].X-1]);
            }
            it = n;
            mx = -INF;
            for(int i = s-1;i >= 0;i--)
            {
                while(it >= v[i].X)mx = max(mx,dp[ct-1][it] - pre[it]),it--;
                dp[ct][v[i].Y] = max(dp[ct][v[i].Y],mx + pre[v[i].Y]);
            }
        }
        ll mx = 0;
        REP1(i,m)REP1(j,n)mx = max(mx,dp[i][j]);
        if(mx >= k)r = h;
        else l = h;
    }
    if(r == INF)cout<<-1<<endl;
    else cout<<r<<endl;


}