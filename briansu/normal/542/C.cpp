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


const ll MAXn=2e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> lp;
ll vis[MAXn], p[MAXn], dis[MAXn];

ll ct = 0;
bool dfs1(ll now, ll g)
{
    vis[now] = 1;
    ct ++;
    if(vis[p[now]])
    {
        if(p[now] == g)return 1;
        else return 0;
    }
    return dfs1(p[now], g);
}

void dfs2(ll now)
{
    if(dis[p[now]] == -1)dfs2(p[now]);
    dis[now] = dis[p[now]] + 1;
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>p[i];
    FILL(dis, -1);
    for(int i = 1;i <= n;i ++)
    {
        FILL(vis, 0);
        ct = 0;
        if(dfs1(i, i))dis[i] = 0, lp.pb(ct);
    }
    pary(dis + 1, dis + 1 + n);
    for(int i = 1;i <= n;i ++)if(dis[i] == -1)dfs2(i);
    ll ans = 1;
    for(ll t:lp)
    {
        ll g = __gcd(ans, t);
        ans = ans * (t/g);
    }
    pary(dis + 1, dis + 1 + n);
    ll mx = ans;
    for(int i = 1;i <= n;i ++)if(ans < dis[i])mx = max(mx, ((dis[i] - 1) / ans + 1) * ans);
    cout<<mx<<'\n';

}