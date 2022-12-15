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
#define endl '\n'
#endif // brian
//}

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);
ll n;
map<ll,ll> mp;
vector<ii> d,u;
ll cnt[4*MAXn],id[4*MAXn];
ll bit[4*MAXn];
void add(ll x,ll k)
{
    while(x<4*MAXn)
    {
        bit[x]+=k;
        x+=x&-x;
    }
}
ll qr(ll x)
{
    ll r=0;
    while(x>0)
    {
        r+=bit[x];
        x-=x&-x;
    }
    return r;
}
int main()
{
    cin>>n;
    REP(i,n)
    {
        ll a,b;
        cin>>a>>b;
        if(mp.find(a)==mp.end())mp[a]=a;
        if(mp.find(b)==mp.end())mp[b]=b;
        swap(mp[a],mp[b]);
    }
    debug(mp);
    ll lt=0;
    for(auto &k:mp)
    {
        if(k.X!=lt+1)d.pb(ii(lt+1,k.X-1));
        d.pb(ii(k.Y,k.Y));
        lt=k.X;
    }
    debug(d);
    REP(i,d.size())u.pb(ii(d[i].X,i));
    sort(ALL(u));
    debug(u);
    REP(i,SZ(u))
    {
        id[u[i].Y]=i+1;
        cnt[i+1]+=d[u[i].Y].Y-d[u[i].Y].X+1;
    }
    partial_sum(cnt,cnt+SZ(u)+1,cnt);
    ll ans=0;
    REP(i,SZ(d))
    {
        ll c=qr(id[i]-1);
        ll s=d[i].Y-d[i].X+1;
        ans+=s*(cnt[id[i]-1]-c);
        add(id[i],s);
    }
    cout<<ans<<endl;
}