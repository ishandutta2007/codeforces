#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=100000+7;
const int K=19;
int n, q, euler[2*N], topeuler, firstap[N], lastap[N], dep[N], lg[2*N], l[N], r[N], top2, nodes[N], par[K][N], kekos[N];
pair<int, int> tab[K][2*N];
ll init[N];
vector<int> g[N];


ll sum[4*N], lazy[4*N];

void push(int v, int tl, int tr)
{
        if (!lazy[v])
                return;
        sum[v]+=(ll) (tr-tl+1)*lazy[v];
        if (tl<tr)
        {
                lazy[2*v]+=lazy[v];
                lazy[2*v+1]+=lazy[v];
        }
        lazy[v]=0;
}

void add(int v, int tl, int tr, int l, int r, int x)
{
        push(v, tl, tr);
        if (tr<l ||r<tl)
                return;
        if (l<=tl && tr<=r)
        {
                lazy[v]+=x;
                push(v, tl, tr);
        }
        else
        {
                int tm=(tl+tr)/2;
                add(2*v, tl, tm, l, r, x);
                add(2*v+1, tm+1, tr, l, r, x);
                sum[v]=sum[2*v]+sum[2*v+1];
        }

}

ll get(int v, int tl, int tr, int l, int r)
{
        push(v, tl, tr);
        if (tr<l || r<tl)
                return 0;
        if (l<=tl && tr<=r)
                return sum[v];
        int tm=(tl+tr)/2;
        return get(2*v, tl, tm, l, r)+get(2*v+1, tm+1, tr, l, r);
}



void addintv(int l, int r, int x)
{
        add(1, 1, n, l, r, x);
}

ll getintv(int l, int r)
{
        return get(1, 1, n, l, r);
}


void build(int a, int p=0)
{
        par[0][a]=p;
        for (int k=1; k<K; k++)
                par[k][a]=par[k-1][par[k-1][a]];

        nodes[++top2]=a;
        addintv(top2, top2, kekos[a]);

        l[a]=top2;
        euler[++topeuler]=a;
        tab[0][topeuler]={dep[a], a};
        firstap[a]=lastap[a]=topeuler;

        for (auto &b:g[a])
        {
                if (b==p)
                        continue;
                dep[b]=1+dep[a];
                build(b, a);
                euler[++topeuler]=a;
                lastap[a]=topeuler;
                tab[0][topeuler]={dep[a], a};
        }

        r[a]=top2;
}

int lca(int a, int b)
{
        if (firstap[a]>lastap[b])
                swap(a, b);
        assert(firstap[a]<=lastap[b]);
        a=firstap[a];
        b=lastap[b];
        int k=lg[b-a+1];
        return min(tab[k][a], tab[k][b-(1<<k)+1]).second;
}

int root=1;

int distroot(int a)
{
        return dep[a]+dep[root]-2*dep[lca(a, root)];
}

int lcaroot(int a, int b)
{
        int c=lca(a, b);
        if (l[c]<=l[root] && r[root]<=r[c]) /// daca root se gaseste sub c
        {
                int x=lca(root, a), y=lca(root, b);
                if (distroot(x)<distroot(y))
                        return x;
                else
                        return y;
        }
        else
        {
                return c;
        }
}

void add(int a, int x)
{
        if (lca(a, root)!=a)
        {
                addintv(l[a], r[a], x);
        }
        else
        {
                addintv(1, n, x);
                if (a==root)
                        return;
                int goup=dep[root]-dep[a]-1, vert=root;
                assert(goup>=0);
                for (int bit=0; (1<<bit)<=goup; bit++)
                        if (goup&(1<<bit))
                                vert=par[bit][vert];
                addintv(l[vert], r[vert], -x);
        }
}

ll under(int a)
{
        if (lca(a, root)!=a)
        {
                return getintv(l[a], r[a]);
        }
        else
        {
                ll sol=getintv(1, n);
                if (a==root)
                        return sol;
                int goup=dep[root]-dep[a]-1, vert=root;
                assert(goup>=0);
                for (int bit=0; (1<<bit)<=goup; bit++)
                        if (goup&(1<<bit))
                                vert=par[bit][vert];
                sol-=getintv(l[vert], r[vert]);
                return sol;
        }
}


signed main()
{
        ///freopen ("input", "r", stdin);
        ios::sync_with_stdio(0); cin.tie(0); /// NOT just for aesthetics this time

        for (int i=2; i<2*N; i++)
                lg[i]=1+lg[i/2];

        cin>>n>>q;
        for (int i=1; i<=n; i++)
                cin>>kekos[i];
        for (int i=1; i<n; i++)
        {
                int x, y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        build(1);
        for (int k=1; (1<<k)<=topeuler; k++)
                for (int i=1; i+(1<<k)-1<=topeuler; i++)
                        tab[k][i]=min(tab[k-1][i], tab[k-1][i+(1<<(k-1))]);
        while (q--)
        {
                int type;
                cin>>type;
                if (type==1)
                {
                        cin>>root;
                        continue;
                }
                if (type==2)
                {
                        int a, b, x;
                        cin>>a>>b>>x;
                        int c=lcaroot(a, b);
                        add(c, x);
                }
                if (type==3)
                {
                        int a;
                        cin>>a;
                        cout<<under(a)<<"\n";
                }
        }

        return 0;
}


/**

**/