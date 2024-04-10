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

vector<ll> v[MAXn];
vector<ll> tre;
ll n;
ll d[MAXn],dg[MAXn];
ll ans=0;
ll t=1;
ll vis[MAXn];
void dfs(ll now,ll f)
{
    vis[now]=1;
    for(ll k:v[now])
    {
        if(k==f)continue;
        else dfs(k,now);
    }
}
void dfs2(ll now)
{
    vis[now]=t;
    if(vis[d[now]])
    {
        if(vis[d[now]]==t)
        {
            if(SZ(tre))d[now]=tre[0];
            else tre.pb(d[now]=now);
            ans++;
        }
    }
    else dfs2(d[now]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        v[d[i]].pb(i);
    }
    for(int i=1;i<=n;i++)if(d[i]==i){tre.pb(i);dfs(i,-1);}
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            t++;
            dfs2(i);
        }
    }
    debug(tre);
    for(int i=1;i<SZ(tre);i++)
    {
        d[tre[i]]=tre[0];
        ans++;
    }
    cout<<ans<<endl;
    REP(i,n)cout<<(i==0?"":" ")<<d[i+1];
    cout<<endl;

}