#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
const int N=200005;
struct node
{
    int sum;
    int cnt;
}fake;
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=a.sum+b.sum;
        ret.cnt=a.cnt+b.cnt;
        return ret;
    }
    inline node make_node(int x=0,int y=0)
    {
        node ret;
        ret.sum=x;
        ret.cnt=y;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node();
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val,1);
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    int query(ll v,ll st,ll en,ll val)
    {
        if(val==0)
            return 0;
        if(st==en)
            return tree[v].sum;
        int mid=(st+en)>>1;
        if(tree[v<<1].cnt>=val)
            return query(v<<1,st,mid,val);
        else
            return tree[v<<1].sum+query(v<<1 | 1,mid+1,en,val-tree[v<<1].cnt);
    }
}seg;

vector<pair<int,int>> same,one,two,none;
vector<pair<int,int>> id;
int n,m,k;

int findI(pair<int,int> &val)
{
    auto it=lower_bound(all(id),val)-id.begin();
    return it;
}
int _runtimeTerror_()
{
    cin>>n>>m>>k;
    int ans=2e9+100;
    for(int i=1;i<=n;++i)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(a==1 && b==1)
            same.pb({t,i});
        else if(a==1)
            one.pb({t,i});
        else if(b==1)
            two.pb({t,i});
        else 
            none.pb({t,i});
        id.pb({t,i});
    }        
    sort(all(id));sort(all(none));sort(all(same));sort(all(one));sort(all(two));
    int x=min({sz(one),sz(two),k});
    seg.buildTree(1,0,n-1);
    int sum1=0,sum2=0;
    for(int i=0;i<x;++i)
        sum1+=one[i].F,sum2+=two[i].F;
    for(auto k:none)
    {
        int it=findI(k);
        seg.update(1,0,n-1,it,k.F);
    }
    int idx=-1;
    for(int i=x;i<sz(one);++i)
    {
        auto it=findI(one[i]);
        seg.update(1,0,n-1,it,one[i].F);
    }
    for(int i=x;i<sz(two);++i)
    {
        auto it=findI(two[i]);
        seg.update(1,0,n-1,it,two[i].F);
    }
    int cur=x-1;
    int $=min(sz(same),m);
    int sum=0,kitne=0;
    for(int i=0;i<=$;++i)
    {
        if(cur+1+i>=k)
        {
            while(cur>=0 && cur+i+1>k)
            {
                auto it=findI(two[cur]);
                seg.update(1,0,n-1,it,two[cur].F);
                it=findI(one[cur]);
                seg.update(1,0,n-1,it,one[cur].F);
                sum1-=one[cur].F;
                sum2-=two[cur].F;
                --cur;
            }
            if(i+2*(cur+1)<=m && i+2*(cur+1)+seg.tree[1].cnt>=m)
            {
                int val=sum+sum1+sum2+seg.query(1,0,n-1,m-i-2*(cur+1));
                if(val<ans)
                    ans=val,idx=i,kitne=cur+1;
            }
        }
        if(i!=$)
            sum+=same[i].F;
    }
    if(ans==2e9+100)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<ans<<'\n';
    vector<int> print;
    for(int i=0;i<idx;++i)
        print.pb(same[i].S);
    for(int i=0;i<kitne;++i)
        print.pb(one[i].S),print.pb(two[i].S);
    for(auto k:print)
        cout<<k<<" ";
    int fuck=m-sz(print);
    for(int i=kitne;i<sz(one);++i)
        none.pb(one[i]);
    for(int i=kitne;i<sz(two);++i)
        none.pb(two[i]);
    sort(all(none));
    for(int i=0;i<fuck;++i)
        cout<<none[i].S<<' ';
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}