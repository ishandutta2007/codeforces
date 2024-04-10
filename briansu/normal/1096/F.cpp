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
const ll MOD=998244353;
const ll INF=ll(1e15);

ll pw(ll x,ll k)
{
    if(!k)return 1;
    ll a = pw(x, k>>1);
    a = a * a % MOD;
    if(k & 1)return a * x % MOD;
    else return a;
}

ll d[MAXn], bit[MAXn], p[MAXn];

void ins(ll x,ll k)
{
    while(x < MAXn)bit[x] += k, x += x & -x;
}

ll qr(ll x)
{
    ll ret = 0;
    while(x)ret += bit[x], x -= x & -x;
    return ret;
}

ii operator + (const ii a, const ii b){
    return ii((a.X * b.Y + a.Y * b.X) % MOD, a.Y * b.Y % MOD);
}

ii operator * (const ii a,const ii b)
{
    return ii(a.X * b.X % MOD, a.Y * b.Y % MOD);
}

int main()
{
    IOS();
    ll n;
    cin>>n;
    ii ans = ii(0, 1);
    ll ct = 0, oans = 0;
    REP(i,n)cin>>d[i];
    REP(i,n)if(d[i] == -1)ct++;
    ans = ans + ii(ct * (ct - 1) / 2 % MOD, 2);
    for(int i = n-1;i >= 0;i --)if(d[i] != -1)
    {
        oans += qr(d[i]);
        ins(d[i], 1);
    }
    debug(oans);
    ans = ans + ii(oans % MOD, 1);
    debug(ans);
    REP(i,n)if(d[i] != -1)p[d[i]] = 1;
    for(int i = n;i > 0;i --)p[i] = p[i+1] + !p[i];
    ll tct = 0;
    if(ct)REP(i,n)if(d[i] != -1)
    {
        debug(i, ii(tct * p[d[i]] % MOD, ct));
        ans = ans + ii(tct * p[d[i]] % MOD, ct);
        ans = ans + ii((ct - tct) * (ct - p[d[i]]) % MOD, ct);
    }else tct++;
    debug(ans);
    cout<<ans.X * pw(ans.Y, MOD-2)%MOD<<endl;
}