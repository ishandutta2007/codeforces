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
#define pary(...)
#define endl '\n'
#endif // brian
//}

const ll MAXn=2e5+5,MAXlg=__lg(10*MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(2e18);

vector<ii> v[MAXn];
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
cc_hash_table<string,ll> mp;
bool vis[MAXn];
ll n;
ll dgo[MAXn],dgi[MAXn];
vector<ll> ans;
ll r[MAXn];
void dfs(ll now,ll f)
{
    vis[f]=1;
    for(;r[now]<SZ(v[now]);)if(!vis[v[now][r[now]++].Y])dfs(v[now][r[now]-1].X,v[now][r[now]-1].Y);
    ans.pb(f);
}
ll it=0;
string d[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)
    {
        string s;
        cin>>s;
        string a=s.substr(0,2);
        string b=s.substr(1,2);
        d[i]=s;
        if(mp.find(a)==mp.end())mp[a]=it++;
        if(mp.find(b)==mp.end())mp[b]=it++;
        ll x=mp[a];
        ll y=mp[b];
        v[x].pb(ii(y,i));
        dgo[x]++;
        dgi[y]++;
    }
    ll a=-1,b=-1;
    REP(i,it)
    {
        if(dgo[i]!=dgi[i])
        {
            if(dgo[i]==dgi[i]+1&&a==-1)a=i;
            else if(dgo[i]==dgi[i]-1&&b==-1)b=i;
            else{cout<<"NO"<<endl;return 0;}
        }
    }
    if(a==-1)a=0;
    dfs(a,n);
    if(SZ(ans)!=n+1){cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
    reverse(ALL(ans));
    cout<<d[ans[1]];
    for(int i=2;i<=n;i++)cout<<d[ans[i]][2];
    cout<<endl;
}