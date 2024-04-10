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
template<typename _a,typename _b> ostream& operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
template<typename _t>
struct ary
{
    _t _a,_b;
    ary(_t _ai,_t _bi):_a(_ai),_b(_bi){}
};
template<typename T> void pary(T _a,T _b){_OUTC(cerr,_a,_b);}
#else
#define debug(...)
//#define endl '\n'
#endif // brian
//}

const ll MAXn=129,MAXlg=8;
const ll MOD=1000000007;
const ll INF=ll(1e15);


string s;
bool b[26];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin>>n;
    cin>>s;
    if(n>26){cout<<-1<<endl;return 0;}
    ll ans=0;
    REP(i,n)
    {
        if(b[s[i]-'a'])ans++;
        else b[s[i]-'a']=1;
    }
    cout<<ans<<endl;

}