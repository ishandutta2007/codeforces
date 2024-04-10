#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<array<int,2>> tree(4*N,{0,0});
vector<int> lazy(4*N,0);
vector<int> h(N,0);
vector<int> depth(N,0);

void pull(int idx){tree[idx]=max(tree[2*idx],tree[2*idx+1]);}
void apply(int idx,int x){tree[idx][0]+=x;lazy[idx]+=x;}
void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
    lazy[idx]=0;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]={depth[h[l]],h[l]};
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        pull(idx);
    }
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,x);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        pull(idx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v[n+1];
    vector<int> p(n+1,0);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int leaves=0;
    vector<int> tin(n+1,0);
    vector<int> tout(n+1,0);
    int tcnt=0;
    vector<bool> is_leaf(n+1,0);
    function<void(int)> dfs=[&](int a)
    {
        depth[a]=depth[p[a]]+1;
        tin[a]=(++tcnt);
        h[tcnt]=a;
        if(a!=1&&v[a].size()==1)
        {
            leaves++;
            is_leaf[a]=1;
        }
        for(int to:v[a])
        {
            if(to==p[a]) continue;
            p[to]=a;
            dfs(to);
        }
        tout[a]=tcnt;
    };
    dfs(1);
    build(1,1,n);
    auto rm=[&](int a)
    {
        update(1,1,n,tin[a],tin[a],-(1<<30));
    };
    for(int i=1;i<=n;i++) if(!is_leaf[i]) rm(i);
    vector<bool> vis(n+1,0);
    vis[0]=1;
    ll res=-(1ll<<60);
    int blocked=0;
    for(int r=1;r<=k;r++)
    {
        if(r<=leaves)
        {
            int a=tree[1][1];
            rm(a);
            while(!vis[a])
            {
                update(1,1,n,tin[a],tout[a],-1);
                vis[a]=1;
                blocked++;
                a=p[a];
            }
            ll u=(n-blocked);
            ll x=n-r;
            ll y=r;
            if(x>y) swap(x,y);
            //minimize (x-t)*(y-t) s.t. 0<=t<=u
            ll opt=(x-u)*(y-u);
            ll s=y-x;
            if(x+s/2<=u) opt=min(opt,(-s/2)*(s-s/2));
            res=max(res,opt);
        }
        else res=max(res,ll(n-r)*r);
    }
    cout << res << "\n";
    return 0;
}