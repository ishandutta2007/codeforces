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

ll dis[MAXn];
vector<ii> v[MAXn];
priority_queue<ii,vector<ii>,greater<ii> > pq;
ll p[MAXn];

int main()
{
    IOS();
    ll n,m;
    cin>>n>>m;
    REP(i,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].pb(ii(b,c));
        v[b].pb(ii(a,c));
    }
    REP1(i,n)debug(i,v[i]);
    REP1(i,n)dis[i] = INF;
    dis[1] = 0;
    pq.push({0,1});
    while(SZ(pq))
    {
        ll t = pq.top().Y,tmpdis = pq.top().X;
        pq.pop();
        if(dis[t] != tmpdis)continue;
        debug(t,dis[t]);
        for(ii tmp:v[t])if(dis[t] + tmp.Y < dis[tmp.X])
        {
            dis[tmp.X] = dis[t] + tmp.Y;
            pq.push({dis[tmp.X],tmp.X});
            p[tmp.X] = t;
        }
    }
    if(dis[n] == INF)
    {
        cout<<-1<<endl;
        return 0;
    }
    debug(dis[n]);
    vector<ll> h;
    ll now = n;
    h.pb(now);
    while(now != 1)
    {
        h.pb(p[now]);
        now = p[now];
    }
    reverse(ALL(h));
    for(ll x:h)cout<<x<<" ";
}