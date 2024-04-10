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


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e18);

vector<ll> v[MAXn];
ll st[MAXn][MAXlg];
ll n;
ll dp[MAXn],p[MAXn],sz[MAXn];
void dfs(ll now,ll f)
{
    sz[now]=1;
    p[now]=f;
    for(ll k:v[now])
    {
        if(k==f)continue;
        dp[k]=dp[now]+1;
        dfs(k,now);
        sz[now]+=sz[k];
    }
}
ll lca(ll a,ll b)
{
    if(dp[a]<dp[b])swap(a,b);
    for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=-1&&dp[st[a][i]]>=dp[b])a=st[a][i];
    //debug(a,b);
    if(a==b)return a;
    for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=st[b][i])a=st[a][i],b=st[b][i];
    return p[a];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dp[0]=1;
    dfs(0,-1);
    FILL(st,-1);
    REP(i,n)st[i][0]=p[i];
    for(int i=1;i<MAXlg;i++)REP(j,n)if(st[j][i-1]!=-1)st[j][i]=st[st[j][i-1]][i-1];
    ll q;
    ll a,b;
    cin>>q;
    while(q--&&cin>>a>>b)
    {
        a--;b--;
        if(a==b)cout<<n<<endl;
        else
        {
            ll l=lca(a,b);
            if(dp[a]==dp[b])
            {
                for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=-1&&dp[st[a][i]]>dp[l])a=st[a][i];
                for(int i=MAXlg-1;i>=0;i--)if(st[b][i]!=-1&&dp[st[b][i]]>dp[l])b=st[b][i];
                cout<<n-sz[a]-sz[b]<<endl;
            }
            else
            {
                debug(l+1);
                ll dis=dp[a]+dp[b]-2*dp[l];
                if(dis%2==1)cout<<0<<endl;
                else
                {
                    if(dp[a]<dp[b])swap(a,b);
                    dis=dp[a]-dis/2;
                    for(int i=MAXlg-1;i>=0;i--)if(st[a][i]!=-1&&dp[st[a][i]]>dis)a=st[a][i];
                    cout<<sz[p[a]]-sz[a]<<endl;
                }
            }
        }
    }
}