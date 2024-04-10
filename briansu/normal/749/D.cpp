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
#else
#define debug(...)
#define endl '\n'
#endif // brian
//}


const ll MAXn=2e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e10);

set<ii> st;
ll n;
ll mx[MAXn];
vector<ll> d[MAXn];
vector<ll> qr;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    st.erase(ii(1,2));
    cin>>n;
    REP(i,n)
    {
        ll a,k;
        cin>>a>>k;
        mx[a]=k;
        d[a].pb(k);
    }
    REP(i,n)if(mx[i+1])st.insert(ii(mx[i+1],i+1));
    ll q;
    cin>>q;
    debug(st);
    REP(i,q)
    {
        ll k;
        cin>>k;
        qr.resize(k);
        REP(j,k)cin>>qr[j];
        REP(j,k)st.erase(ii(mx[qr[j]],qr[j]));
        debug(st);
        if(SZ(st)==0)cout<<"0 0"<<endl;
        else if(SZ(st)==1)cout<<(*st.begin()).Y<<" "<<d[(*st.begin()).Y][0]<<endl;
        else
        {
            auto it=st.end();
            it--;
            ll a=(*it).Y;
            it--;
            ll b=(*it).X;
            cout<<a<<" "<<*upper_bound(ALL(d[a]),b)<<endl;
        }
        REP(j,k)if(mx[qr[j]])st.insert(ii(mx[qr[j]],qr[j]));
    }
}