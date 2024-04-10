#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
ll rng(ll l,ll r) {return uniform_int_distribution<ll>(l,r)(gen);}

const int N=300005;
int val[N];
ll x[N];

struct Node
{
    ll h;
    Node *l,*r;
    Node(ll a):h(a){l=r=nullptr;}
    Node(Node *a,Node *b):l(a),r(b){h=(l->h^r->h);}
};

Node* build(int l,int r)
{
    if(l==r) return new Node(0);
    int m=(l+r)/2;
    return new Node(build(l,m),build(m+1,r));
}

Node* update(Node *now,int l,int r,int pos)
{
    if(l==r) return new Node(now->h^x[l]);
    int m=(l+r)/2;
    if(pos<=m) return new Node(update(now->l,l,m,pos),now->r);
    else return new Node(now->l,update(now->r,m+1,r,pos));
}

int query(Node *a,Node *b,int l,int r,int ql,int qr,int lc)
{
    if(ql>qr) return -1;
    if((a->h^b->h^(l<=val[lc]&&val[lc]<=r?x[val[lc]]:0))==0) return -1;
    if(l==r) return l;
    int m=(l+r)/2;
    int res=query(a->l,b->l,l,m,ql,min(qr,m),lc);
    if(res!=-1) return res;
    return query(a->r,b->r,m+1,r,max(ql,m+1),qr,lc);
}

int n;
vector<int> v[N];
vector<Node*> st(N);
int depth[N];
int p[N][19];

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<19;i++) p[a][i]=p[p[a][i-1]][i-1];
    st[a]=update(st[p[a][0]],1,n,val[a]);
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=18;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=18;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) x[i]=rng(1,(1ll<<62));
    st[0]=build(1,n);
    dfs(1);
    while(q--)
    {
        int a,b,l,r;
        cin >> a >> b >> l >> r;
        cout << query(st[a],st[b],1,n,l,r,lca(a,b)) << "\n";
    }
    return 0;
}