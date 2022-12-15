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

const ll MAXn=1e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll n,m,q;
vector<ll> v[MAXn],d[MAXn],ls,ans,tmpans;
ll sz[MAXn],mx[MAXn],cl[MAXn],cr[MAXn],p[MAXn],dp[MAXn];

struct node
{
    ll l,r;
    node *lc,*rc;
    vector<ll> mn;
    node(ll li,ll ri,node *lci,node *rci):l(li),r(ri),lc(lci),rc(rci)
    {
        if(l==r-1)
        {
            mn.resize(10);
            REP(i,10)
            {
                if(i<SZ(d[ls[l]]))mn[i]=d[ls[l]][i];
                else mn[i]=INF;
            }
        }
        else
        {
            mn.resize(20);
            merge(ALL(lc->mn),ALL(rc->mn),mn.begin());
            mn.resize(10);
        }
    }
    void qr(ll li,ll ri)
    {
        //debug(l,r,mn);
        if(li>=r||ri<=l)return;
        if(li<=l&&ri>=r)
        {
            tmpans.resize(0);
            tmpans.resize(20);
            merge(ALL(ans),ALL(mn),tmpans.begin());
            tmpans.resize(10);
            ans.swap(tmpans);
        }
        else
        {
            lc->qr(li,ri);
            rc->qr(li,ri);
        }
    }
};
node *build(ll l,ll r)
{
    if(l==r-1)return new node(l,r,0,0);
    else return new node(l,r,build(l,(r+l)/2),build((l+r)/2,r));
}
void szdfs(ll now,ll f)
{
    sz[now]=1;
    mx[now]=-1;
    p[now]=f;
    for(ll k:v[now])
    {
        if(k==f)continue;
        dp[k]=dp[now]+1;
        szdfs(k,now);
        sz[now]+=sz[k];
        if(mx[now]==-1||sz[k]>sz[mx[now]])mx[now]=k;
    }
}
ll t=-1;
void dfs(ll now,ll f)
{
    ls.pb(now);
    cr[now]=++t;
    if(mx[now]!=-1)
    {
        cl[mx[now]]=cl[now];
        dfs(mx[now],now);
    }
    for(ll k:v[now])
    {
        if(k==f||k==mx[now])continue;
        cl[k]=t+1;
        dfs(k,now);
    }
}
ll lca(ll a,ll b)
{
    //debug(a+1,b+1);
    if(cl[a]==cl[b])return (dp[a]<dp[b]?a:b);
    else return (dp[ls[cl[a]]]>dp[ls[cl[b]]]?lca(p[ls[cl[a]]],b):lca(a,p[ls[cl[b]]]));
}
node *rt=0;

void path(ll a,ll b,bool c)
{
    if(cl[a]==cl[b])
    {
        rt->qr(cr[b]+c,cr[a]+1);
    }
    else
    {
        rt->qr(cl[a],cr[a]+1);
        path(p[ls[cl[a]]],b,c);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i,m)
    {
        ll a;
        cin>>a;
        a--;
        d[a].pb(i+1);
    }
    REP(i,n)sort(ALL(d[i]));
    dp[0]=1;
    szdfs(0,-1);
    cl[0]=0;
    dfs(0,-1);
    rt=build(0,n);
    //REP(i,n)debug(i,ls[i]);
    REP(i,q)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        ll k=lca(a,b);
        ans.resize(10);
        REP(j,10)ans[j]=INF;
        path(a,k,0);
        path(b,k,1);
        ll tmp=0;
        REP(j,10)tmp+=(ans[j]!=INF);
        tmp=min(tmp,c);
        cout<<tmp;
        REP(j,tmp)cout<<" "<<ans[j];
        cout<<endl;
    }
}