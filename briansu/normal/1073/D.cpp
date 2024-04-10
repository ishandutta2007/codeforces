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
#undef brian
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


const ll MAXn=4e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn];
ll bit[2 * MAXn],ct[2 * MAXn];
vector<ii> dt;


void ins(ll x,ll k,ll tp)
{
    while(x < MAXn)
    {
        bit[x] += k;
        ct[x] += tp;
        x += x & -x;
    }
}

ll qr(ll l, ll r)
{
    ll tt = 0;
    while(r)tt += bit[r],r -= r & -r;
    l --;
    while(l)tt -= bit[l],l -= l & -l;
    return tt;
}
ll qrct(ll l, ll r)
{
    ll tt = 0;
    while(r)tt += ct[r],r -= r & -r;
    l --;
    while(l)tt -= ct[l],l -= l & -l;
    return tt;
}

ll n,T;
ll ans = 0,cursum = 0,curct = 0;
void rem(ll x)
{
    ins(x,-d[x],-1);
    ins(x + n,-d[x],-1);
    cursum -= d[x];
    curct --;
}

int main()
{
    IOS();
    cin>>n>>T;
    REP1(i,n)cin>>d[i];
    REP1(i,n)dt.pb(ii(d[i],i)),ins(i,d[i],1),ins(i + n,d[i],1);
    sort(ALL(dt));
    ll now = 1;
    cursum = qr(1,n),curct = n;
    while(SZ(dt))
    {
        ll t = dt.back().Y;
        dt.pop_back();
        debug(t,now,T,cursum,curct,ans);
        if(t < now){
            ll tmp = qr(now,t + n);
            if(T - tmp < 0){
                rem(t);
                continue;
            }
            T -= tmp;
            ans += qrct(now,t+n);
            now = t+1;
        }
        else{
            ll tmp = qr(now,t);
            debug(tmp);
            if(T - tmp < 0){
                rem(t);
                continue;
            }
            T -= tmp;
            ans += qrct(now,t);
            now = t+1;
        }
        if(now == n+1)now = 1;
        debug(now,T);
        ll tmp = T / cursum;
        ans += tmp * curct;
        T -= cursum * tmp;
        rem(t);        
    }
    cout<<ans<<endl;
}