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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll p[MAXn][MAXlg],st[MAXn][MAXlg],dph[MAXn],lg[MAXn];
ll lca(ll a,ll b)
{
    if(dph[a] < dph[b])swap(a,b);
    for(int i = MAXlg-1;i >= 0;i--)if(dph[p[a][i]] >= dph[b])a = p[a][i];
    if(a == b)return a;
    for(int i = MAXlg-1;i >= 0;i--)if(p[a][i] != p[b][i])a = p[a][i],b = p[b][i];
    return p[a][0];
}

ll cal(ll l,ll r)
{
    ll di = lg[r - l + 1];
    return lca(st[l][di],st[r - (1<<di) + 1][di]);
}

ll rm(ll l,ll r,ll x)
{
    if(x == l)return cal(l+1,r);
    else if(x == r)return cal(l,r-1);
    else return lca(cal(l,x-1),cal(x+1,r));
}

vector<ll> v[MAXn];

void dfs(ll now,ll f)
{
    for(ll k:v[now])if(k!=f)
    {
        dph[k] = dph[now] + 1;
        dfs(k,now);
    }
}

int main()
{
    IOS();
    REP1(i,MAXn-1)lg[i] = __lg(i);
    ll n,q;
    cin>>n>>q;
    p[1][0] = 1;
    dph[1] = 0;
    for(int i = 2;i <= n;i ++)cin>>p[i][0],v[p[i][0]].pb(i);
    dfs(1,-1);
    pary(dph+1,dph+1+n);
    for(int j = 1;j < MAXlg;j ++)REP1(i,n)p[i][j] = p[p[i][j-1]][j-1];
    REP1(i,n)st[i][0] = i;
    for(int j = 1;j < MAXlg;j ++)REP1(i,n)if(i + (1<<(j-1)) <= n)st[i][j] = lca(st[i][j-1],st[i + (1<<(j-1))][j-1]);
    debug(cal(3,3));
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll mn = dph[cal(l,r)];
        ll tmpl = l,tmpr = r;
        while(tmpl != tmpr-1)
        {
            ll h = (tmpl+tmpr)/2;
            if(dph[cal(l,h)] != mn)tmpl = h;
            else tmpr = h;
        }
        ll b = tmpl + 1;
        tmpl = l, tmpr = b;
        while(tmpl != tmpr - 1)
        {
            ll h = (tmpl+tmpr)/2;
            if(dph[cal(h,b)] != mn)tmpr = h;
            else tmpl = h;
        }
        ll a = tmpr - 1;
        assert(dph[lca(a,b)] == mn);
        if(dph[rm(l,r,a)] < dph[rm(l,r,b)])swap(a,b);
        cout<<a<<" "<<dph[rm(l,r,a)]<<endl;
    }
}