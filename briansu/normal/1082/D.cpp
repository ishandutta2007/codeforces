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

vector<ll> one, two;
ll d[MAXn], u[MAXn];

vector<ii> e;

priority_queue<ii> pq;

int main()
{
    IOS();
    ll n;
    cin>>n;
    REP1(i,n)cin>>d[i];
    REP1(i,n)if(d[i] == 1)one.pb(i);else two.pb(i);
    if(!SZ(one))
    {
        cout<<"YES "<<n-1<<endl;
        cout<<n-1<<endl;
        REP1(i,n-1)cout<<i<<" "<<i+1<<endl;
        return 0;
    }
    ll ans = max(1, SZ(two) - 1 + min(2, SZ(one)));
    REP1(i, SZ(one) - 1)pq.push(ii(1, one[i]));
    for(ll x:two)pq.push(ii(d[x], x));
    ll lst = one[0];
    u[one[0]] = 1;
    while(SZ(pq))
    {
        ii t = pq.top();
        debug(t);
        pq.pop();
        if(d[lst])
        {
            e.pb(ii(lst, t.Y));
            d[lst]--;
            d[t.Y]--;
            lst = t.Y;
            u[t.Y] = 1;
        }
        else
        {
            bool fg = 0;
            REP1(i,n)if(u[i] && d[i])
            {
                d[i]--;
                d[t.Y]--;
                u[t.Y] = 1;
                e.pb(ii(i, t.Y));
                fg = 1;
                break;
            }
            if(!fg)
            {
                cout<<"NO"<<endl;
                exit(0);
            }
        }
    }
    cout<<"YES "<<ans<<endl;
    cout<<SZ(e)<<endl;
    for(ii p:e)cout<<p.X<<" "<<p.Y<<endl;
}