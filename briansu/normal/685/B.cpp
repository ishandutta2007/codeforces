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
template<typename _a,typename _b> ostream& operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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

const ll MAXn=3e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000;//1000000007;
const ll INF=ll(1e15);

ll n,q;
vector<ll> v[MAXn];
vector<ll> d;
ll t=-1;
ll l[MAXn],c[MAXn],r[MAXn];
ll mx[MAXn],sz[MAXn];
void dfs(ll now)
{
    sz[now]=1;
    mx[now]=-1;
    for(ll k:v[now])
    {
        dfs(k);
        sz[now]+=sz[k];
        if(mx[now]==-1||sz[mx[now]]<sz[k])mx[now]=k;
    }
}
void build(ll now)
{
    d.pb(now);
    if(mx[now]!=-1)
    {
        l[mx[now]]=++t;
        c[mx[now]]=c[now];
        r[c[now]]=t;
        build(mx[now]);
    }
    for(ll k:v[now])
    {
        if(k==mx[now])continue;
        l[k]=++t;
        c[k]=t;
        r[c[k]]=t;
        build(k);
    }

}
ll cal(ll now,ll r)
{
    ll m=(mx[now]==-1?0:sz[mx[now]]);
    m=max(m,sz[r]-sz[now]);
    debug(now,r,m);
    return m;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    REP(i,n-1)
    {
        ll k;
        cin>>k;
        k--;
        v[k].pb(i+1);
    }
    dfs(0);
    l[0]=++t;
    c[0]=0;
    r[0]=t;
    build(0);
    #ifdef brian
    _OUTC(cout,l,l+n);
    _OUTC(cout,r,r+n);
    _OUTC(cout,c,c+n);
    _OUTC(cout,sz,sz+n);
    debug(d);
    #endif // brian
    REP(i,q)
    {
        ll k;
        cin>>k;
        k--;
        ll a=l[k];
        ll b=r[c[k]]+1;
        while(a!=b-1)
        {
            debug(a,b);
            ll h=(a+b)/2;
            if(cal(d[h],k)<cal(d[h-1],k))a=h;
            else b=h;
        }
        cout<<d[a]+1<<endl;
    }
}