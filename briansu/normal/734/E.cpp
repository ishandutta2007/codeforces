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
#define endl '\n'
#endif // brian
//}

const ll MAXn=2e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);


ll n;
vector<ll> v[MAXn];
bool d[MAXn];
set<ii,greater<ll> > st;

ll mn=0;
ll dfs(ll now,ll f,bool l)
{
    ii tmp=ii(0,0);
    for(ll k:v[now])
    {
        if(k==f)continue;
        ll t=dfs(k,now,d[now]);
        if(t>tmp.X)swap(t,tmp.X);
        if(t>tmp.Y)tmp.Y=t;
    }
    mn=max(mn,(tmp.X+tmp.Y+1)/2);
    return (tmp.X+(d[now]!=l));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)cin>>d[i];
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0,-1,d[0]);
    cout<<mn<<endl;
}