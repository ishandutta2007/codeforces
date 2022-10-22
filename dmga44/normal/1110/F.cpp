#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 500005
#define oo ((ll)(1e18))

vector<pii> g[MAXN];
vector<pip>qs[MAXN];
ll p[MAXN],mk[MAXN],cont,inter[MAXN][2],d[MAXN];
ll dist,leaf[MAXN],areq[MAXN],ans[MAXN],n;
ll st[4*MAXN],lazy[4*MAXN];

void dfs(ll u)
{
    mk[u]=1;
    inter[u][0]=cont;
    cont++;
    if(leaf[u])
        d[u]=dist;
    else
        d[u]=oo;
    areq[u]+=qs[u].size();
    for(auto y : g[u])
    {
        ll v=y.first;
        ll w=y.second;
        if(!mk[v])
        {
            dist+=w;
            dfs(v);
            dist-=w;
            areq[u]+=areq[v];
        }
    }
    inter[u][1]=cont-1;
}

void build(ll p,ll l,ll r)
{
    if(l==r)
    {
        st[p]=d[l];
        return;
    }
    ll mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);

    st[p]=min(st[p<<1],st[(p<<1)+1]);
}

void push(ll p,ll l,ll r)
{
    if(!lazy[p])
        return ;
    ll x=lazy[p];
    lazy[p]=0;
    st[p]+=x;
    if(l!=r)
    {
        lazy[p<<1]+=x;
        lazy[(p<<1)+1]+=x;
    }
}

void update(ll p,ll l,ll r,ll L,ll R,ll v)
{
    push(p,l,r);
    if(L<=l && r<=R)
    {
        lazy[p]=v;
        push(p,l,r);
        return ;
    }
    if(l>R || L>r)
        return ;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R,v);
    update((p<<1)+1,mid+1,r,L,R,v);

    st[p]=min(st[p<<1],st[(p<<1)+1]);
}

ll query(int p,int l,int r,int L,int R)
{
    push(p,l,r);
    if(L<=l && r<=R)
        return st[p];
    if(L>r || l>R)
        return oo;
    int mid=(l+r)>>1;

    return min(query(p<<1,l,mid,L,R)
              ,query((p<<1)+1,mid+1,r,L,R));
}

void dfs1(ll u)
{
    mk[u]=1;
    for(auto y : qs[u])
        ans[y.first]=query(1,0,n-1,y.second.first,y.second.second);
    for(auto y : g[u])
    {
        ll v=y.first;
        ll w=y.second;
        if(!mk[v] && areq[v])
        {
            update(1,0,n-1,0,n-1,w);
            update(1,0,n-1,inter[v][0],inter[v][1],-(2*w));
            dfs1(v);
            update(1,0,n-1,0,n-1,-w);
            update(1,0,n-1,inter[v][0],inter[v][1],(2*w));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    ll q,w,qq;
    cin >> n >> q;
    for(ll i=1;i<n;i++)
    {
        cin >> p[i] >> w;
        p[i]--;
        leaf[p[i]]=1;
        g[i].push_back(pii(p[i],w));
        g[p[i]].push_back(pii(i,w));
    }
    for(ll i=0;i<n;i++)
        leaf[i]=1-leaf[i];

    qq=q;
    while(q--)
    {
        ll v,l,r;
        cin >> v >> l >> r;
        v--,l--,r--;
        qs[v].push_back(pip(q,pii(l,r)));
    }
    dfs(0);

    build(1,0,n-1);
    for(ll i=0;i<n;i++)
        mk[i]=0;

    dfs1(0);

    for(ll i=qq-1;i>=0;i--)
        db(ans[i])

    return 0;
}