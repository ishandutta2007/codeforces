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


const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

namespace seg{ // max
    const ll N = (1<<18);
    ii d[2 * N];
    set<ii> st[2 * N];
    void ins(ll x,ii k)
    {
        x += N;
        st[x].insert(k);
        for(d[x] = *st[x].rbegin();x > 1;x >>= 1)d[x>>1] = max(d[x], d[x ^ 1]);
    }
    void rm(ll x,ii k)
    {
        x += N;
        st[x].erase(k);
        for(d[x] = (SZ(st[x]) ? *st[x].rbegin() : ii(0, 0));x > 1;x >>= 1)d[x>>1] = max(d[x], d[x ^ 1]);
    }
    ii qr(ll l,ll r)
    {
        ii ret = ii(0, 0);
        for(l += N, r += N;l < r;l >>= 1, r >>= 1)
        {
            if(l & 1)ret = max(ret, d[l ++]);
            if(r & 1)ret = max(ret, d[-- r]);
        }
        return ret;
    }
}

struct tg{
    ll l, r, c;
};

ii v[MAXn];
tg c[MAXn];

vector<ll> vdt;
vector<ll> cdt;

int main()
{
    IOS();
    ll ans = 0;
    ii bst = {0, 0};
    ll n, m;
    cin>>n>>m;
    REP1(i, n)cin>>v[i].X>>v[i].Y;
    REP1(i, m)cin>>c[i].l>>c[i].r>>c[i].c;

    REP1(i, n)vdt.pb(i);
    REP1(i, m)cdt.pb(i);

    // c v v c
    {
        sort(ALL(cdt), [](auto a, auto b){return c[a].r < c[b].r;});
        sort(ALL(vdt), [](auto a, auto b){return v[a].Y < v[b].Y;});
        vector<ll> uni;
        REP1(i, n)uni.pb(v[i].X);
        sort(ALL(uni));
        uni.resize(unique(ALL(uni)) - uni.begin());
        ll it = 0;
        for(ll t:cdt)
        {
            while(it < SZ(vdt) && v[vdt[it]].Y <= c[t].r)
            {
                seg::ins(lower_bound(ALL(uni), v[vdt[it]].X) - uni.begin(), {v[vdt[it]].Y - v[vdt[it]].X, vdt[it]});
                it ++;
            }
            auto p = seg::qr(lower_bound(ALL(uni), c[t].l) - uni.begin() , upper_bound(ALL(uni), c[t].r) - uni.begin());
            if(p.X * c[t].c > ans)
            {
                ans = c[t].c * p.X;
                bst = {p.Y, t};
            }
        }
    }

    // v c v c
    {
        set<ii> st;
        sort(ALL(cdt), [](auto a, auto b){return c[a].l < c[b].l;});
        sort(ALL(vdt), [](auto a, auto b){return v[a].X < v[b].X;});
        ll it = 0;
        for(ll t:cdt)
        {
            while(it < SZ(vdt) && v[vdt[it]].X <= c[t].l)
            {
                st.insert({v[vdt[it]].Y, vdt[it]});
                it ++;
            }
            if(!SZ(st))continue;
            auto p = *st.rbegin();
            if(p.X < c[t].l)continue;
            ll a = min(c[t].r, p.X) - c[t].l;
            if(a * c[t].c > ans)
            {
                ans = c[t].c * a;
                bst = {p.Y, t};
            }
        }
    }

    // c v c v
    {
        set<ii> st;
        sort(ALL(cdt), [](auto a, auto b){return c[a].r > c[b].r;});
        sort(ALL(vdt), [](auto a, auto b){return v[a].Y > v[b].Y;});
        ll it = 0;
        for(ll t:cdt)
        {
            while(it < SZ(vdt) && v[vdt[it]].Y >= c[t].r)
            {
                st.insert({v[vdt[it]].X, vdt[it]});
                it ++;
            }
            if(!SZ(st))continue;
            auto p = *st.begin();
            if(p.X > c[t].r)continue;
            ll a = c[t].r - max(c[t].l, p.X);
            if(a * c[t].c > ans)
            {
                ans = c[t].c * a;
                bst = {p.Y, t};
            }
        }
    }

    cout<<ans<<endl;
    if(ans != 0)cout<<bst.X<<" "<<bst.Y<<endl;

}