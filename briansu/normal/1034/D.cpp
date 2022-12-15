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


const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);


/*struct node{
    ll l, r;
    node *lc, *rc;
    ll tg, tt, ltt;
    node(ll li, ll ri, node *lci = 0, node *rci = 0):l(li), r(ri), lc(lci), rc(rci), tg(0), tt(0), ltt(0){}
    void pull()
    {
        tt = (r - l) * tg;
        ltt = tg;
        if(l != r-1)tt += lc->tt + rc->tt, ltt += lc->ltt;
    }
    void ins(ll li,ll ri, ll k)
    {
        if(li >= r || ri <= l)return;
        else if(li <= l && ri >= r)tg += k, pull();
        else lc->ins(li, ri, k), rc->ins(li, ri, k), pull();
    }
    ll fd(ll x, ll k = 0) // find and add all > x
    {
        k += tg;
        if(l == r-1)return gtt += k, l;
        else if(rc->ltt + k <= x)return lc->fd(x, k);
        else return gtt += k * (lc->r - lc->l) + lc->tt, rc->fd(x, k);
    }
    void clr(){
        tg = tt = ltt = 0;
        if(l != r-1)lc->clr(), rc->clr();
    }
};

node *build(ll l, ll r)
{
    if(l == r-1)return new node(l, r);
    else return new node(l, r, build(l, (l + r) / 2), build((l + r) / 2, r));
}*/

ii d[MAXn];
vector<ii> cv[MAXn];
set<pair<ii, ll>> st;
ll gtt, ct;
ll dt[MAXn];

ll n, k;

void go(ll h)
{
    FILL(dt, 0);
    gtt = 0, ct = 0;
    ll it = 0, tt = 0, cur = 0;
    REP1(i, n)
    {
        for(auto &p:cv[i])
        {
            tt += min(it, p.X) * p.Y;
            if(p.X >= it)cur += p.Y, dt[p.X] += p.Y;
        }
        ll t = d[i].Y - d[i].X;
        cur += t, dt[i] += t;
        tt += it * t;
        while(cur - dt[it] > h)cur -= dt[it], it ++, tt += cur;
        ct += it, gtt += tt;
    }
}

int main()
{
    IOS();
    cin>>n>>k;
    REP1(i, n)cin>>d[i].X>>d[i].Y;
    REP1(i ,n)
    {
        auto &v = cv[i];
        auto nit = st.begin();
        while((nit = st.lower_bound({{d[i].Y, d[i].Y}, -1})) != st.begin())
        {
            auto it = prev(nit);
            ii p = it->X;ll t = it->Y;
            if(p.Y <= d[i].X)break;
            st.erase(it);
            if(p.X < d[i].X && p.Y <= d[i].Y)v.pb(ii(t, -(p.Y - d[i].X))), st.insert({{p.X, d[i].X}, t});
            else if(p.X >= d[i].X && p.Y <= d[i].Y)v.pb(ii(t, -(p.Y - p.X)));
            else if(p.Y > d[i].Y && p.X >= d[i].X)v.pb(ii(t, -(d[i].Y - p.X))), st.insert({{d[i].Y, p.Y}, t});
            else v.pb(ii(t, -(d[i].Y - d[i].X))), st.insert({{p.X, d[i].X}, t}), st.insert({{d[i].Y, p.Y}, t});
        }
        st.insert({d[i], i});
    }

    ll l = 0, r = 1000000000LL;
    while(l != r-1)
    {
        ll h = (l + r) / 2;
        go(h);
        if(ct < k)r = h;
        else l = h;
    }
    go(r);
    gtt += (k - ct) * r;
    cout<<gtt<<endl;
}