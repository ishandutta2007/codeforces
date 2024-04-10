#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

struct node{
    int id,pos,l;
    bool imp;
    node *edge[26];
    node() : imp(0),id(0),l(0) { for(int i=0;i<26;i++) edge[i]=0; }
}*root;

#define MAXN 1000005

node *arr[MAXN];
ll p[MAXN],cont,ls[MAXN][2],res[MAXN],n;


template <typename T>
struct st_lazy{
    vector< T > st,lazy;
    ll sz;
    T neutroQ,neutroL;

    st_lazy (ll n,T neutroq,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroQ(neutroq),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return min(v1,v2);
    }

    void up(int p,T v)
    {
        st[p]=min(v,st[p]);
        lazy[p]=min(v,lazy[p]);
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            lazy[p]=neutroL;
            return ;
        }
        if(lazy[p]==neutroL)
            return ;
        st[p<<1]=min(st[p<<1],lazy[p]);
        st[(p<<1)+1]=min(st[(p<<1)+1],lazy[p]);
        lazy[p<<1]=min(lazy[p<<1],lazy[p]);
        lazy[(p<<1)+1]=min(lazy[(p<<1)+1],lazy[p]);
        lazy[p]=neutroL;
    }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void update(int p,int l,int r,int L,int R,T v)
    {
        push(p,l,r);

        if(L<=l && r<=R)
        {
            up(p,v);
            return ;
        }
        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int p,int l,int r,int L,int R)
    {
        push(p,l,r);

        if(L<=l && r<=R)
            return st[p];
        else if(L>r || l>R)
            return neutroQ;

        int mid=(l+r)>>1;

        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

st_lazy<int> ST(MAXN,0,0);

void dfs(node *u)
{
    if(u->imp)
        cont++;
    u->pos=cont;
    ls[u->id][0]=cont;

    for(int i=0;i<26;i++)
        if(u->edge[i])
            dfs(u->edge[i]);
    ls[u->id][1]=cont;
}

void dfs1(node *u)
{
    if(u->imp)
        res[u->id]=min(res[u->id],(ll)ST.query(1,0,MAXN-1,u->pos,u->pos)+u->pos);
    ST.update(1,0,MAXN-1,ls[u->id][0],ls[u->id][1],res[u->id]-(u->pos)+(u->imp));

    for(int i=0;i<26;i++)
        if(u->edge[i])
        {
            res[u->edge[i]->id]=min(res[u->id]+1,res[u->edge[i]->id]);
            dfs1(u->edge[i]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    root=new node();
    arr[0]=root;

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin >> p[i] >> c;
        int v=c-'a';
        if(!arr[p[i]]->edge[v])
        {
            arr[p[i]]->edge[v]=new node();
            arr[p[i]]->edge[v]->id=i+1;
            arr[i+1]=arr[p[i]]->edge[v];
        }
    }

    int k,x;
    cin >> k;
    vector<int> xs;
    for(int i=0;i<k;i++)
    {
        cin >> x;
        xs.push_back(x);
        arr[x]->imp=1;
    }

    dfs(root);

    for(int i=0;i<=n+1;i++)
        res[i]=1e9;
    res[0]=0;
    dfs1(root);

    for(auto y : xs)
        cout << res[y] << ' ';
    cout << '\n';

    return 0;
}