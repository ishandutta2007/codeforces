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


const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn], bit[MAXn], ctbit[MAXn];
void ins(ll x,ll k)
{
    x++;
    while(x < MAXn)bit[x] += k, ctbit[x] ++, x += x & -x;
}
ii qr(ll x)
{
    x++;
    ll ret = 0, retct = 0;
    while(x) ret += bit[x], retct += ctbit[x], x -= x & -x;
    return ii(ret, retct);
}

ll suf[MAXn], pre[MAXn];

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i,n)cin>>d[i];
    sort(d + 1,d+ 1 + n, greater<ll>());
    for(int i = n;i >= 1;i --)
    {
        ins(d[i], d[i]);
        ii tmp = qr(i);
        suf[i] = tmp.X + (n - i + 1 - tmp.Y) * i;
        debug(i, suf[i]);
    }
    {
        ll s = 0;
        REP1(i,n)
        {
            s += d[i-1];
            suf[i] = suf[i] + i * (i-1) - s; 
        }
    }
    for(int i = n-1;i >= 1;i --)suf[i] = min(suf[i], suf[i+1]);
    suf[n+1] = INF;
    FILL(bit, 0);
    FILL(ctbit, 0);
    for(int i = n;i >= 1;i --)
    {
        ii tmp = qr(i);
        pre[i] = tmp.X + (n - i - tmp.Y) * i;
        ins(d[i], d[i]);
    }
    {
        ll s = 0;
        REP1(i,n)
        {
            s += d[i];
            debug(i, s, s - i * (i-1), pre[i] + i);
            if(s - i * (i-1)  > pre[i] + i)pre[i] = INF;
            else pre[i] = s - i * (i-1) - pre[i];
        }
    }
    REP1(i,n)pre[i] = max(pre[i], pre[i-1]);
    pre[0] = -1;
    ll it = 0, s = 0;
    REP1(i,n)s += d[i];
    REP(i,n + 2)debug(i, pre[i], suf[i]);
    vector<ll> ans;
    for(int i = n;i >= 0;i --)
    {
        while(it < n && d[it + 1] >= i)it++;
        if((s + i) % 2 == 0 && i >= pre[it] && i <= suf[it + 1])ans.pb(i);
    }
    sort(ALL(ans));
    if(SZ(ans) == 0)cout<<-1<<endl;
    else for(ll x:ans)cout<<x<<" ";
}