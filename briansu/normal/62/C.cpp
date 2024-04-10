//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<lf,lf> ii;
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


const ll MAXn=1e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ii operator - (ii a, ii b){return ii(a.X - b.X, a.Y - b.Y);}
lf cros(ii a,ii b){return a.X * b.Y - a.Y * b.X;}
ll sign(lf x){
    if(x > 0)return 1;
    else if(x < 0)return -1;
    else return 0;
}

vector<ii> v[MAXn];

ll n;

bool inter(ii a, ii b,ii c,ii d)
{
    if(sign(cros(c - a, b - a)) * sign(cros(d - a, b - a)) < 0 && sign(cros(a - c, d - c)) * sign(cros(b - c, d - c)) < 0)return 1;
    else return 0;
}

lf gm(ii a,ii b){return (b.Y - a.Y) / (b.X - a.X);}

ii itp(ii a,ii b,ii c,ii d)
{
    if(a.X == b.X)return ii(a.X, gm(c, d) * (a.X - c.X) + c.Y);
    else if(c.X == d.X)return ii(c.X, gm(a, b) * (c.X - a.X) + a.Y);
    else
    {
        lf m1 = gm(a, b), m2 = gm(c, d);
        lf p = (c.Y - a.Y + m2 * a.X - m2 * c.X) / (m1 - m2);
        return ii(a.X + p, a.Y + p * m1);
    }
}

ii mid(ii a,ii b){return ii((a.X + b.X) / 2, (a.Y + b.Y) / 2);}

const lf eps = 0;

bool inbt(ii a,ii b,ii c,ii d)
{
    return cros(a - b, d - b) * cros(c - b, d - b) < eps;
}

bool in(ii p, ll i)
{
    auto &vv = v[i];
    return inbt(vv[0], vv[1], vv[2], p) && inbt(vv[1], vv[2], vv[0], p) && inbt(vv[2], vv[0], vv[1], p);
}

lf sq(lf x){return x * x;}

lf len(ii a,ii b)
{
    ii d = a - b;
    return sqrt(sq(d.X) + sq(d.Y));
}

lf proc(ii a,ii b, ll id)
{
    vector<ii> dt;
    dt.pb(a);
    dt.pb(b);
    REP(i, n)if(i != id)REP(j, 3)
    {
        ii c = v[i][j], d = v[i][(j + 1) % 3];
        if(inter(a, b, c, d))dt.pb(itp(a, b, c, d));
    }
    sort(ALL(dt));
    dt.resize(unique(ALL(dt)) - dt.begin());
    debug(dt);
    lf tt = 0;
    REP(i, SZ(dt) - 1)
    {
        ii md = mid(dt[i], dt[i + 1]);
        bool fg = 1;
        REP(j, n)if(j != id && in(md, j))fg = 0;
        if(fg)tt += len(dt[i], dt[i + 1]);
    }
    return tt;
}

int main()
{
    IOS();
    cin>>n;
    REP(i, n)REP(j, 3)
    {
        ii tmp;
        cin>>tmp.X>>tmp.Y;
        v[i].pb(tmp);
    }
    lf ans = 0;
    REP(i, n)REP(j, 3)
    {
        lf tmp = proc(v[i][j], v[i][(j + 1) % 3], i);
        debug(v[i][j], v[i][(j + 1) % 3], tmp);
        ans += tmp;
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;

}