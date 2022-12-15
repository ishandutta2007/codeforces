//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
template<typename _a,typename _b> ostream &operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
#else
#define debug(...)
//#define endl '\n'
#endif // brian
//}

const ll MAXn=2e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000;//1000000007;
const ll INF=ll(1e15);

ll d[2*MAXn];
ll p=1;
void ch(ll x,ll k)
{
    d[p+x]=k;
    ll t=(p+x)/2;
    bool b=0;
    while(t!=0)
    {
        if(b==0)d[t]=d[2*t]|d[2*t+1];
        else d[t]=d[2*t]^d[2*t+1];
        t/=2;
        b=!b;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,q;
    cin>>n>>q;
    REP(i,n)p*=2;
    n=p;
    p=p-1;
    debug(p);
    REP(i,n)
    {
        ll k;
        cin>>k;
        ch(i+1,k);
    }
    REP(i,2*n)debug(i+1,d[i+1]);
    REP(i,q)
    {
        ll x,k;
        cin>>x>>k;
        ch(x,k);
        cout<<d[1]<<endl;
    }
}