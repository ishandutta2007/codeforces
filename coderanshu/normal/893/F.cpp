#include<iostream>
#include<vector>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll int 
#define pb push_back

const int N=100005,NN=20000000;
vector<int> v[N];
ll a[N],n,r,sub[N],dep[N];

void pre(int s,int p)
{
    sub[s]=1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1;
            pre(j,s);
            sub[s]+=sub[j];
        }
    }
}

struct node{
    ll val,L,R;
    node (): L(-1),R(-1),val(2e9){};
    node(ll x) : L(-1),R(-1),val(x){};
};
struct PERTREE{
    node tree[NN];
    int cursz=0;
    ll buildTree(ll st,ll en)
    {
        ll v = cursz++;
        tree[v]=node();
        if(st==en)
            return v;
        ll mid=(st+en)>>1;
        tree[v].L=buildTree(st,mid);
        tree[v].R=buildTree(mid+1,en); 
        return v;
    }
    ll update(ll v,ll st,ll en,ll pos,ll val)
    {
        ll u=cursz++;
        tree[u]=node(min(val,tree[v].val));
        // current value + value jo merko add karni hai is my answer //
        // and is node ko update karna hai islie hi ispe call hua hai function
        if(st==en)
            return u;
        // agar leaf hai to seedha return kar do wrna left ya right jisko update karna ho kar do
        // just re adjusting the pointers and combining the updates....
        ll mid=(st+en)>>1;
        if(pos<=mid)
            tree[u].L=update(tree[v].L,st,mid,pos,val);
        else 
            tree[u].R=update(tree[v].R,mid+1,en,pos,val);
        tree[u].L=(tree[u].L==-1)?tree[v].L:tree[u].L;
        tree[u].R=(tree[u].R==-1)?tree[v].R:tree[u].R;
        return u;
    }
    ll query(ll v,ll st,ll en,ll l,ll r)
    {
        if(st>r || en<l)
            return 2e9;
        if(st>=l & en<=r)
            return tree[v].val;
        int mid=(st+en)>>1;
        return min(query(tree[v].L,st,mid,l,r),query(tree[v].R,mid+1,en,l,r));
    }
}seg;
int depmin[N],roots[N];

void add(int s,int p,int &curv)
{
    if(depmin[dep[s]]>a[s])
        curv=seg.update(curv,1,n,dep[s],a[s]),depmin[dep[s]]=a[s];
    for(auto j:v[s])
        if(j!=p)
            add(j,s,curv);
}

void clear(int s,int p)
{
    depmin[dep[s]]=2e9;
    for(auto j:v[s])
        if(j!=p)
            clear(j,s);
}
void dfs(int s,int p,bool bors)
{
    int mx=-1,bc=-1;
    for(auto j:v[s])
        if(j!=p)
            if(sub[j]>mx)
                mx=sub[j],bc=j;
    for(auto j:v[s])
        if(j!=p && j!=bc)
            dfs(j,s,0);
    int curv=roots[0];
    if(bc!=-1)
    {
        dfs(bc,s,1);
        curv=roots[bc];
    }
    if(depmin[dep[s]]>a[s])
    {
        curv=seg.update(curv,1,n,dep[s],a[s]),depmin[dep[s]]=a[s];
    }
    for(auto j:v[s])
        if(j!=p && j!=bc)
            add(j,s,curv);
    roots[s]=curv;
    if(!bors)
    {
        clear(s,p);
    }
}
int _runtimeTerror_()
{
    cin>>n>>r;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    dep[r]=1;
    for(int i=1;i<=n;++i)
        depmin[i]=2e9;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].emplace_back(y),v[y].emplace_back(x);
    }
    roots[0]=seg.buildTree(1,n);
    pre(r,-1);
    dfs(r,-1,1);
    int m;
    cin>>m;
    int last=0;
    while(m--)
    {
        int p,q;
        cin>>p>>q;
        p=(p+last)%n+1;
        q=(q+last)%n;
        last=seg.query(roots[p],1,n,dep[p],dep[p]+q);
        cout<<last<<'\n';
    }
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