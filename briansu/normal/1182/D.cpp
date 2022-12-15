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

vector<ll> v[MAXn];
ll dis1[MAXn], dis2[MAXn], dis3[MAXn], dg[MAXn], u[MAXn];
ll n;

void disdfs(ll now, ll f, ll *dis)
{
    for(ll k:v[now])if(k != f)dis[k] = dis[now] + 1, disdfs(k, now, dis);
}

void chk(ll x)
{
    dis3[x] = 0;
    disdfs(x, -1, dis3);
    REP(i, n)dg[i] = -1;
    REP1(i,n)
    {
        if(dg[dis3[i]] == -1)dg[dis3[i]] = SZ(v[i]);
        else if(dg[dis3[i]] != SZ(v[i]))return;
    }
    debug(x);
    REP1(i,n)debug(i, dis3[i]);
    cout<<x<<endl;
    exit(0);
}

void go(ll now,ll f)
{
    u[now] = 1;
    for(ll k:v[now])if(k != f && SZ(v[k]) <= 2)go(k, now);
}

int main()
{
    IOS();
    cin>>n;
    REP1(i, n-1)
    {
        ll a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    

    ll a, b;
    disdfs(1, -1, dis1);
    a = 1;
    REP1(i,n)if(dis1[i] > dis1[a])a = i;
    disdfs(a, -1, dis2);
    b = a;
    REP1(i,n)if(dis2[i] > dis2[b])b = i;
    if(dis2[b]&1)
    {
        chk(a);
        chk(b);
        cout<<-1<<endl;
        return 0;
    }
    dis1[b] = 0;
    disdfs(b, -1, dis1);
    ll c = -1;
    REP1(i,n)if(dis1[i] == dis2[b] / 2 && dis2[i] == dis2[b] / 2)c = i;
    assert(c != -1);
    chk(c);
    dis1[c] = 0;
    disdfs(c, -1, dis1);
    vector<ll> dt;
    REP1(i,n)if(SZ(v[i]) == 1)dt.pb(i);
    sort(ALL(dt), [](int a, int b){return dis1[a] < dis1[b];});
    chk(dt.front());
    chk(dt.back());
    go(c, -1);
    REP1(i,n)if(SZ(v[i]) == 1 && u[i])
    {
        chk(i);
        break;
    }
    cout<<-1<<endl;


}