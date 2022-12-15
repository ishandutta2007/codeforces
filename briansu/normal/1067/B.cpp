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
ll vis[MAXn],dg[MAXn],h[MAXn];

void qt()
{
    cout<<"No"<<endl;
    exit(0);
}

int main()
{
    IOS();
    ll n,k;
    cin>>n>>k;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        dg[a]++;
        dg[b]++;
    }
    queue<ll> q;
    FILL(h,-1);

    REP1(i,n)if(dg[i] == 1)
    {
        vis[i] = 1;
        h[i] = 0;
        q.push(i);
    }
    while(SZ(q))
    {
        ll t = q.front();q.pop();
        for(ll x:v[t])if(!vis[x])
        {
            if(h[x] != -1 && h[x] != h[t] + 1)qt();
            h[x] = h[t] + 1;
            dg[x]--;
            if(dg[x] == 1)
            {
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    ll ct = 0;
    debug(234);
    pary(h+1,h+1+n);
    REP1(i,n)
    {
        if(h[i] > k)qt();
        if(h[i] == k)ct++;
    }
    if(ct != 1)qt();
    debug(123);
    REP1(i,n)
    {
        if(h[i] != k && h[i] != 0 && SZ(v[i]) < 4)qt();
        else if(h[i] == k && SZ(v[i]) < 3)qt();
    }
    cout<<"Yes"<<endl;

}